#ifndef SETTINGS_H
#define SETTINGS_H

#include <SFML/Graphics.hpp>

#include "Console.h"
#include "Vector2.h"

class Settings
{
private:
	sf::Font font;
	static Vector2 gravityStrength;
	static float amortization;
	static bool debug_mode;

public:
	Settings();
	sf::Font& GetFont();
	static Vector2& GetGravityStrength();
	static float& GetAmortization();
	static bool& GetDebugMode();
	static void SetGravityStrength(Vector2 value);
	static void SetAmortization(float value);
	static void SetDebugMode(bool value);
};

extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;
extern const int FRAMERATE;

extern const int NUM_CIRCLES;
extern const float PHYSICS_MARGIN;

#endif
