#include "Score.h"
#include "Functions.h"
Score::Score(sf::Font& font, int targetsNeeded, sf::Vector2f position)
    : font(font), targetsNeeded(targetsNeeded)
{
    // Set up score text
    scoreText.setFont(font);
    scoreText.setCharacterSize(45);
    scoreText.setFillColor(sf::Color::Black);
    scoreText.setPosition(position);

    // Set up target text
    targetText.setFont(font);
    targetText.setString("Collect " + std::to_string(targetsNeeded));
    targetText.setCharacterSize(30);
    targetText.setFillColor(sf::Color::Black);
	targetText.move(400, 25);
    GetTextCenter(targetText);

    // Set up box for score
    box.setSize(sf::Vector2f(180, 40));
    box.setOrigin(90, 20);
    box.move(400, 25);
    box.setFillColor(sf::Color::White);
    box.setOutlineThickness(2);
    box.setOutlineColor(sf::Color::Black);

    // Update score text with initial score
    scoreText.setString(formatScore(score));
}

void Score::increaseScore(int amount) {
    score += amount;
    scoreText.setString(formatScore(score));
}

void Score::setScore(int score) {
    this->score = score;
    scoreText.setString(formatScore(score));
}

int Score::getScore() const {
    return score;
}

void Score::setTargetsNeeded(int targetsNeeded) {
    this->targetsNeeded = targetsNeeded;
    targetText.setString("Collect " + std::to_string(targetsNeeded));
}

int Score::getTargetsNeeded() const {
    return targetsNeeded;
}

sf::Text Score::getScoreText() const {
    return scoreText;
}

sf::Text Score::getTargetText() const {
    return targetText;
}

sf::RectangleShape Score::getTargetBox() const {
    return box;
}

std::string Score::formatScore(int score) const {
    std::stringstream ss;
    ss << std::setw(5) << std::setfill('0') << score;
    return ss.str();
}

void Score::drawScore(sf::RenderWindow& window, Score score ) {

    window.draw(score.getTargetBox());
    window.draw(score.getScoreText());
    window.draw(score.getTargetText());
}
