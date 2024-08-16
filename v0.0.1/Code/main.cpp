#include "Game.h"
#include <windows.h>


int main()
{
    Game Engine;
    HWND consoleWindow = GetConsoleWindow();
    ShowWindow(consoleWindow, SW_HIDE);
    
    Engine.run();


    return 0;
}