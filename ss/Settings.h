#ifndef SETTINGS_H
#define SETTINGS_H

#include <SFML/Graphics.hpp>

#include "Console.h"

class Settings
{
private:
    sf::Font font;
public:
    Settings(); 
    sf::Font& GetFont(); 
};

const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;
const int FRAMERATE = 60;

const int NUM_CIRCLES = 128;

const float PHYSICS_MARGIN = 50.f;
const float GRAVITY_STRENGTH = 9.81f;
const float AMORTISATION = 0.9f;
#endif