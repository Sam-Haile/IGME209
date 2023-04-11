#pragma once
#define SFML_STATIC
#include <GravitySnake.h>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Functions.h"
#include <iostream>

class GameOver
{
public:
	GameOver();
	void drawObject(sf::RenderWindow& window);


	sf::Texture m_gameOverTexture;
	sf::Sprite m_gameOverSprite;
};

