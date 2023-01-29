﻿#pragma once

#include <string>
#include <filesystem>

#if defined(_WIN64)
#include <windows.h>
#endif

enum ConsoleColour
{
   BLACK = 0,
   BLUE,
   GREEN,
   AQUA,
   RED,
   PURPLE,
   YELLOW,
   WHITE,
   GREY,
   LIGHT_BLUE,
   LIGHT_GREEN,
   LIGHT_AQUA,
   LIGHT_RED,
   LIGHT_PURPLE,
   LIGHT_YELLOW,
   BRIGHT_WHITE
};

class Console
{
public:
   static constexpr ConsoleColour DEFAULT_COLOUR = ConsoleColour::BRIGHT_WHITE;

   static void PrintText(const std::string& message, ConsoleColour colour = DEFAULT_COLOUR);

   static void PrintInfo(const std::string& message) { PrintText("[INFO] " + message, ConsoleColour::GREY); }
   static void PrintWarning(const std::string& message) { PrintText("[WARN] " + message, ConsoleColour::YELLOW); }
   static void PrintError(const std::string& message) { PrintText("[ERROR] " + message, ConsoleColour::RED); }
   static void PrintSuccess(const std::string& message) { PrintText("[SUCCESS] " + message, ConsoleColour::GREEN); }

   #if defined(_DEBUG)
   // Method that returns just the filename from a full path
   #  define FILE_NAME std::filesystem::path(__FILE__).filename().string()
   // Uses PrintInfo to print message. Only in debug mode, and stripped out in release mode
   #  define DEBUG_LOG(message) Console::PrintInfo((message))
   // Uses PrintInfo but includes [FileName:LineNumber] at the end of the message. Only in debug mode, and stripped out in release mode
   #  define DEBUG_FULL_LOG(message) Console::PrintInfo(std::string(message) + " [" + std::string(FILE_NAME) + ": " + std::to_string(__LINE__) + "]")
   #else
   // Stripped out in release mode
   #  define DEBUG_LOG(message)
   // Stripped out in release mode
   #  define DEBUG_FULL_LOG(message)
   #endif
   
protected:
   #if defined(_WIN64)
   /// @details Windows only function to get the console handle
   static HANDLE GetHandle();
   #endif

   static void SetConsoleColour(ConsoleColour colour);
   static void ResetConsoleColour();
};