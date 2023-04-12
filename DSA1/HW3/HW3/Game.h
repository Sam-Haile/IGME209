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
    b2Vec2 m_box2DTarget;
    std::vector<sf::Texture> m_items;
    std::vector<sf::RectangleShape> m_listOfGordos;
    sf::Texture m_gordo;
    sf::RectangleShape m_leftWall;
    sf::RectangleShape m_rightWall;
    sf::RectangleShape m_floor;
    sf::RectangleShape m_ceiling;
    sf::RectangleShape m_targetShape;
    sf::Texture m_gameUI;
    sf::Sprite s_background;
    sf::Texture t_background;
    sf::Clock m_clock;


public:

    //METHODS FOR THE GAME
    Game();
    void setNewItem();
    void itemRandomPos();
    void enemyCollision(sf::RectangleShape& playerRect);
    void animate();
    void generateGordo(int numOfGordos);
    void moveObjects(float& backgroundSpeed, int numOfGordo);
    void drawGameObjects(sf::RenderWindow& window, bool spawn);
    sf::Vector2f getRandomPosition(float minX, float minY, float maxX, float maxY);
    std::vector<sf::RectangleShape>& getListOfEnemies();
};