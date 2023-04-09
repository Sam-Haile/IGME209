// HW3 - Graphical Snake
// Sam Haile
// DSA1.06
/* Unique Feature : 
Not sure if this counts but I  made my game 
resemble Kirby's dream land from the game boy
*/

#include <iostream>
#include <GravitySnake.h>
#include <iomanip>
#include <sstream>
#define SFML_STATIC
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Functions.h"
using namespace std;

/// <summary>
/// Converts pixel based coordinates (SFML) 
/// to metric based coordinates (Box2D)
/// </summary>
/// <param name="vec"></param>
/// <returns>A vector 2 in Box2Ds coordinate system</returns>
b2Vec2 SFMLToBox2D(const sf::Vector2f& vec)
{
	return b2Vec2(vec.x / 100.0f, -vec.y / 100.0f);
}

/// <summary>
/// Converts metric based coordinates (Box2D) 
/// to pixel based coordinates (SFML)
/// </summary>
/// <param name="vec"></param>
/// <returns>A vector 2 in SFMLs coordinate system</returns>
sf::Vector2f Box2DToSFML(const b2Vec2& vec)
{
	// Convert SFML vector to Box2D position with the proper scale
	return sf::Vector2f(vec.x * 100.0f, vec.y * -100.0f);
}

/// <summary>
/// Gets the center point of a textbox
/// </summary>
/// <param name="text"></param>
void GetTextCenter(sf::Text& text)
{
	sf::FloatRect bounds = text.getLocalBounds(); // get the local bounds of the text
	text.setOrigin(bounds.left + bounds.width / 2.0f, bounds.top + bounds.height / 2.0f);
}

int main()
{
	// Improves formatting of console output.
	cout << fixed << showpoint << setprecision(2);

	setTargetBounds(1.0f, 7.0f, -6.6f, -1.0f);
	//Create the physics world, and all the objects. Return a pointer to the snake body.
	//These functions are from the DLL.
	initVariables(b2Vec2(0.0f, -9.8f));

	// Creating the walls/floor
	b2Vec2 box2DLWall = b2Vec2(0.2f, 0.0f);
	createLeftWall(b2Vec2(box2DLWall), 0.0f, 8.0f);
	b2Vec2 box2DRWall = b2Vec2(7.8f, 0.0f);
	createRightWall(b2Vec2(box2DRWall), 0.0f, 8.0f);
	b2Vec2 box2DFloorPos = b2Vec2(0.0f, -7.4f);
	createFloor(b2Vec2(box2DFloorPos), 10.0f, 0.0f);
	b2Vec2 box2DCeiling = b2Vec2(0.0f, -0.0f);
	createCeiling(b2Vec2(box2DCeiling), 10.0f, 0.0f);

#pragma region Title Screen

	sf::RectangleShape whiteBox(sf::Vector2f(800, 800));
	whiteBox.setFillColor(sf::Color(248, 248, 248));
	sf::Texture t_logo;
	if (!t_logo.loadFromFile("assets/Title_Screen.png"))
		sf::err() << "Error: The file is not found!" << std::endl;
	sf::Sprite s_logo(t_logo);
	s_logo.setOrigin(t_logo.getSize().x / 2, t_logo.getSize().y / 2 + 40);
	s_logo.scale(4, 4);
	s_logo.setPosition(400, 400);

	sf::Texture t_credits;
	if (!t_credits.loadFromFile("assets/credits.png"))
		sf::err() << "Error: The file is not found!" << std::endl;
	sf::Sprite s_credits(t_credits);
	s_credits.setOrigin(t_credits.getSize().x / 2, t_credits.getSize().y / 2);
	s_credits.scale(4, 4);
	s_credits.setPosition(400, 700);


	sf::Texture t_gameOver;
	if (!t_gameOver.loadFromFile("assets/GameOver.png"))
		sf::err() << "Error: The file is not found!" << std::endl;
	sf::Sprite s_gameOver(t_gameOver);
	s_gameOver.setOrigin(t_gameOver.getSize().x / 2, t_gameOver.getSize().y / 2);
	s_gameOver.scale(4, 4);
	s_gameOver.setPosition(400, 400);

#pragma endregion

#pragma region Background Texture
	// Load background and scale it up
	sf::Texture t_background;	
	if (!t_background.loadFromFile("assets/bubbly_clouds.png"))
		sf::err() << "Error: The file is not found!" << std::endl;
	sf::Sprite s_background(t_background);
	float scaleFactor = 800 / s_background.getTextureRect().width;
	s_background.setScale(scaleFactor, scaleFactor);
	s_background.setPosition(0, -1596 * scaleFactor + 800);
	float backgroundSpeed = .09f;
#pragma endregion

#pragma region Creating Items

	// Initialize a std vector to hold the various items
	std::vector<sf::Texture> items;
	sf::Texture item1, item2, item3, item4, item5, item6, item7;

	// Load the sprites into the vector
	for (int i = 1; i < 8; i++)
	{
		sf::Texture texture;
		if (!texture.loadFromFile("assets/item" + std::to_string(i) + ".png"))
			sf::err() << "Error: The file is not found!" << std::endl;
		items.push_back(texture);
	}

	// create the targets random pos
	b2Vec2 box2DTarget = getTargetPosition();
	// Give it 64x64 size
	sf::RectangleShape targetShape(sf::Vector2f(64, 64));
	targetShape.setTexture(&items[randomNumber()]);
#pragma endregion

#pragma region Score Tracking
	// Score tracking
	sf::Font font;
	if (!font.loadFromFile("assets/ARCADECLASSIC.ttf"))
		sf::err() << "Error: The font is not found!" << std::endl;

	int score = 0;
	std::stringstream ss;
	ss << std::setw(5) << std::setfill('0') << score;
	sf::Text text;
	text.setFont(font);
	text.setString(ss.str());
	text.setCharacterSize(45);
	text.setFillColor(sf::Color::Black);
	text.setPosition(sf::Vector2f(300, 725));
	
	int targetsNeeded = 5;
	sf::Text target_text("Collect " + std::to_string(targetsNeeded), font, 30);
	target_text.setFillColor(sf::Color::Black);
	GetTextCenter(target_text);
	target_text.move(400, 30);

	sf::RectangleShape box(sf::Vector2f(180, 40));
	box.setOrigin(90, 20);
	box.move(400, 25);

#pragma endregion

#pragma region Controls

	sf::Text controls_text("Controls", font, 40);
	controls_text.setFillColor(sf::Color::Black);	
	GetTextCenter(controls_text);
	controls_text.setPosition(sf::Vector2f(400, 470));
	
	sf::Text jump_text("Move", font, 34);
	jump_text.setFillColor(sf::Color::Black);
	jump_text.setPosition(sf::Vector2f(300, 525));

	sf::Texture t_keys;
	if (!t_keys.loadFromFile("assets/keys.png"))
		sf::err() << "Error: The file is not found!" << std::endl;	
	sf::Sprite s_keys(t_keys);
	s_keys.setOrigin(t_keys.getSize().x/ 2 , t_keys.getSize().y/ 2);
	s_keys.setScale(.15, .15);
	s_keys.setPosition(460, 550);
	
#pragma endregion

#pragma region Audio
	
	sf::Music music;
	if (!music.openFromFile("assets/Float_Islands.wav"))
		sf::err() << "Error: The song is not found!" << std::endl;
	music.play();

	sf::SoundBuffer item_collect;
	if (!item_collect.loadFromFile("assets/item_collect.wav"))
		sf::err() << "Error: The song is not found!" << std::endl;
	sf::Sound sound;
	sound.setBuffer(item_collect);

#pragma endregion

#pragma region Creating Kirby

	// Creating Kirby	
	b2Body* kirby = createSnake(b2Vec2(5.0f, -1.0f), .5f, .5f);
	sf::RectangleShape kirbyShape(sf::Vector2f(2 * 100 * 0.5f, 2 * 100 * 0.5f));
	// set the origin of the shape to its center  
	kirbyShape.setOrigin(kirbyShape.getSize().x / 2, kirbyShape.getSize().y / 2);
	sf::Texture t_kirby;
	if (!t_kirby.loadFromFile("assets/Kirby_Float.png"))
		sf::err() << "Error: The file is not found!" << std::endl;
		kirbyShape.setTexture(&t_kirby);

	int kirbySpritePos = 0;
	kirbyShape.setTextureRect(sf::IntRect(kirbySpritePos, 0, 24, 24));

#pragma endregion

#pragma region Initialize/Move Objects

	// Object Sizes
	sf::RenderWindow window(sf::VideoMode(800, 800), "Gravity Snake");
	sf::RectangleShape leftWall(sf::Vector2f(-20, 800));
	sf::RectangleShape rightWall(sf::Vector2f(20, 800));
	sf::RectangleShape floor(sf::Vector2f(800, 60));
	sf::Texture gameUI;
	if (!gameUI.loadFromFile("assets/Floor.png"))
		sf::err() << "Error: The file is not found!" << std::endl;
	floor.setTexture(&gameUI);

	sf::RectangleShape ceiling(sf::Vector2f(800, 20));

	// Set their respective position
	leftWall.setPosition(Box2DToSFML(box2DLWall));
	rightWall.setPosition(Box2DToSFML(box2DRWall));
	floor.setPosition(Box2DToSFML(box2DFloorPos));
	ceiling.setPosition(Box2DToSFML(box2DCeiling));
	targetShape.setPosition(Box2DToSFML(box2DTarget));

#pragma endregion

	bool spawnObjects = true;
	bool move = false;
	sf::Clock clock;
	sf::Clock clock2;
	// run the program as long as the window is open
	while (window.isOpen())
	{
		// check all the window's events that were triggered since the last iteration of the loop
		sf::Event event;
		while (window.pollEvent(event))
		{
			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed)
				window.close();
		}

		// Clear the window with black color
		window.clear(sf::Color::Black);
		//This function advances the physics world by deltaTime, and returns the deltaTime in seconds.
		float deltaTime = updateWorldAndReturnDeltaTime();

		// Kirbys Movement
		b2Vec2 kirbyPos = kirby->GetPosition();
		sf::Vector2f kirbyPosSFML = Box2DToSFML(kirbyPos);
		kirbyShape.setPosition(kirbyPosSFML);

		//Process input and apply forces to the snake.
		if (move)
		{
			handleInput();
		}

		#pragma region Animate Kirby/ Move Background

		if (clock.getElapsedTime().asSeconds() > .1f) {
			if (kirbySpritePos == 0)
				kirbySpritePos = 24;
			else
				kirbySpritePos = 0;

			kirbyShape.setTextureRect(sf::IntRect(kirbySpritePos, 0, 23, 24));
			clock.restart();
		}

		// move background
		s_background.move(0, backgroundSpeed);
		// Checks if sprite is off screen
		if (s_background.getPosition().y >= 0)
		{
			backgroundSpeed = 0;
		}

		#pragma endregion

		window.draw(whiteBox);
		window.draw(s_logo);
		window.draw(s_credits);
		window.draw(controls_text);
		window.draw(jump_text);
		window.draw(s_keys);

		if (clock2.getElapsedTime().asSeconds() > 3.5f) {

			move = true;
			// draw everything here...
			window.draw(s_background);
			window.draw(kirbyShape);
			window.draw(leftWall);
			window.draw(rightWall);
			window.draw(floor);
			window.draw(ceiling);
			window.draw(text);
			window.draw(box);
			window.draw(target_text);
			if (spawnObjects)
			{
				window.draw(targetShape);
			}
		}

		// Checks for collision
		if (checkCollisionAndMoveTarget(1.0f) && spawnObjects)
		{
			box2DTarget = getTargetPosition();
			// Display at random position
			targetShape.setPosition(Box2DToSFML(box2DTarget));

			// Increase score
			score += 100;
			sound.play();
			ss.str("");
			ss << std::setw(5) << std::setfill('0') << score;
			text.setString(ss.str());

			// Randomize item
			targetShape.setTexture(&items[randomNumber()]);
			targetsNeeded--;
			target_text.setString("Collect " + std::to_string(targetsNeeded));
		}
		else if (targetsNeeded <= 0)
		{
			spawnObjects = false;
			window.draw(whiteBox);
			window.draw(s_gameOver);
		}
		// end the current frame
		window.display();
	}
	releaseVariables();

}