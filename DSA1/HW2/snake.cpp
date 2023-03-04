//define methods
#include <iostream>
#define SFML_STATIC
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include "snake.h"

void Update(b2World& world, sf::Clock& deltaClock) 
{
	b2BodyDef groundBodyDef;
	groundBodyDef.position.Set(0.0f, -10.0f);
	b2Body* groundBody = world.CreateBody(&groundBodyDef);

	b2PolygonShape groundBox;
	groundBox.SetAsBox(50.0f, 10.0f);
	// NOTE: Objects that dont move have 0 density
	groundBody->CreateFixture(&groundBox, 0.0f);

	// Created the falling box
	b2BodyDef bodyDef;
	// NOTE: Dynamic bodies are affected by forces
	bodyDef.type = b2_dynamicBody;
	// Set default position
	bodyDef.position.Set(0.0f, 9.0f);
	// Tell world to create dynamic body
	b2Body* body = world.CreateBody(&bodyDef);

	b2PolygonShape dynamicBox;
	dynamicBox.SetAsBox(1.0f, 1.0f);

	b2FixtureDef fixtureDef;
	fixtureDef.shape = &dynamicBox;
	fixtureDef.density = 1.0f;
	fixtureDef.friction = 0.3f;
	body->CreateFixture(&fixtureDef);
	
	// Calculating DeltaTime
	sf::Time deltaTime;

	bool running = true;
	b2Vec2 position;

	while (running)
	{
		deltaTime = deltaClock.getElapsedTime();
		deltaClock.restart();
		// Advances world by num of seconds
		world.Step(deltaTime.asSeconds(), 6, 2);

		position = body->GetPosition();
		std::cout << "(" << position.x << ", " << position.y << ")" << std::endl;
		// if escape is pressed set running to false

	}

}

void Display(int& targetX, int& targetY, int& playerX, int& playerY) 
{
	std::cout << "Target " << targetX << ", " << targetY 
			  << "--> Snake " << playerX << ", " << playerY << std::endl;

	if (playerX == targetX && playerY == targetY)
	{
		std::cout << "Target " << targetX << ", " << targetY
			<< "--> Snake " << playerX << ", " << playerY << "	TARGET HIT" << std::endl;
	}
}

void ApplyForces()
{

}
