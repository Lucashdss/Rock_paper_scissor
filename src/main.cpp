#include <iostream>
#include <thread>
#include "raylib.h"
#include "gameLogic/gameLogic.hpp"

int main()
{
    InitWindow(800, 600, "Rock Paper Scissors - Raylib C++ Edition");
    SetTargetFPS(60);
    std::unique_ptr<GameLogic> gameLogic = std::make_unique<GameLogic>();

    do{
        if(!gameLogic->RunGameLoop())
            break;
    }
    while (gameLogic->RunGameLoop());
    CloseWindow();
    gameLogic->PrintBlankSpaces(50);
    std::cout << "Thanks for playing! Goodbye!" << std::endl;

    return 0;
}