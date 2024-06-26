#ifndef SETTINGS_H
#define SETTINGS_H

#include <SFML/Graphics.hpp>

#include "Console.h"

class Settings
{
private:
    sf::Font font;
    static float physicsMargin;
    static float gravityStrength;
    static float amortization;

public:
    Settings();
    sf::Font& GetFont();
    static float GetGravityStrength();
    static float GetAmortization();
    static void SetGravityStrength(float value);
    static void SetAmortization(float value);
};

extern const bool IS_DEBUG_MODE_ON;

extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;
extern const int FRAMERATE;

extern const int NUM_CIRCLES;
extern const float PHYSICS_MARGIN;

#endif
