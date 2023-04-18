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
	int numOfGordo = 3;			// Number of enemies that spawn per wave
	int targetNeeded = 12;		// Targets needed for game
	float spawnRate = 4.0f;		// Set frequency of spawn rate for enemies
	bool spawnObjects = true;	// Spawns object until game is done
	bool showMainMenu = true;	// Draw menu for X amount of time
	float scrollSpeed = 0.1f;	// Speed of background paralax
	float gordoSpeed = 0.1f;	// Speed of background paralax

	// Improves formatting of console output.
	cout << fixed << showpoint << setprecision(2);

	setTargetBounds(1.0f, 7.0f, -6.6f, -1.0f);
	//Create the physics world, and all the objects. Return a pointer to the body.
	//These functions are from the DLL.
	initVariables(b2Vec2(0.0f, -9.8f));
	// Load window and font
	sf::RenderWindow window(sf::VideoMode(800, 800), "Gravity Snake");
	sf::Font font;
	if (!font.loadFromFile("assets/ARCADECLASSIC.ttf"))
		sf::err() << "Error: The font is not found!" << std::endl;

	// Initialize game components
	Game game;
	Kirby kirby;
	Audio audio;
	sf::Clock clock;
	sf::Clock enemySpawner;
	MainMenu mainMenu(font);
	Score score(font, targetNeeded, sf::Vector2f(300, 725));

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

		//Animates kirby and gordo
		kirby.playerUpdate();
		game.animate();

		if (showMainMenu)
		{
			mainMenu.drawObjects(window);
		}

		if (clock.getElapsedTime().asSeconds() > 1.5f) {
		
			window.clear(sf::Color::Black);
			showMainMenu = false;
			game.drawGameObjects(window, true);
			kirby.draw(window);
			game.moveObjects(scrollSpeed, gordoSpeed);
			score.drawScore(window, score);
		}

		if (enemySpawner.getElapsedTime().asSeconds() > spawnRate)
		{
			game.generateGordo(numOfGordo);
			enemySpawner.restart();
		}

		//Reference to list of enemies and kirbys rectangles
		sf::RectangleShape& playerRect = kirby.getPlayerRect();

		//Checks for collision between player and enemy
		game.enemyCollision(playerRect, &spawnObjects);
		// Checks for collision with items
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
		}
		else if (score.getTargetsNeeded() <= 0 || !spawnObjects)
		{
			spawnObjects = false;
			window.clear(sf::Color::Black);
			mainMenu.drawBox(window);
		}
		// end the current frame
		window.display();
	}


	void releaseVariables();
}