#pragma once
#include <GravitySnake.h>
#define SFML_STATIC
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Functions.h"

class Game
{
private:
    b2Vec2 m_box2DTarget;
    std::vector<sf::Texture> m_items;
    sf::RectangleShape m_leftWall;
    sf::RectangleShape m_rightWall;
    sf::RectangleShape m_floor;
    sf::RectangleShape m_ceiling;
    sf::RectangleShape m_targetShape;
    sf::Texture m_gameUI;
    sf::Sprite s_background;
    sf::Texture t_background;

public:
    //Game();
    void moveBackground(float backgroundSpeed);
    void createObjects();
    void randomPos();
    void drawObjects(sf::RenderWindow& window, bool spawn);
    void setNewItem();

};

