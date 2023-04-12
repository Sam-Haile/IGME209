#pragma once
#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>

class Kirby {
public:
    Kirby();
    void playerUpdate();
    void move();
    void draw(sf::RenderWindow& window) const;
    sf::RectangleShape& getPlayerRect();
private:
    b2Body* m_body;
    sf::RectangleShape m_shape;
    sf::Texture m_texture;
    int m_spritePos = 0;
    sf::Clock m_clock;
};
