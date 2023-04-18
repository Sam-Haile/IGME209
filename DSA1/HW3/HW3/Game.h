#pragma once
#include <GravitySnake.h>
#define SFML_STATIC
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Functions.h"
#include <iostream>
#include <vector>
#include <random>

class Game
{
private:
    // GAME
    sf::Clock m_clock;
    int x_spacing = 300;
    sf::Texture t_gordo;
    sf::Texture t_health;
    sf::Texture t_gameUI;
    b2Vec2 m_box2DTarget;
    sf::Sprite s_background;
    sf::Texture t_background;
    sf::RectangleShape m_floor;
    sf::RectangleShape m_ceiling;
    sf::RectangleShape m_leftWall;
    sf::RectangleShape m_rightWall;
    sf::RectangleShape m_healthRect;
    std::vector<sf::Texture> t_items;
    sf::RectangleShape m_targetShape;
    std::vector<sf::RectangleShape> m_listOfGordos;
    std::vector < sf::RectangleShape*> m_listOfHearts;

public:

    //METHODS FOR THE GAME
    Game();
    void animate();
    void setNewItem();
    void itemRandomPos();
    void generateGordo(int numOfGordos);
    void drawHearts( sf::RenderWindow& window);
    std::vector<sf::RectangleShape>& getListOfEnemies();
    void drawGameObjects(sf::RenderWindow& window, bool spawn);
    void moveObjects(float& backgroundSpeed, float& gordoSpeed);
    void enemyCollision(sf::RectangleShape& playerRect, bool* gameOver);
    sf::Vector2f getRandomPosition(float minX, float minY, float maxX, float maxY);
};