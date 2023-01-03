#pragma once

#include <string>

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
    static void PrintWarning(const std::string& message) { PrintText("[WARN] " + message , ConsoleColour::YELLOW); }
    static void PrintError(const std::string& message) { PrintText("[ERROR] " + message, ConsoleColour::RED); }
    static void PrintSuccess(const std::string& message) { PrintText("[SUCCESS] " + message, ConsoleColour::GREEN); }

protected:

#if defined(_WIN64)
    /// @details Windows only function to get the console handle
    static HANDLE GetHandle();
#endif

    static void SetConsoleColour(ConsoleColour colour);
    static void ResetConsoleColour();
    
};
