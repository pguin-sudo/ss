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
    for (auto& circle : circles) {
        // Handle wall collisions
        float radius = circle.radius;

        if (circle.position.x - radius < PHYSICS_MARGIN) {
            circle.position.x = radius + PHYSICS_MARGIN;
            circle.velocity.x *= -AMORTISATION;
        }

        if (circle.position.x + radius > SCREEN_WIDTH - PHYSICS_MARGIN) {
            circle.position.x = SCREEN_WIDTH - PHYSICS_MARGIN - radius;
            circle.velocity.x *= -AMORTISATION;
        }

        if (circle.position.y - radius < PHYSICS_MARGIN) {
            circle.position.y = radius + PHYSICS_MARGIN;
            circle.velocity.y *= -AMORTISATION;
        }

        if (circle.position.y + radius > SCREEN_HEIGHT - PHYSICS_MARGIN) {
            circle.position.y = SCREEN_HEIGHT - PHYSICS_MARGIN - radius;
            circle.velocity.y *= -AMORTISATION;
        }

        //// Handle circle collisions
        //for (Circle& otherCircle : circles) {
        //    if (&circle == &otherCircle) {
        //        continue;
        //    }

        //    float distanceSq = Vector2::DistanceSq(circle.position, otherCircle.position);
        //    float collisionDistance = circle.radius + otherCircle.radius;

        //    if (distanceSq < collisionDistance * collisionDistance) {
        //        Vector2 normal = Vector2::Normalize(otherCircle.position - circle.position);
        //        Vector2 relativeVelocity = otherCircle.velocity - circle.velocity;
        //        float dotProduct = Vector2::Dot(relativeVelocity, normal);

        //        float impulseMag = (2.0f * dotProduct) / (circle.mass + otherCircle.mass);

        //        // Apply impulse
        //        Vector2 impulse = normal * impulseMag;

        //        circle.velocity += impulse / circle.mass;
        //        otherCircle.velocity -= impulse / otherCircle.mass;

        //        // Separate the circles to avoid overlap
        //        float overlap = collisionDistance - sqrt(distanceSq);
        //        circle.position -= normal * overlap * 0.5f;
        //        otherCircle.position += normal * overlap * 0.5f;
        //    }
        //}

        // Handle gravity
        Vector2 gravity = { 0, GRAVITY_STRENGTH * circle.mass };
        circle.ApplyForce(gravity, deltaTime);

        // Update circle position based on velocity
        circle.Update(deltaTime);
    }
}
