#include "Game.h"

/// <summary>
/// Moves the background and enemies
/// </summary>
/// <param name="backgroundSpeed"></param>
/// <param name="numOfGordo"></param>
void Game::moveObjects(float& backgroundSpeed, float& gordoSpeed) {

	s_background.move(0, backgroundSpeed);
	// Checks if sprite is off screen
	if (s_background.getPosition().y >= 0)
	{
		backgroundSpeed = 0;
	}

	
	for (int i = 0; i < m_listOfGordos.size(); i++)
	{
		m_listOfGordos[i].move(0, gordoSpeed);
	}

}

void Game::setNewItem() {
	// Spawn random item
	m_targetShape.setTexture(&t_items[randomNumber()]);
}

/// <summary>
/// Draws the games background, 
/// </summary>
/// <param name="window"></param>
/// <param name="spawn"></param>
void Game::drawGameObjects(sf::RenderWindow& window, bool spawn) {


	window.draw(s_background);
	drawHearts(window);
	if (spawn)
	{
		for (int i = 0; i < m_listOfGordos.size(); i++)
		{
			window.draw(m_listOfGordos[i]);
		}
	}
	window.draw(m_targetShape);
	window.draw(m_leftWall);
	window.draw(m_rightWall);
	window.draw(m_ceiling);
	window.draw(m_floor);
}

void Game::drawHearts(sf::RenderWindow& window) {

	for (int i = 0; i < m_listOfHearts.size(); i++)
	{
		m_listOfHearts[i]->setPosition(sf::Vector2f(x_spacing, 785));
		window.draw(*m_listOfHearts[i]);
		x_spacing += 25;
	}
}


/// <summary>
/// Display item at a random position
/// </summary>
void Game::itemRandomPos() {
	m_box2DTarget = getTargetPosition();
	m_targetShape.setPosition(Box2DToSFML(m_box2DTarget));
}

/// <summary>
/// Spawn the requested number of 
/// gordos and randomly set their position
/// </summary>
/// <param name="numOfGordos"></param>
void Game::generateGordo(int numOfGordos) {
	
	sf::Vector2f pos;
	sf::Texture gordo;
	if (!t_gordo.loadFromFile("assets/gordo.png"))
		sf::err() << "Error: The file is not found!" << std::endl;


	// Load the sprites into the vector
	for (int i = 1; i < numOfGordos; i++)
	{
		sf::RectangleShape gordoObj;
		gordoObj.setTexture(&t_gordo);
		gordoObj.setSize(sf::Vector2f(64, 64));
		gordoObj.setOrigin(32,32);
		pos = getRandomPosition(0, 0, 780, 0);
		gordoObj.setPosition(pos);
		m_listOfGordos.push_back(gordoObj);
	}

}


/// <summary>
/// Animate the gordos
/// </summary>
void Game::animate() {

	if (m_clock.getElapsedTime().asSeconds() > .3f) {
		for (int i = 0; i < m_listOfGordos.size(); i++)
		{
			sf::Vector2f scale = m_listOfGordos[i].getScale();
			m_listOfGordos[i].setScale(-scale.x, scale.y);
			m_clock.restart();
		}
	}
}

/// <summary>
/// Main game logic
/// </summary>
Game::Game() {

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

	
	sf::Texture texture;
	// Load the sprites into the vector
	for (int i = 1; i < 8; i++)
	{
		if (!texture.loadFromFile("assets/item" + std::to_string(i) + ".png"))
			sf::err() << "Error: The file is not found!" << std::endl;
		t_items.push_back(texture);
	}

	// create the targets random pos
	b2Vec2 m_box2DTarget = getTargetPosition();
	// Give it 64x64 size	
	m_targetShape.setSize(sf::Vector2f(64, 64));
	m_targetShape.setTexture(&t_items[randomNumber()]);

	// Object Sizes
	m_leftWall.setSize(sf::Vector2f(-20, 800));
	m_rightWall.setSize(sf::Vector2f(20, 800));
	m_floor.setSize(sf::Vector2f(800, 60));
	m_ceiling.setSize(sf::Vector2f(800, 20));
	
	if (!t_gameUI.loadFromFile("assets/floor.png"))
		sf::err() << "Error: The file is not found!" << std::endl;	
	m_floor.setTexture(&t_gameUI);

	// Set their respective position
	m_leftWall.setPosition(Box2DToSFML(box2DLWall));
	m_rightWall.setPosition(Box2DToSFML(box2DRWall));
	m_ceiling.setPosition(Box2DToSFML(box2DCeiling));
	m_targetShape.setPosition(Box2DToSFML(m_box2DTarget));
	m_floor.setPosition(Box2DToSFML(box2DFloorPos));

	// Load full health icon
	if (!t_health.loadFromFile("assets/health.png"))
		sf::err() << "Error: The file is not found!" << std::endl;
	
	m_healthRect.setTexture(&t_health);
	m_healthRect.setSize(sf::Vector2f(21, 18));
	m_healthRect.setTextureRect(sf::IntRect(0, 0, 22, 18));
	m_healthRect.setOrigin(sf::Vector2f(m_healthRect.getSize().x / 2, m_healthRect.getSize().y / 2));

}


/// <summary>
/// Retreive a random position 
/// </summary>
/// <param name="minX"></param>
/// <param name="minY"></param>
/// <param name="maxX"></param>
/// <param name="maxY"></param>
/// <returns>Returns a random vector 2 position</returns>
sf::Vector2f Game::getRandomPosition(float minX, float minY, float maxX, float maxY) {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<float> xDist(minX, maxX);
	std::uniform_real_distribution<float> yDist(minY, maxY);
	float x = xDist(gen);
	float y = yDist(gen);
	return sf::Vector2f(x, y);
}


std::vector<sf::RectangleShape>& Game::getListOfEnemies() {
	return m_listOfGordos;
}






/// <summary>
/// Checks for collision between the player and enemies
/// </summary>
/// <param name="playerRect"></param>
void Game::enemyCollision(sf::RectangleShape& playerRect, bool* gameOver) {

	int numOfHearts = m_listOfHearts.size() -1;
	bool isInvincible = false; // flag to indicate if the player is currently invincible

	for (int i = 0; i < m_listOfGordos.size(); i++)
	{
		if (m_listOfGordos[i].getGlobalBounds().intersects(playerRect.getGlobalBounds()))
		{
			*gameOver = false;
		}
	}
}