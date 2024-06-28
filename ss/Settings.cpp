#include "Settings.h"

const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;
const int FRAMERATE = 75;

const int NUM_CIRCLES = 100;
const float PHYSICS_MARGIN = 50.f;

Vector2 Settings::gravityStrength = Vector2(0, 9.806601f);
float Settings::amortization = 0.9f;
bool Settings::debug_mode = false;

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

Vector2& Settings::GetGravityStrength()
{
	return gravityStrength;
}

float& Settings::GetAmortization()
{
	return amortization;
}

bool& Settings::GetDebugMode()
{
	return debug_mode;
}

void Settings::SetGravityStrength(Vector2 value)
{
	gravityStrength = value;
}

void Settings::SetAmortization(float value)
{
	amortization = value;
}

void Settings::SetDebugMode(bool value)
{
	debug_mode = value;
}