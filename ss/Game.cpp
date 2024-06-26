#include "Game.h"

Game::Game()
{
    physicsEngine = new Engine;
    Init();
}

void Game::Init()
{
    std::random_device rd;
    std::mt19937 gen(rd()); 

    std::uniform_real_distribution<float> posX(100.0f, SCREEN_WIDTH - 100.0f);  
    std::uniform_real_distribution<float> posY(100.0f, SCREEN_HEIGHT - 100.0f);
    std::uniform_real_distribution<float> velX(-50.0f, 50.0f);  
    std::uniform_real_distribution<float> velY(-50.0f, 50.0f);  
    std::uniform_int_distribution<int> radius(10, 20);     
    std::uniform_int_distribution<int> color(0, 9);       

    for (int i = 0; i < NUM_CIRCLES; ++i)
    {
        auto radius_v = radius(gen);
        Circle p({ posX(gen), posY(gen) }, { velX(gen), velY(gen) }, (float)(2*3.14f*std::pow(radius_v, 2)), radius_v, PASTEL_COLOR[color(gen)]);

        physicsEngine->AddCircle(p);
    }
}

void Game::Update(float deltaTime)
{
    physicsEngine->Update(deltaTime);
}

void Game::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    auto circles = physicsEngine->GetCircles();

    for (size_t i = 0; i < circles.size(); ++i) {
        const Circle& circle = circles[i];
        const sf::Color& color = circle.color;

        sf::CircleShape shape(circle.radius-2.f);
        shape.setPosition(circle.position.x-circle.radius, circle.position.y-circle.radius);
        shape.setOutlineThickness(4.f);
        shape.setFillColor(color - sf::Color(0, 0, 0, 128));
        shape.setOutlineColor(color);
        target.draw(shape, states);
    }

    sf::RectangleShape border({ (float)SCREEN_WIDTH - PHYSICS_MARGIN * 2, (float)SCREEN_HEIGHT - PHYSICS_MARGIN * 2});
    border.setPosition(PHYSICS_MARGIN, PHYSICS_MARGIN);
    border.setOutlineThickness(4.f);
    border.setOutlineColor(sf::Color(240, 240, 240));
    border.setFillColor(sf::Color::Transparent);
    target.draw(border, states);
}