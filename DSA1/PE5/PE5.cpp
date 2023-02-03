// PE5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#define SFML_STATIC
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
	// create the window
	sf::RenderWindow window(sf::VideoMode(800, 600), "My window");
	
	// run programs as long as window is open
	while (window.isOpen())
	{

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}

		//Clear window
		window.clear(sf::Color::Black);

		// Draw Here
		//window.draw(line, 2, sf::Lines);
		sf::CircleShape shape(50);

		// set the shape color to green
		shape.setFillColor(sf::Color(100, 250, 50));


		window.display();
	}

	return 0;
}
