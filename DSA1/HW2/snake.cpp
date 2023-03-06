//define methods
#include <conio.h>
#include <cmath>
#include <iostream>
#define SFML_STATIC
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include "snake.h"
using namespace sf;

void Update(b2World& world, sf::Clock& deltaClock)
{
	sf::Time deltaTime;

	//Calculating time
	deltaTime = deltaClock.getElapsedTime();
	deltaClock.restart();
	// Advances world by num of seconds
	world.Step(deltaTime.asSeconds(), 6, 2);
}

void Display(double targetX, double targetY, double playerX, double playerY)
{

	std::cout << "Target " << targetX << ", " << targetY <<
		" --> " << "Snake " << playerX << ", " << playerY << std::endl;

}

void ApplyForces(int keyPress, b2Body* snakeBody, b2Vec2 targetPosition, bool jump_pressed)
{
	switch (keyPress)
	{
	
		case 119: //W
		{
			//Apply upward force
			b2Vec2 force(0.0f, 100.0f);
			snakeBody->ApplyForceToCenter(force, true);
			jump_pressed = false;
			break;
		}
		case 97: //A
		{
			//Apply leftward force
			b2Vec2 force(-100.0f, 0.0f);
			snakeBody->ApplyForceToCenter(force, true);
			jump_pressed = false;
			break;
		}
		case 115: //S
		{
			//Apply downard force
			b2Vec2 force(0.0f, -100.0f);
			snakeBody->ApplyForceToCenter(force, true);
			jump_pressed = false;
			break;
		}
		case 100: //D
		{
			//Apply rightward firce
			b2Vec2 force(100.0f, 0.0f);
			snakeBody->ApplyForceToCenter(force, true);
			jump_pressed = false;
			break;
		}
		case 32: //SpaceBar
		{
			//Apply jumping force
			if (!jump_pressed) {
				b2Vec2 force(0.0f, 1000.0f);
				snakeBody->ApplyForceToCenter(force, true);
				// Set the flag to indicate 'Jump' has been pressed
				jump_pressed = true;
			}
			break;
		}
		default:
			break;
	}
}

b2Vec2 MoveTarget(b2Vec2* target) {

	// Define a range for the random values
	const float minX = -5.0f;
	const float maxX = 5.0f;
	const float minY = -5.0f;
	const float maxY = 5.0f;

	// Generate random x and y values within the range
	float randX = (float)rand() / RAND_MAX * (maxX - minX) + minX;
	float randY = (float)rand() / RAND_MAX * (maxY - minY) + minY;

	// round random values to tenths
	randX = std::round(randX * 10) / 10;
	randY = std::round(randY * 10) / 10;

	b2Vec2 targetPosition(randX, randY);

	return targetPosition;
}

