#ifndef CONSOLE_H
#define CONSOLE_H

#include <string>
#include <iostream>

enum class MessageType { INFO = 0, DEBUG = 1, ERROR = 2, FATAL = 3 };

class Console : std::string
{
protected:
	std::string author;
public:
	Console(std::string author);
	void Print(std::string msg, MessageType msgType);
};
#endif