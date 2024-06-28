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
	std::uniform_real_distribution<float> velocity_x(-50.0f, 50.0f);
	std::uniform_real_distribution<float> velocity_y(-50.0f, 50.0f);
	std::uniform_int_distribution<int> radius(10, 20);
	std::uniform_int_distribution<int> color(0, 9);

	for (int i = 0; i < NUM_CIRCLES; ++i)
	{
		int radius_v = radius(gen);
		Circle p({ posX(gen), posY(gen) }, Vector2(velocity_x(gen), velocity_y(gen)), (float)(4 * 3.14f * std::pow(radius_v, 3)), radius_v, PASTEL_COLOR[color(gen)], false);

		physicsEngine->AddCircle(p);
	}

	// int radius_v = 100;
	// Circle p({ float(SCREEN_WIDTH/2), float(SCREEN_HEIGHT / 2) }, Vector2(0.f, 0.f), float(4 * 3.14f * std::pow(radius_v, 3)), radius_v, PASTEL_COLOR[0], true);

	// physicsEngine->AddCircle(p);
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