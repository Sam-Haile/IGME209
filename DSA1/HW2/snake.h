#pragma once
//initialize methods

/// <summary>
/// continually updates the physics in the game
/// </summary>
/// <param name="world"></param>
/// <param name="deltaClock"></param>
void Update(b2World& world, sf::Clock& deltaClock);

/// <summary>
/// Display the position of the target and the player
/// </summary>
void Display(int& targetX, int& targetY, int& playerX, int& playerY);

/// <summary>
/// Read key presses and apply a force to the player
/// </summary>
void ApplyForces(int keyPress, b2Body* snake);


/// <summary>
/// Moves target to new location
/// </summary>
/// <param name="target"></param>
void MoveTarget(b2Vec2* target);

