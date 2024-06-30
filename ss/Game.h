#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <random>
#include <ctime>
#include <cmath>

#include "Physics.h"
#include "Console.h"
#include "Random.h"

enum class Direction { Left = 0, Right = 1, Up = 2, Down = 3 };

class Game : public sf::Drawable, public sf::Transformable
{
public:
	Engine* physicsEngine;
public:
	Game();
	void Init();
	void Update(float deltaTime);
public:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};
#endif
