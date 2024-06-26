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
        std::cout << "\033[1;37m[INFO]\033[0m " << author << ": " << msg << '\n'; // ����� ����� ���� ��� INFO
        break;
    case MessageType::DEBUG:
        std::cout << "\033[1;36m[DEBG]\033[0m " << author << ": " << msg << '\n'; // ����-�������� ���� ��� DEBUG
        break;
    case MessageType::ERROR:
        std::cout << "\033[1;31m[ERRO]\033[0m " << author << ": " << msg << '\n'; // ����-������� ���� ��� ERROR
        break;
    case MessageType::FATAL:
        std::cout << "\033[1;35m[FATL]\033[0m " << author << ": " << msg << '\n'; // ����-���������� ���� ��� FATAL
        break;
    }
}