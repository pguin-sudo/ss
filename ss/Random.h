#ifndef RANDOM_H
#define RANDOM_H

#include <random>
#include "Physics.h"

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

class Random {
public:
    static Random& GetInstance() {
        static Random instance; 
        return instance;
    }

    Circle GetRandomCircle() {
        int radius_v = radius(gen);
        Circle circle({ position_x(gen), position_y(gen) },
            { velocity_x(gen), velocity_y(gen) },
            (float)(4 * 3.14f * std::pow(radius_v, 3)),
            radius_v, PASTEL_COLOR[color(gen)], false);
        return circle;
    }

private:
    Random()
        : rd(), gen(rd()),
        position_x(100.0f, SCREEN_WIDTH - 100.0f),
        position_y(100.0f, SCREEN_HEIGHT - 100.0f),
        velocity_x(-50.0f, 50.0f), velocity_y(-50.0f, 50.0f),
        radius(10, 20), color(0, 9) {
    }

    ~Random() = default;

    Random(const Random&) = delete;
    Random& operator=(const Random&) = delete;

    std::random_device rd;
    std::mt19937 gen;
    std::uniform_real_distribution<float> position_x;
    std::uniform_real_distribution<float> position_y;
    std::uniform_real_distribution<float> velocity_x;
    std::uniform_real_distribution<float> velocity_y;
    std::uniform_int_distribution<int> radius;
    std::uniform_int_distribution<int> color;
};


#endif