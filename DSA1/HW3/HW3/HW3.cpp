// HW3 - Graphical Snake
// Sam Haile
// DSA1.06
/* Unique Feature :
Not sure if this counts but I  made my game
resemble Kirby's dream land from the game boy
*/
#define SFML_STATIC
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <GravitySnake.h>
#include "Functions.h"
#include "MainMenu.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include "Score.h"
#include "Kirby.h"
#include "Game.h"
#include "Audio.h"
using namespace std;

int main()
{
	// Improves formatting of console output.
	cout << fixed << showpoint << setprecision(2);

	setTargetBounds(1.0f, 7.0f, -6.6f, -1.0f);
	//Create the physics world, and all the objects. Return a pointer to the body.
	//These functions are from the DLL.
	initVariables(b2Vec2(0.0f, -9.8f));
	sf::RenderWindow window(sf::VideoMode(800, 800), "Gravity Snake");

	sf::Font font;
	if (!font.loadFromFile("assets/ARCADECLASSIC.ttf"))
		sf::err() << "Error: The font is not found!" << std::endl;

	MainMenu mainMenu(font);
	Game game;
	Kirby kirby;
	Audio audio;

	int targetNeeded = 5;
	Score score(font, targetNeeded, sf::Vector2f(300, 725));
	
	bool spawnObjects = true;
	sf::Clock clock;
	float scrollSpeed = 0.1f;


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

		game.moveBackground(scrollSpeed);

		mainMenu.drawObjects(window);

		if (clock.getElapsedTime().asSeconds() > 1.5f) {

			game.drawGameObjects(window, true);
			kirby.draw(window);
			score.drawScore(window, score);
		}

		// Checks for collision
		if (checkCollisionAndMoveTarget(1.0f) && spawnObjects)
		{
			//// Display at random position
			game.itemRandomPos();

			audio.playItemCollect();
			// Increase score and reduce target count
			targetNeeded--;
			score.increaseScore(100);
			score.setTargetsNeeded(targetNeeded);
			
			// Spawn random item
			game.setNewItem();
			//targetShape.setTexture(&items[randomNumber()]);
		}
		else if (score.getTargetsNeeded() <= 0)
		{
			spawnObjects = false;
			mainMenu.drawBox(window);
		}
		// end the current frame
		window.display();
	}
	void releaseVariables();

}