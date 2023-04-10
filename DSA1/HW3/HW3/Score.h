#pragma once
#include <sstream>
#include <iomanip>
#define SFML_STATIC
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class Score {
public:
    Score(sf::Font& font, int targetsNeeded, sf::Vector2f position);

    void increaseScore(int amount);
    void setScore(int score);
    int getScore() const;

    void setTargetsNeeded(int targetsNeeded);
    int getTargetsNeeded() const;
    void formatScoree(std::stringstream ss);

    sf::Text getScoreText() const;
    sf::Text getTargetText() const;
    sf::RectangleShape getTargetBox() const;
    void drawScore(sf::RenderWindow& window, Score score);

private:
    sf::Font& font;
    int score = 0;
    int targetsNeeded = 0;
    sf::Text scoreText;
    sf::Text targetText;
    sf::RectangleShape box;
    std::string formatScore(int score) const;
};

