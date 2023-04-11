#pragma once
#define SFML_STATIC
#include <GravitySnake.h>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Functions.h"
#include <iostream>
class MainMenu
{
protected:
	sf::Text m_jumpText;

private:
	sf::Text m_controlsText;
	sf::Texture m_keysTexture;
	sf::Sprite m_keysSprite;

	sf::RectangleShape m_whiteBox;
	sf::Texture m_logoTexture;
	sf::Sprite m_logoSprite;

	sf::Texture m_creditsTexture;
	sf::Sprite m_creditsSprite;

public:
	MainMenu(sf::Font& font);
	void drawObjects(sf::RenderWindow& window);
	void drawBox(sf::RenderWindow& window);
};

