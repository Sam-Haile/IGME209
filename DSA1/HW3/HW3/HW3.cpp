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
#include "Score.h"
#include "Kirby.h"
#include "Game.h"
using namespace std;

int main()
{
	// Improves formatting of console output.
	cout << fixed << showpoint << setprecision(2);

	setTargetBounds(1.0f, 7.0f, -6.6f, -1.0f);
	//Create the physics world, and all the objects. Return a pointer to the snake body.
	//These functions are from the DLL.
	initVariables(b2Vec2(0.0f, -9.8f));
	Kirby kirby;


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

	
#pragma region Controls
	
	sf::Font font;
	if (!font.loadFromFile("assets/ARCADECLASSIC.ttf"))
		sf::err() << "Error: The font is not found!" << std::endl;

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
	//music.play();

	sf::SoundBuffer item_collect;
	if (!item_collect.loadFromFile("assets/item_collect.wav"))
		sf::err() << "Error: The song is not found!" << std::endl;
	sf::Sound sound;
	sound.setBuffer(item_collect);

#pragma endregion

	sf::RenderWindow window(sf::VideoMode(800, 800), "Gravity Snake");
	Game game;
	game.createObjects();
	
	int targetNeeded = 5;
	Score score(font, targetNeeded, sf::Vector2f(300, 725));

	bool spawnObjects = true;
	sf::Clock clock;
	
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
		
		window.clear(sf::Color::Black);
		float deltaTime = updateWorldAndReturnDeltaTime();


		kirby.move();
		handleInput();

		kirby.playerUpdate();
		game.moveBackground(0.5f);

		window.draw(whiteBox);
		window.draw(s_logo);
		window.draw(s_credits);
		window.draw(controls_text);
		window.draw(jump_text);
		window.draw(s_keys);

		if (clock.getElapsedTime().asSeconds() > .5f) {

			game.drawObjects(window, true);
			kirby.draw(window);
			score.drawScore(window, score);
			
		}

		// Checks for collision
		if (checkCollisionAndMoveTarget(1.0f) && spawnObjects)
		{
			//// Display at random position
			game.randomPos();

			sound.play();
			// Increase score and reduce target count
			targetNeeded--;
			score.increaseScore(100);
			score.setTargetsNeeded(targetNeeded);
			//
			//// Spawn random item
			game.setNewItem();
			//targetShape.setTexture(&items[randomNumber()]);
		}
		else if (score.getTargetsNeeded() <= 0)
		{
			spawnObjects = false;
			window.draw(whiteBox);
			window.draw(s_gameOver);
		}
		// end the current frame
		window.display();
	}
	void releaseVariables();

}