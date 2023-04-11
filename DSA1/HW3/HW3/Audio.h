#pragma once
#define SFML_STATIC
#include <GravitySnake.h>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Functions.h"
#include <iostream>
#include <SFML/Audio.hpp>

class Audio
{
public:
	Audio();
	void playItemCollect();
	sf::Music m_music;
	sf::SoundBuffer m_itemCollect;
	sf::Sound m_sound;
};


