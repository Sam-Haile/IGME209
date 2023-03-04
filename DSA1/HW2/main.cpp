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

	cout << "Let's play Gravity Snake!" << endl;
	cout << "Press Esc key to quit anytime..." << endl;
	cout << "Press Enter key to begin..." << endl;


	do
	{
		int key = _getch();
		if (key == enterKey)
			break;

	} while (key != enterKey);

	while (key != escKey)
	{
		// Create the world 
		// gravity can be changed below
		b2Vec2 gravity(0.0f, -9.8f);
		b2World world(gravity);
		Clock deltaClock;

		Update(world, deltaClock);



		int key = _getch();
		if (key == escKey)
			return 0;
		std::cout << "Thank you for playing! " << key << std::endl;
	}







}
