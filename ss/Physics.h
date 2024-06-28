#ifndef PHYSICS_H
#define PHYSICS_H

#include <vector>
#include <algorithm>
#include <SFML/Graphics.hpp>

#include "Settings.h"
#include "Vector2.h"

struct Circle {
	Vector2 position;
	Vector2 velocity;
	float mass;
	int radius;
	sf::Color color;
	bool is_static;

	Circle(Vector2 position, Vector2 velocity, float mass, int radius, sf::Color color, bool is_static);

	void ApplyForce(const Vector2& force);
	void ApplyImpulse(const Vector2& impulse);
	void ApplyOffset(const Vector2& offset);

	void Update(const float& deltaTime);
};

class Engine {
public:
	Engine();
	~Engine();

	void AddCircle(const Circle& circle);
	std::vector<Circle>& GetCircles() const;
	void Update(const float& deltaTime);
private:
	std::vector<Circle> circles;

	Vector2& r_gravitational_acceleration = Settings::GetGravityStrength();
	float& r_amortization = Settings::GetAmortization();
	bool& r_debug_mode = Settings::GetDebugMode();
};
#endif
