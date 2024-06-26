#include "Settings.h"

const bool IS_DEBUG_MODE_ON = false;

const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;
const int FRAMERATE = 75;

const int NUM_CIRCLES = 128;
const float PHYSICS_MARGIN = 50.f;

float Settings::gravityStrength = 9.806601f;
float Settings::amortization = 0.9f;

Settings::Settings()
{
    if (!font.loadFromFile("assets/RubikMonoOne.ttf"))
    {
        Console("Settings").Print("No font found in \"assets/RubikMonoOne.ttf\"", MessageType::FATAL);
    }
}

sf::Font& Settings::GetFont()
{
    return font;
}

float Settings::GetGravityStrength()
{
    return gravityStrength;
}

float Settings::GetAmortization()
{
    return amortization;
}

void Settings::SetGravityStrength(float value)
{
    gravityStrength = value;
}

void Settings::SetAmortization(float value)
{
    amortization = value;
}