#include "Console.h"

Console::Console(const std::string author)
{
	this->author = author;
}

void Console::Print(std::string msg, MessageType msgType)
{
	switch (msgType)
	{
	case MessageType::INFO:
		std::cout << "\033[1;37m[INFO]\033[0m " << author << ": " << msg << '\n'; // яркий белый цвет дл€ INFO
		break;
	case MessageType::DEBUG:
		std::cout << "\033[1;36m[DEBG]\033[0m " << author << ": " << msg << '\n'; // ярко-циановый цвет дл€ DEBUG
		break;
	case MessageType::ERROR:
		std::cout << "\033[1;31m[ERRO]\033[0m " << author << ": " << msg << '\n'; // ярко-красный цвет дл€ ERROR
		break;
	case MessageType::FATAL:
		std::cout << "\033[1;35m[FATL]\033[0m " << author << ": " << msg << '\n'; // ярко-фиолетовый цвет дл€ FATAL
		break;
	}
}