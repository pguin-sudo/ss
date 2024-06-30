#include "Game.h"


Game::Game()
{
	physicsEngine = new Engine;
	Init();
}

void Game::Init()
{
	for (int i = 0; i < NUM_CIRCLES; ++i)
	{
		physicsEngine->AddCircle(Random::GetInstance().GetRandomCircle());
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

		sf::CircleShape shape(circle.radius - 4.f);
		shape.setPosition(circle.position.x - circle.radius, circle.position.y - circle.radius);
		shape.setOutlineThickness(4.f);
		shape.setFillColor(color - sf::Color(0, 0, 0, 128));
		shape.setOutlineColor(color);
		target.draw(shape, states);
	}

	sf::RectangleShape border({ (float)SCREEN_WIDTH - PHYSICS_MARGIN * 2, (float)SCREEN_HEIGHT - PHYSICS_MARGIN * 2 });
	border.setPosition(PHYSICS_MARGIN - 4.f, PHYSICS_MARGIN - 4.f);
	border.setOutlineThickness(4.f);
	border.setOutlineColor(sf::Color(240, 240, 240));
	border.setFillColor(sf::Color::Transparent);
	target.draw(border, states);
}