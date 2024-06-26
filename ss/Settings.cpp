#include "Settings.h"

Settings::Settings()
{
    if (!font.loadFromFile("assets/calibri.ttf"))
    {
        Console("Settings").Print("No font found in \"assets/calibri.ttf\"", MessageType::FATAL);
    }
}

sf::Font& Settings::GetFont()
{
    return font;
}
