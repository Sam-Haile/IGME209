#pragma once
#define SFML_STATIC
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <Box2D/Box2D.h>
#include <GravitySnake.h>
#include <iostream>
#include <conio.h>
#include <ctime>

void display(b2Body* snake);
void handleInput();
int randomNumber();
void GetTextCenter(sf::Text& text);
sf::Vector2f Box2DToSFML(const b2Vec2& vec);
b2Vec2 SFMLToBox2D(const sf::Vector2f& vec);
