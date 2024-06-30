#include <SFML/Graphics.hpp>

#include "Settings.h"
#include "Console.h"
#include "Game.h"


int main() {
	sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Spheres Sandbox");

	Game game;
	Settings settings;
	Console console("Main");

	sf::Text text("", settings.GetFont(), 15);
	text.setFillColor(sf::Color(240, 240, 240));
	text.setPosition(50.f, 1.5f);

	sf::Clock clock;

	float& r_gravitational_acceleration = Settings::GetGravityStrength().y;
	float& r_amortization = Settings::GetAmortization();
	bool& r_debug_mode = Settings::GetDebugMode();

	Vector2* p_new_circle_pos = nullptr;

	while (window.isOpen()) {

		float deltaTime = clock.restart().asSeconds();

		sf::Event event;
		while (window.pollEvent(event)) {
			switch (event.type) {
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::KeyPressed:
				if (event.key.code == sf::Keyboard::Up) {
					float old = r_gravitational_acceleration;
					Settings::SetGravityStrength(Vector2(0.f, old + 0.98066f));
					console.Print("Gravity strength has been changed from " + std::to_string(old) + " to " + std::to_string(r_gravitational_acceleration), MessageType::DEBUG);
				}
				else if (event.key.code == sf::Keyboard::Down) {
					float old = r_gravitational_acceleration;
					Settings::SetGravityStrength(Vector2(0.f, old - 0.98066f));
					console.Print("Gravity strength has been changed from " + std::to_string(old) + " to " + std::to_string(r_gravitational_acceleration), MessageType::DEBUG);
				}
				else if (event.key.code == sf::Keyboard::Right) {
					float old = r_amortization;
					Settings::SetAmortization(old + 0.05f);
					console.Print("Amortization has been changed from " + std::to_string(old) + " to " + std::to_string(r_amortization), MessageType::DEBUG);
				}
				else if (event.key.code == sf::Keyboard::Left) {
					float old = r_amortization;
					Settings::SetAmortization(old - 0.05f);
					console.Print("Amortization has been changed from " + std::to_string(old) + " to " + std::to_string(r_amortization), MessageType::DEBUG);
				}
				else if (event.key.code == sf::Keyboard::E) {
					Settings::SetDebugMode(!r_debug_mode);
					console.Print("Debug mode has been changed from " + std::to_string(!r_debug_mode) + " to " + std::to_string(r_debug_mode), MessageType::DEBUG);
				}
				else if (event.key.code == sf::Keyboard::R) {
					game = Game();
					console.Print("New game created", MessageType::INFO);
				}
				else if (event.key.code == sf::Keyboard::Space && r_debug_mode) {
					game.Update(0.025f);
				}
				break;
			case sf::Event::MouseButtonPressed:
				if (event.key.code == sf::Mouse::Right) {
					auto new_circle = Random::GetInstance().GetRandomCircle();
					p_new_circle_pos = &new_circle.position;
					game.physicsEngine->AddCircle(new_circle);
					*p_new_circle_pos = Vector2(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y);
				}
			case sf::Event::MouseButtonReleased:
				if (event.key.code == sf::Mouse::Right) {
					p_new_circle_pos = nullptr;
				}
			case sf::Event::MouseMoved:
				if (p_new_circle_pos != nullptr ) {
					*p_new_circle_pos = Vector2(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y);
				}
				break;
			default:
				break;
			}
		}

		if (!r_debug_mode) {
			game.Update(deltaTime);
		}

		text.setString("Gravity       ( UP /DOWN):  " + std::to_string(r_gravitational_acceleration) + "          Debug mode (E): " + std::to_string(r_debug_mode) + '\n' +
			"Amortization  (RIGHT/LEFT):  " + std::to_string(r_amortization) + "                Delta time: " + std::to_string(deltaTime));

		window.clear();
		window.draw(text);
		window.draw(game);
		window.display();
	}

	return 0;
}