#include <SFML/Graphics.hpp>

#include "Settings.h"
#include "Console.h"
#include "Game.h"


int main() {
    Console console("Main");

    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "SS");
    Game game;

    Settings settings;

    // Текст с обозначением клавиш
    sf::Text text("", settings.GetFont(), 15);
    text.setFillColor(sf::Color(240, 240, 240));
    text.setPosition(50.f, 1.5f);

    sf::Clock clock;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            else if (event.type == sf::Event::KeyPressed) {             
                if (event.key.code == sf::Keyboard::Up)
                    Settings::SetGravityStrength(Settings::GetGravityStrength() + 0.98066f);
                else if (event.key.code == sf::Keyboard::Down)
                    Settings::SetGravityStrength(Settings::GetGravityStrength() - 0.98066f);

                if (event.key.code == sf::Keyboard::Right)
                    Settings::SetAmortization(Settings::GetAmortization() + 0.05f);
                else if (event.key.code == sf::Keyboard::Left)
                    Settings::SetAmortization(Settings::GetAmortization() - 0.05f);
            }
        }

        float deltaTime = clock.restart().asSeconds();;

        game.Update(deltaTime);

        text.setString("Gravity       ( UP /DOWN):  " + std::to_string(Settings::GetGravityStrength()) + '\n' +
                       "Amortization  (RIGHT/LEFT):  " + std::to_string(Settings::GetAmortization()));

        window.clear();
        window.draw(text);
        window.draw(game);
        window.display();
    }

    return 0;
}