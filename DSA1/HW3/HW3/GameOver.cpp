#include "GameOver.h"


GameOver::GameOver() {
	
	
	sf::Texture t_gameOver;
	if (!m_gameOverTexture.loadFromFile("assets/GameOver.png"))
		sf::err() << "Error: The file is not found!" << std::endl;
	(m_gameOverTexture);
	m_gameOverSprite.setOrigin(m_gameOverTexture.getSize().x / 2, m_gameOverTexture.getSize().y / 2);
	m_gameOverSprite.scale(4, 4);
	m_gameOverSprite.setPosition(400, 400);
}

void GameOver::drawObject(sf::RenderWindow& window)
{

	window.draw(m_gameOverSprite);
}
