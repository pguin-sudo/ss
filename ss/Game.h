#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <random>
#include <ctime>
#include <cmath>

#include "Physics.h"
#include "Console.h"

enum class Direction { Left = 0, Right = 1, Up = 2, Down = 3 };

const sf::Color PASTEL_COLOR[10] = {
	sf::Color(255, 209, 220),   // Pastel Pink
	sf::Color(174, 198, 207),   // Pastel Blue
	sf::Color(176, 229, 124),   // Pastel Green
	sf::Color(253, 253, 150),   // Pastel Yellow
	sf::Color(177, 156, 217),   // Pastel Purple
	sf::Color(255, 179, 71),    // Pastel Orange
	sf::Color(255, 105, 97),    // Pastel Red
	sf::Color(175, 238, 238),   // Pastel Turquoise
	sf::Color(230, 230, 250),   // Pastel Lavender
	sf::Color(255, 218, 185)    // Pastel Peach
};

class Game : public sf::Drawable, public sf::Transformable
{
public:
	Engine* physicsEngine;
public:
	Game();
	void Init();
	// void Move(Direction direction);
	void Update(float deltaTime);
public:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};
#endif
