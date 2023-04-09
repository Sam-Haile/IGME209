#pragma once
#include <Box2D/Box2D.h>
#define SFML_STATIC
#include "SFML/Window.hpp"
#include "SFML/System.hpp"

#ifdef GRAVITYSNAKE_EXPORTS
#define GRAVITYSNAKE_API __declspec(dllexport)
#else
#define GRAVITYSNAKE_API __declspec(dllimport)
#endif

/// <summary>
/// Initializes the world, and other relevant variables. Must be called before creating bodies.
/// </summary>
/// <param name="gravity">The gravity vector of the physics world.</param>
extern "C" GRAVITYSNAKE_API void initVariables(b2Vec2 gravity);

/// <summary>
/// Frees all variables. Must be called at the end of the program.
/// </summary>
extern "C" GRAVITYSNAKE_API void releaseVariables();

/// <summary>
/// Updates the physics world by deltaTime, and returns the deltaTime in seconds as a float.
/// </summary>
/// <returns>The deltaTime in seconds.</returns>
extern "C" GRAVITYSNAKE_API float updateWorldAndReturnDeltaTime();

/// <summary>
/// Detects collisions between the snake and target based on distance.
/// </summary>
/// <param name="collisionDistance">The maximum distance to trigger a collision.</param>
/// <returns>True if there is a collision, and false otherwise.</returns>
extern "C" GRAVITYSNAKE_API bool checkCollisionAndMoveTarget(float collisionDistance);

/// <summary>
/// Applies an arbitrary force to the snake's center. Note that the force will be scaled by deltaTime internally.
/// </summary>
/// <param name="force">The force to apply.</param>
extern "C" GRAVITYSNAKE_API void applyForceToSnake(b2Vec2 force);

/// <summary>
/// Creates the floor body and returns a pointer to it.
/// </summary>
/// <param name="center">The center point of the body.</param>
/// <param name="halfWidth">The distance from the center to an edge in the X axis. Half the width of the box.</param>
/// <param name="halfHeight">The distance from the center to an edge in the Y axis. Half the height of the box.</param>
extern "C" GRAVITYSNAKE_API void createFloor(b2Vec2 center, float halfWidth, float halfHeight);

/// <summary>
/// Creates the ceiling body and returns a pointer to it.
/// </summary>
/// <param name="center">The center point of the body.</param>
/// <param name="halfWidth">The distance from the center to an edge in the X axis. Half the width of the box.</param>
/// <param name="halfHeight">The distance from the center to an edge in the Y axis. Half the height of the box.</param>
extern "C" GRAVITYSNAKE_API void createCeiling(b2Vec2 center, float halfWidth, float halfHeight);

/// <summary>
/// Creates the right wall body and returns a pointer to it.
/// </summary>
/// <param name="center">The center point of the body.</param>
/// <param name="halfWidth">The distance from the center to an edge in the X axis. Half the width of the box.</param>
/// <param name="halfHeight">The distance from the center to an edge in the Y axis. Half the height of the box.</param>
extern "C" GRAVITYSNAKE_API void createRightWall(b2Vec2 center, float halfWidth, float halfHeight);

/// <summary>
/// Creates the left wall body and returns a pointer to it.
/// </summary>
/// <param name="center">The center point of the body.</param>
/// <param name="halfWidth">The distance from the center to an edge in the X axis. Half the width of the box.</param>
/// <param name="halfHeight">The distance from the center to an edge in the Y axis. Half the height of the box.</param>
extern "C" GRAVITYSNAKE_API void createLeftWall(b2Vec2 center, float halfWidth, float halfHeight);

/// <summary>
/// Creates the snake dynamic body and returns a pointer to it.
/// </summary>
/// <param name="center">The center point of the body's starting position.</param>
/// <param name="halfWidth">The distance from the center to an edge in the X axis. Half the width of the box.</param>
/// <param name="halfHeight">The distance from the center to an edge in the Y axis. Half the height of the box.</param>
/// <returns>A pointer to the b2Body.</returns>
extern "C" GRAVITYSNAKE_API b2Body* createSnake(b2Vec2 center, float halfWidth, float halfHeight);

/// <summary>
/// Gets a copy of the target position.
/// </summary>
/// <returns>A copy of the target position.</returns>
extern "C" GRAVITYSNAKE_API b2Vec2 getTargetPosition();

/// <summary>
/// Sets the min and max values for target X and Y spawn locations.
/// </summary>
/// <param name="minX">The minimum X value for target locations.</param>
/// <param name="maxX">The maximum X value for target locations.</param>
/// <param name="minY">The minimum Y value for target locations.</param>
/// <param name="maxY">The maximum Y value for target locations.</param>
extern "C" GRAVITYSNAKE_API void setTargetBounds(float minX, float maxX, float minY, float maxY);