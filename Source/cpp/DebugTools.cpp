#include "DebugTools.h"
#include <iostream>
#include <stdlib.h>
/// @brief To output the debug information.
/// @param text
/// @param messageType
void LightMC::DebugTools::DebugOutput(const char *text, MsgType messageType)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    switch (messageType)
    {
    case MsgType::Error:
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
        std::cout << text << std::endl;
        break;
    case MsgType::Normal:
        SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY);
        std::cout << text << std::endl;
        break;
    default:
        break;
    }
}
/// @brief To output the debug information.
/// @param text
/// @param messageType
void LightMC::DebugTools::DebugOutput(unsigned char *text, MsgType messageType)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    switch (messageType)
    {
    case MsgType::Error:
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
        std::cout << text << std::endl;
        break;
    case MsgType::Normal:
        SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY);
        std::cout << text << std::endl;
        break;
    default:
        break;
    }
}
/// @brief To initialize the debug tools.
void LightMC::DebugTools::DebugToolsInitialize()
{
    std::system("CLS");
}
///@brief To output the debug information.
/// @param text
/// @param messageType
void LightMC::DebugTools::DebugOutput(std::string text, MsgType messageType)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    switch (messageType)
    {
    case MsgType::Error:
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
        std::cout << text << std::endl;
        break;
    case MsgType::Normal:
        SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY);
        std::cout << text << std::endl;
        break;
    default:
        break;
    }
}