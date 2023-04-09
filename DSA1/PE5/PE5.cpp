// PE5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#define SFML_STATIC
#include <SFML/Window.hpp>
#include <iostream>
#include <SFML/Graphics.hpp>
int main()
{

    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");
    // Define circle
    sf::CircleShape circle(100);
    // Define rectangle
    sf::RectangleShape rectangle(sf::Vector2f(120, 50));
    // Define triangle
    sf::CircleShape circleTwo(75);

    // set the circle color to green
    circle.setFillColor(sf::Color(100, 250, 50));

    circle.move(150, 150);
    rectangle.move(300, 400);
    circleTwo.move(500, 150);

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

        // clear the window with black color
        window.clear(sf::Color::Black);



        window.draw(circle);
        window.draw(rectangle);
        window.draw(circleTwo);

        // end the current frame
        window.display();
    }

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
