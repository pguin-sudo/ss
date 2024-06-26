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

    if (IS_DEBUG_MODE_ON) {
        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {

                switch (event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::KeyPressed:
                    if (event.key.code == sf::Keyboard::Up)
                        Settings::SetGravityStrength(Settings::GetGravityStrength() + 0.98066f);
                    else if (event.key.code == sf::Keyboard::Down)
                        Settings::SetGravityStrength(Settings::GetGravityStrength() - 0.98066f);

                    if (event.key.code == sf::Keyboard::Right)
                        Settings::SetAmortization(Settings::GetAmortization() + 0.05f);
                    else if (event.key.code == sf::Keyboard::Left)
                        Settings::SetAmortization(Settings::GetAmortization() - 0.05f);

                    if (event.key.code == sf::Keyboard::Space)
                    {
                        game.Update(0.025);

                        
                    }
                    break;
                default:
                    break;
                }

                text.setString("Gravity       ( UP /DOWN):  " + std::to_string(Settings::GetGravityStrength()) + '\n' +
                    "Amortization  (RIGHT/LEFT):  " + std::to_string(Settings::GetAmortization()));

                window.clear();
                window.draw(text);
                window.draw(game);
                window.display();
            }
        }
    }
    else {
        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                switch (event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::KeyPressed:
                    if (event.key.code == sf::Keyboard::Up)
                        Settings::SetGravityStrength(Settings::GetGravityStrength() + 0.98066f);
                    else if (event.key.code == sf::Keyboard::Down)
                        Settings::SetGravityStrength(Settings::GetGravityStrength() - 0.98066f);

                    if (event.key.code == sf::Keyboard::Right)
                        Settings::SetAmortization(Settings::GetAmortization() + 0.05f);
                    else if (event.key.code == sf::Keyboard::Left)
                        Settings::SetAmortization(Settings::GetAmortization() - 0.05f);
                    break;
                default:
                    break;
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
    }
    return 0;
}