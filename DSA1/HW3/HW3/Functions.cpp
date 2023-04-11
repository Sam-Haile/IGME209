#include "Functions.h"

using namespace std;

void display(b2Body* snake)
{
	cout << "Target: (" << getTargetPosition().x << ", " << getTargetPosition().y << ")  ";
	cout << "Snake: (" << snake->GetPosition().x << ", " << snake->GetPosition().y << ")  " << endl;
}

void handleInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		applyForceToSnake(b2Vec2(0.0f, 100000.0f));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		applyForceToSnake(b2Vec2(-10000.0f, 0.0f));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		applyForceToSnake(b2Vec2(10000.0f, 0.0f));
	}
}

int randomNumber() 
{
	// Seed the random number generator with the current time
	srand(time(NULL));

	// Generate a random number between 1 and 6
	int randomNumber = rand() % 6 + 1;

	// Return the random number
	return randomNumber;

}

/// <summary>
/// Converts pixel based coordinates (SFML) 
/// to metric based coordinates (Box2D)
/// </summary>
/// <param name="vec"></param>
/// <returns>A vector 2 in Box2Ds coordinate system</returns>
b2Vec2 SFMLToBox2D(const sf::Vector2f& vec)
{
	return b2Vec2(vec.x / 100.0f, -vec.y / 100.0f);
}

/// <summary>
/// Converts metric based coordinates (Box2D) 
/// to pixel based coordinates (SFML)
/// </summary>
/// <param name="vec"></param>
/// <returns>A vector 2 in SFMLs coordinate system</returns>
sf::Vector2f Box2DToSFML(const b2Vec2& vec)
{
	// Convert SFML vector to Box2D position with the proper scale
	return sf::Vector2f(vec.x * 100.0f, vec.y * -100.0f);
}

/// <summary>
/// Gets the center point of a textbox
/// </summary>
/// <param name="text"></param>
void GetTextCenter(sf::Text& text)
{
	sf::FloatRect bounds = text.getLocalBounds(); // get the local bounds of the text
	text.setOrigin(bounds.left + bounds.width / 2.0f, bounds.top + bounds.height / 2.0f);
}
