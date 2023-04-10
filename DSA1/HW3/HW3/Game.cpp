#include "Game.h"

void Game::moveBackground(float backgroundSpeed) {

	s_background.move(0, backgroundSpeed);
	// Checks if sprite is off screen
	if (s_background.getPosition().y >= 0)
	{
		backgroundSpeed = 0;
	}

}

void Game::setNewItem() {
	// Spawn random item
	m_targetShape.setTexture(&m_items[randomNumber()]);
}

void Game::drawObjects(sf::RenderWindow& window, bool spawn) {

	window.draw(s_background);
	window.draw(m_leftWall);
	window.draw(m_rightWall);
	window.draw(m_ceiling);
	window.draw(m_floor);

	if (spawn)
	{
		window.draw(m_targetShape);
	}
}

void Game::randomPos() {

	m_box2DTarget = getTargetPosition();
	m_targetShape.setPosition(Box2DToSFML(m_box2DTarget));
}


void Game::createObjects() {

	// Load background and scale it up
	if (!t_background.loadFromFile("assets/bubbly_clouds.png"))
		sf::err() << "Error: The file is not found!" << std::endl;
	s_background.setTexture(t_background);

	// Creating the walls/floor
	b2Vec2 box2DLWall = b2Vec2(0.2f, 0.0f);
	createLeftWall(b2Vec2(box2DLWall), 0.0f, 8.0f);
	b2Vec2 box2DRWall = b2Vec2(7.8f, 0.0f);
	createRightWall(b2Vec2(box2DRWall), 0.0f, 8.0f);
	b2Vec2 box2DFloorPos = b2Vec2(0.0f, -7.4f);
	createFloor(b2Vec2(box2DFloorPos), 10.0f, 0.0f);
	b2Vec2 box2DCeiling = b2Vec2(0.0f, -0.0f);
	createCeiling(b2Vec2(box2DCeiling), 10.0f, 0.0f);

	float scaleFactor = 800 / s_background.getTextureRect().width;
	s_background.setScale(scaleFactor, scaleFactor);
	s_background.setPosition(0, -1596 * scaleFactor + 800);
	float backgroundSpeed = .09f;

	// Initialize a std vector to hold the various items
	sf::Texture item1, item2, item3, item4, item5, item6, item7;

	// Load the sprites into the vector
	for (int i = 1; i < 8; i++)
	{
		sf::Texture texture;
		if (!texture.loadFromFile("assets/item" + std::to_string(i) + ".png"))
			sf::err() << "Error: The file is not found!" << std::endl;
		m_items.push_back(texture);
	}

	// create the targets random pos
	b2Vec2 m_box2DTarget = getTargetPosition();
	// Give it 64x64 size	
	m_targetShape.setSize(sf::Vector2f(64, 64));
	m_targetShape.setTexture(&m_items[randomNumber()]);

	// Object Sizes
	m_leftWall.setSize(sf::Vector2f(-20, 800));
	m_rightWall.setSize(sf::Vector2f(20, 800));
	m_floor.setSize(sf::Vector2f(800, 60));
	m_ceiling.setSize(sf::Vector2f(800, 20));
	
	sf::Texture m_gameUI;
	if (!m_gameUI.loadFromFile("assets/Floor.png"))
		sf::err() << "Error: The file is not found!" << std::endl;	
	m_floor.setTexture(&m_gameUI);


	// Set their respective position
	m_leftWall.setPosition(Box2DToSFML(box2DLWall));
	m_rightWall.setPosition(Box2DToSFML(box2DRWall));
	m_floor.setPosition(Box2DToSFML(box2DFloorPos));
	m_ceiling.setPosition(Box2DToSFML(box2DCeiling));
	m_targetShape.setPosition(Box2DToSFML(m_box2DTarget));

}



