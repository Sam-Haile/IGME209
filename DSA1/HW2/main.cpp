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
	// ALL CODE ABOVE IS INITIALIZATION


	//CREATING LEFT WALL
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
		b2Vec2 force(10.0f, 1.0f); // Define the force to be applied

		// incur a force
		body->ApplyForce(force, point, true);


		std::cout << "(" << position.x << ", " << position.y << ")" << std::endl;

		// if escape is pressed set running to false
	}

	/*
	cout << "Let's play Gravity Snake!" << endl;
	cout << "Press Esc key to quit anytime..." << endl;
	cout << "Press Enter key to begin..." << endl;*/


}
