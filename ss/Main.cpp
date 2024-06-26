#include <SFML/Graphics.hpp>

#include "Settings.h"
#include "Console.h"
#include "Game.h"


int main() {
    Console console("Main");

    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "SS");
    Game game;

    sf::Clock clock;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            //else if (event.type == sf::Event::KeyPressed) {
            //    if (event.key.code == sf::Keyboard::Left)
            //        game.Move(Direction::Left);
            //    else if (event.key.code == sf::Keyboard::Right)
            //        game.Move(Direction::Right);
            //    else if (event.key.code == sf::Keyboard::Up)
            //        game.Move(Direction::Up);
            //    else if (event.key.code == sf::Keyboard::Down)
            //        game.Move(Direction::Down);
            //}
        }

        float deltaTime = clock.restart().asSeconds();;

        game.Update(deltaTime);

        window.clear();
        window.draw(game);
        window.display();
    }

    return 0;
}