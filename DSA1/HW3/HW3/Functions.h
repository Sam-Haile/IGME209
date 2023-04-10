#pragma once
#include <Box2D/Box2D.h>
#define SFML_STATIC
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

void display(b2Body* snake);
void handleInput();
int randomNumber();
void GetTextCenter(sf::Text& text);
sf::Vector2f Box2DToSFML(const b2Vec2& vec);
b2Vec2 SFMLToBox2D(const sf::Vector2f& vec);
