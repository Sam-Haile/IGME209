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

int main()
{
	int key = 0; 	// For ASCII keys of various letter inputs
	int score = 0; 	// Tracks score to display at the end of the game
	bool jump_pressed = false; // A flag to track if 'jump' has been pressed
	bool hitTarget = false;
	// Create the world
	b2Vec2 gravity(0.0f, -0.1f);
	b2World world(gravity);
	Clock deltaClock;
	/* Vector 2 for position of target
	 assign the targets position randomly */
	b2Vec2 targetPos;
	targetPos = MoveTarget(&targetPos);

	#pragma region Creating Floor/Roof

	//initialize the ground
	b2BodyDef groundBodyDef;
	groundBodyDef.position.Set(0.0f, -5.0f);
	b2Body* groundBody = world.CreateBody(&groundBodyDef);
	//Ground Shape
	b2PolygonShape groundShape;
	groundShape.SetAsBox(50.0f, -1.0f);
	// Create ground fixture
	b2FixtureDef groundFixtureDef;
	groundFixtureDef.shape = &groundShape;
	groundFixtureDef.friction = 0.5f;
	// Attach fixture to ground body
	groundBody->CreateFixture(&groundFixtureDef);

	//CREATING ROOF
	// In case snake goes too high and over a wall
	b2BodyDef roofBodyDef;
	roofBodyDef.position.Set(0.0f, 5.0f);
	b2Body* roofBody = world.CreateBody(&roofBodyDef);
	b2PolygonShape roofShape;
	roofShape.SetAsBox(50.0f, -1.0f);
	b2FixtureDef roofFixtureDef;
	roofFixtureDef.shape = &roofShape;
	roofBody->CreateFixture(&roofFixtureDef);

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
	b2BodyDef wallBodyDefL;
	wallBodyDefL.position.Set(-7.1f, 0.0f);
	b2Body* wallBodyL = world.CreateBody(&wallBodyDefL);
	b2PolygonShape wallShapeL;
	wallShapeL.SetAsBox(1.0f, 50.0f);
	b2FixtureDef wallFixtureDefL;
	wallFixtureDefL.shape = &wallShapeL;
	wallBodyL->CreateFixture(&wallFixtureDefL);

	#pragma endregion

	#pragma region Snake

	// Snake
	b2BodyDef snakeBodyDef;
	snakeBodyDef.type = b2_dynamicBody;  //Makes the object move
	snakeBodyDef.position.Set(2.0f, 4.0f); // Location of the snake
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

	// Introduce the game and controls
	#pragma region Intro to Game
	system("Color 0B");
	std::cout << "Welcome to Gravity Snake!" << std::endl;
	std::cout << "\nControls:\nWASD - Move\n\SpaceBar - Jump" << std::endl;
	std::cout << "\nPress Enter to continue..." << "\nPress Esc to quit..." << std::endl;

	bool validInput = false;
	while (!validInput)
	{

		char key = _getch();
		switch (key) {
			// If player wants to quit
		case 27:
		{
			system("Color 0B");
			hitTarget = true;
			validInput = true;
			break;
		}
		// If player wants to continue 
		case 13:
			system("Color 0F");
			hitTarget = false; //Resume while loop
			validInput = true;
			break;
		default:
			break;
		}
	}
	#pragma endregion

	//Main game logic
	#pragma region Game
	while (!hitTarget)
	{
		Update(world, deltaClock);

		//Update position of snake
		b2Vec2 position = body->GetPosition();
		b2Vec2 point = body->GetWorldPoint(position);

		//Round positions to tenths
		double positionX = std::round(position.x * 10) / 10;
		double positionY = std::round(position.y * 10) / 10;

		// Display targets and snakes location
		Display(targetPos.x, targetPos.y, positionX, positionY);

		/* Check for keyboard input
		* Depending on button press
		* apply a force in a direction*/
		if (_kbhit())
		{
			char key = _getch();
			ApplyForces(key, body, targetPos, jump_pressed);
			
			if (key == 27) // If esc key is pressed
			{
				system("Color 0B");
				std::cout << "\nTHANKS FOR PLAYING" <<
							"	FINAL SCORE: " << score << std::endl;
				hitTarget = true;
			}
		}
	#pragma endregion

	/* The if statement below does 2 things
	* 1. Determine if a target is close enough and increase score
	* 2. Every 2 points, ask the user if they would like to continue or quit 
	*/
	#pragma region Target/Score syst.
		if (b2Distance(position, targetPos) < 0.2f)
		{
			score++;
			if (score % 2 == 0 && score != 0)
			{
				hitTarget = true;
				system("Color 0B");
				std::cout << "\n\nNice job! You hit: " << score << " targets." 
							<< "\nPress Enter to continue..." 
							<< "\nPress Esc to quit..." << std::endl;

				bool validInput = false;
				while (!validInput)
				{

					char key = _getch();
					switch (key) {
						// If player wants to quit
					case 27:
					{
						system("Color 0B");
						std::cout << "\n\nWell Done!\t" << "Final Score: " << score << std::endl;
						validInput = true;
						break;
					}
					// If player wants to continue 
					case 13:
						system("Color 0F");
						hitTarget = false; //Resume game loop
						validInput = true;
						break;
					default:
						break;
					}
				}
			}

			targetPos = MoveTarget(&targetPos);
		}
	#pragma endregion

	}
	
}



