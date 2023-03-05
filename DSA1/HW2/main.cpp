// PE5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <conio.h> // for input
#include <cmath>
#include <iostream>
#define SFML_STATIC
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include "snake.h"

using namespace sf;
using namespace std;

int main()
{
	// ASCII codes for keys
	int escKey = 27;
	int enterKey = 13;
	int key = 0;

	// Create world
	b2Vec2 gravity(0.0f, -.1f);
	b2World world(gravity);
	Clock deltaClock;

#pragma region Creating Floor

	//CREATING FLOOR
	//initialize the ground
	b2BodyDef groundBodyDef;
	groundBodyDef.position.Set(0.0f, 0.0f);
	b2Body* groundBody = world.CreateBody(&groundBodyDef);
	//Ground Shape
	b2PolygonShape groundShape;
	groundShape.SetAsBox(50.0f, -1.0f); // Set the dimensions to half-width and full-height
	// Create ground fixture
	b2FixtureDef groundFixtureDef;
	groundFixtureDef.shape = &groundShape;
	// Attach fixture to ground body
	groundBody->CreateFixture(&groundFixtureDef);

#pragma endregion

#pragma region Walls
	//CREATING RIGHT WALL
	//initialize the wall body
	b2BodyDef wallBodyDefR;
	// Position of the wall body
	wallBodyDefR.position.Set(7.1f, 0.0f);
	b2Body* wallBodyR = world.CreateBody(&wallBodyDefR);
	//Walls Shape
	b2PolygonShape wallShapeR;
	// Set the dimensions to half-width and full-height
	wallShapeR.SetAsBox(1.0f, 50.0f);
	// Create wall fixture
	b2FixtureDef wallFixtureDefR;
	wallFixtureDefR.shape = &wallShapeR;
	// Attach fixture to ground body
	wallBodyR->CreateFixture(&wallFixtureDefR);

	//CREATING LEFT WALL
	//initialize the wall body
	b2BodyDef wallBodyDefL;
	// Position of the wall body
	wallBodyDefL.position.Set(-7.1f, 0.0f);
	b2Body* wallBodyL = world.CreateBody(&wallBodyDefL);
	//Walls Shape
	b2PolygonShape wallShapeL;
	// Set the dimensions to half-width and full-height
	wallShapeL.SetAsBox(1.0f, 50.0f);
	// Create wall fixture
	b2FixtureDef wallFixtureDefL;
	wallFixtureDefL.shape = &wallShapeL;
	// Attach fixture to ground body
	wallBodyL->CreateFixture(&wallFixtureDefL);

#pragma endregion

#pragma region Snake

	// Snake
	b2BodyDef snakeBodyDef;
	snakeBodyDef.type = b2_dynamicBody;  //Makes the object move
	snakeBodyDef.position.Set(0.0f, 4.0f); // Location of the snake
	b2Body* body = world.CreateBody(&snakeBodyDef);
	// Set shape as square
	b2PolygonShape dynamicBox;
	dynamicBox.SetAsBox(1.0f, 1.0f);
	// Set box density and friction
	b2FixtureDef fixtureDef;
	fixtureDef.shape = &dynamicBox;
	fixtureDef.density = 1.0f;
	fixtureDef.friction = 0.3f;
	body->CreateFixture(&fixtureDef);

#pragma endregion


	// Calculating DeltaTime
	sf::Time deltaTime;
	bool running = true;
	bool jump_pressed = false; // A flag to track if 'jump' has been pressed
	// Get position and center of box
	b2Vec2 position = body->GetPosition();
	b2Vec2 point = body->GetWorldPoint(position);


	while (running)
	{
		//Calculating time
		deltaTime = deltaClock.getElapsedTime();
		deltaClock.restart();
		// Advances world by num of seconds
		world.Step(deltaTime.asSeconds(), 6, 2);

		//Update position
		position = body->GetPosition();
		point = body->GetWorldPoint(position);

		//Round positions to tenths
		double positionX = std::round(position.x * 10) / 10;
		double positionY = std::round(position.y * 10) / 10;

		std::cout << "(" << positionX << ", " << positionY << ")" << std::endl;

		// if escape is pressed set running to false
		bool quit = false;

		// Check for keyboard input
		// Add a force to the game
		if (_kbhit()) { 
			// Get the character of the key pressed
			char key = _getch();
			switch (key) {
			case 27:
				std::cout << "\nTHANKS FOR PLAYING";
				running = false;
				break;
			case 'w': {
				ApplyForces(119, body);
				jump_pressed = false;
				break;
			}
			case 'a': {
				ApplyForces(97, body);
				jump_pressed = false;
			}
				break;
			case 's':
				std::cout << "S";
				jump_pressed = false;
				break;
			case 'd':
				ApplyForces(100, body);
				jump_pressed = false;
				break;
			case 32:
				// Check if 'Jump' has not been pressed before
				if (!jump_pressed) { 
					ApplyForces(32, body);
					// Set the flag to indicate 'Jump' has been pressed
					jump_pressed = true; 
				}
				break;
			default:
				std::cout << "erv";
				break;
			}
		}
	}
	return 0;
}



