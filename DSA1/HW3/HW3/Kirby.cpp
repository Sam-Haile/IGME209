#include "Kirby.h"
#include <GravitySnake.h>
#include "Functions.h"

/// <summary>
/// Main player game logic
/// </summary>
Kirby::Kirby() {
    // Creating Kirby	
    m_body = createSnake(b2Vec2(4.0f, -6.0f), .5f, .5f);
    m_shape.setSize(sf::Vector2f(2 * 100 * 0.5f, 2 * 100 * 0.5f));
    // set the origin of the shape to its center  
    m_shape.setOrigin(m_shape.getSize().x / 2, m_shape.getSize().y / 2);
    if (!m_texture.loadFromFile("assets/Kirby_Float.png"))
        sf::err() << "Error: The file is not found!" << std::endl;
    m_shape.setTexture(&m_texture);
    m_shape.setTextureRect(sf::IntRect(m_spritePos, 0, 24, 24));
}

/// <summary>
/// Animate player
/// </summary>
void Kirby::playerUpdate() {
   
    // Kirbys Movement
    move();

    if (m_clock.getElapsedTime().asSeconds() > .1f) {
        if (m_spritePos == 0)
            m_spritePos = 24;
        else
            m_spritePos = 0;

        m_shape.setTextureRect(sf::IntRect(m_spritePos, 0, 23, 24));
        m_clock.restart();
    }
}

/// <summary>
/// Draws kirby
/// </summary>
/// <param name="window"></param>
void Kirby::draw(sf::RenderWindow& window) const {
    window.draw(m_shape);
}

/// <summary>
/// Moves Kirby
/// </summary>
void Kirby::move() {
    
    // Kirbys Movement
    b2Vec2 kirbyPos = m_body->GetPosition();
    sf::Vector2f kirbyPosSFML = Box2DToSFML(kirbyPos);
    m_shape.setPosition(kirbyPosSFML);
}

sf::RectangleShape& Kirby::getPlayerRect() {
    return m_shape;
}
