#include "Audio.h"

Audio::Audio(){

	if (!m_music.openFromFile("assets/Float_Islands.wav"))
		sf::err() << "Error: The song is not found!" << std::endl;
	m_music.play();

	if (!m_itemCollect.loadFromFile("assets/item_collect.wav"))
		sf::err() << "Error: The song is not found!" << std::endl;
	m_sound.setBuffer(m_itemCollect);
}

void Audio::playItemCollect() {
	m_sound.play();
}

