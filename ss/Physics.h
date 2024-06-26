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

    Circle(Vector2 position, Vector2 velocity, float mass, int radius, sf::Color color);
    void ApplyForce(const Vector2& force, const float& deltaTime);
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
};
#endif
