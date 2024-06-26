#include "Physics.h"

// Circle

Circle::Circle(Vector2 position, Vector2 velocity, float mass, int radius, sf::Color color)
    : position(position), velocity(velocity), mass(mass), radius(radius), color(color) {}

void Circle::ApplyForce(const Vector2& force, const float& deltaTime) {
    Vector2 acceleration = force * (10.0f / mass);
    velocity = velocity + acceleration * deltaTime;
}

void Circle::Update(const float& deltaTime) {
    position = position + velocity * deltaTime;
}


// Engine

Engine::Engine() {}

Engine::~Engine() {}

void Engine::AddCircle(const Circle& circle) {
    circles.push_back(circle);
}

std::vector<Circle>& Engine::GetCircles() const {
    return const_cast<std::vector<Circle>&>(circles);
}

void Engine::Update(const float& deltaTime) {
    auto cached_amortization = Settings::GetAmortization();
    auto cached_gravity_strength = Settings::GetGravityStrength();

    for (size_t i = 0; i < circles.size(); ++i) {
        Circle& circle = circles[i];

        // Handle wall collisions
        float radius = circle.radius;

        if (circle.position.x - radius < PHYSICS_MARGIN) {
            circle.position.x = radius + PHYSICS_MARGIN;
            circle.velocity.x *= -cached_amortization;
        }

        if (circle.position.x + radius > SCREEN_WIDTH - PHYSICS_MARGIN) {
            circle.position.x = SCREEN_WIDTH - PHYSICS_MARGIN - radius;
            circle.velocity.x *= -cached_amortization;
        }

        if (circle.position.y - radius < PHYSICS_MARGIN) {
            circle.position.y = radius + PHYSICS_MARGIN;
            circle.velocity.y *= -cached_amortization;
        }

        if (circle.position.y + radius > SCREEN_HEIGHT - PHYSICS_MARGIN) {
            circle.position.y = SCREEN_HEIGHT - PHYSICS_MARGIN - radius;
            circle.velocity.y *= -cached_amortization;
        }

        // Handle circle collisions
        for (size_t j = i + 1; j < circles.size(); ++j) {
            Circle& otherCircle = circles[j];

            if (&otherCircle == &circle) {
                continue;
            }

            float distance = Vector2::Distance(circle.position, otherCircle.position);
            float collisionDistance = circle.radius + otherCircle.radius;

            if (distance < collisionDistance) {
                Vector2 normal = Vector2::Normalize(otherCircle.position - circle.position);
                Vector2 relativeVelocity = otherCircle.velocity - circle.velocity;
                float dotProduct = Vector2::Dot(relativeVelocity, normal);

                if (dotProduct < 0) {
                    float impulseMag = (-(1 + cached_amortization) * dotProduct) /
                        (1 / circle.mass + 1 / otherCircle.mass);

                    // Apply impulse
                    Vector2 impulse = normal * impulseMag;

                    circle.velocity -= impulse / circle.mass;
                    otherCircle.velocity += impulse / otherCircle.mass;

                    // Separate circles to avoid overlap
                    float overlap = collisionDistance - distance;
                    Vector2 separationVector = normal * overlap * 0.5f;

                    circle.position -= separationVector;
                    otherCircle.position += separationVector;
                }
            }
        }

        // Handle gravity
        Vector2 gravity = { 0, cached_gravity_strength * circle.mass };
        circle.ApplyForce(gravity, deltaTime);

        // Update circle position based on velocity
        circle.Update(deltaTime);
    }
}
