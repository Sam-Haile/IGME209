#include "MainMenu.h"


MainMenu::MainMenu(sf::Font& font) {

	if (!font.loadFromFile("assets/ARCADECLASSIC.ttf"))
		sf::err() << "Error: The font is not found!" << std::endl;

	m_whiteBox.setSize(sf::Vector2f(800, 800));
	m_whiteBox.setFillColor(sf::Color(248, 248, 248));


	if (!m_logoTexture.loadFromFile("assets/Title_Screen.png"))
		sf::err() << "Error: The file is not found!" << std::endl;
	m_logoSprite.setTexture(m_logoTexture);
	m_logoSprite.setOrigin(m_logoTexture.getSize().x / 2, m_logoTexture.getSize().y / 2 + 40);
	m_logoSprite.scale(4, 4);
	m_logoSprite.setPosition(400, 400);

	if (!m_creditsTexture.loadFromFile("assets/credits.png"))
		sf::err() << "Error: The file is not found!" << std::endl;
	m_creditsSprite.setTexture(m_creditsTexture);
	m_creditsSprite.setOrigin(m_creditsTexture.getSize().x / 2, m_creditsTexture.getSize().y / 2);
	m_creditsSprite.scale(4, 4);
	m_creditsSprite.setPosition(400, 700);

	m_controlsText.setString("Controls");
	m_controlsText.setFont(font);
	m_controlsText.setCharacterSize(40);
	m_controlsText.setFillColor(sf::Color::Black);
	GetTextCenter(m_controlsText);
	m_controlsText.setPosition(sf::Vector2f(400, 470));

	m_jumpText.setString("Move");
	m_jumpText.setCharacterSize(34);
	m_jumpText.setFont(font);
	m_jumpText.setFillColor(sf::Color::Black);
	m_jumpText.setPosition(sf::Vector2f(300, 525));

	if (!m_keysTexture.loadFromFile("assets/keys.png"))
		sf::err() << "Error: The file is not found!" << std::endl;
	m_keysSprite.setTexture(m_keysTexture);
	m_keysSprite.setOrigin(m_keysTexture.getSize().x / 2, m_keysTexture.getSize().y / 2);
	m_keysSprite.setScale(.15, .15);
	m_keysSprite.setPosition(460, 550);

}

void MainMenu::drawObjects(sf::RenderWindow& window)
{
	window.draw(m_whiteBox);
	window.draw(m_logoSprite);
	window.draw(m_creditsSprite);
	window.draw(m_controlsText);
	window.draw(m_jumpText);
	window.draw(m_keysSprite);
}

void MainMenu::drawBox(sf::RenderWindow& window)
{
	window.draw(m_whiteBox);
}