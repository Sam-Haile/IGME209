// PE5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <conio.h> // for input
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
	b2Vec2 gravity(0.0f, -9.8f);
	b2World world(gravity);
	Clock deltaClock;

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


	// Snake
	b2BodyDef bodyDef;
	bodyDef.type = b2_dynamicBody;  //Makes the object move
	bodyDef.position.Set(0.0f, 4.0f); // Location of the snake
	b2Body* body = world.CreateBody(&bodyDef);
	// Set shape as square
	b2PolygonShape dynamicBox;
	dynamicBox.SetAsBox(1.0f, 1.0f);
	// Set box density and friction
	b2FixtureDef fixtureDef;
	fixtureDef.shape = &dynamicBox;
	fixtureDef.density = 1.0f;
	fixtureDef.friction = 0.3f;
	body->CreateFixture(&fixtureDef);

	// Calculating DeltaTime
	sf::Time deltaTime;
	b2Vec2 position;
	b2Vec2 point;
	bool wake = true;

	bool running = true;

	while (running)
	{
		//Calculating time
		deltaTime = deltaClock.getElapsedTime();
		deltaClock.restart();
		// Advances world by num of seconds
		world.Step(deltaTime.asSeconds(), 6, 2);

		// Get position and center of box
		position = body->GetPosition();
		point = body->GetWorldPoint(position);

		// Force to move object
		//b2Vec2 force(10.0f, 10.0f); // Define the force to be applied

		// incur a force
		//body->ApplyForce(force, point, true);


		//std::cout << "(" << position.x << ", " << position.y << ")" << std::endl;

		// if escape is pressed set running to false
		bool quit = false;

		bool jump_pressed = false; // A flag to track if 'jump' has been pressed
		while (!quit) {
			if (_kbhit()) { // Check if a key has been pressed
				char c = _getch(); // Get the character of the key pressed
				std::cout << "Key pressed: " << static_cast<int>(c) << std::endl;
				switch (c) {
				case 27:
					std::cout << "Esc";
					quit = true;
					break;
					// This case is upwards continuos
				case 'w':
					std::cout << "W";
					break;
					if (!jump_pressed) { // Check if 'q' has not been pressed before
						// Do something when 'q' is pressed
						jump_pressed = true; // Set the flag to indicate 'q' has been pressed
					}
				case 32:
					std::cout << "Jump";
					break;
				case 'a':
					std::cout << "A";
					break;
				case 's':
					std::cout << "S";
					break;
				case 'd':
					std::cout << "D";
					break;
				default:
					std::cout << "erv";
					break;
				}
			}
			// Do other things in the loop
		}
		return 0;

	}

	/*
	cout << "Let's play Gravity Snake!" << endl;
	cout << "Press Esc key to quit anytime..." << endl;
	cout << "Press Enter key to begin..." << endl;*/


}
