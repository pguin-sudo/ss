#define NOMINMAX

#include <stdio.h>
#include <time.h>
#include <windows.h>

#include "SFML/Graphics.hpp"

const int WEIGHT = 1280;
const int HEIGHT = 720;

int main() 
{
	sf::RenderWindow window(sf::VideoMode(WEIGHT, HEIGHT), "SS");
	sf::Event e;

	while (window.isOpen())
	{
		while (window.pollEvent(e))
		{
			if (e.type == sf::Event::Closed) window.close();
		}
	}

	return 0;
}