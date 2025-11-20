#include <iostream>
#include <thread>
#include "player/player.hpp"
#include "player/cpuEnemy/cpuEnemy.hpp"
#include "animation/animation.hpp"
#include "raylib.h"

int *countDown = new int(4);

int main()
{
    InitWindow(800, 600, "My Game");
    SetTargetFPS(60);

    Texture background = LoadTexture("assets/background.png");
    std::unique_ptr<Animation> HandSigns = std::make_unique<Animation>();

    while (!WindowShouldClose())
    {
        if (*countDown > 0)
        {
            std::this_thread::sleep_for(1000ms);
            (*countDown)--;
        }

        BeginDrawing();
        ClearBackground(BLACK);
        DrawTexture(background, 0, 0, WHITE);

        std::string CountDownText = std::to_string(*countDown);
        int fontSize = 100;
        int textWidth = MeasureText(CountDownText.c_str(), fontSize);

        if (*countDown > 0)
            DrawText(CountDownText.c_str(), (800 - textWidth) / 2, (600 - fontSize) / 2, fontSize, WHITE);
        else if (*countDown == 0)
        {
            DrawText("Go!", (800 - textWidth) / 2, (600 - fontSize) / 2, fontSize, WHITE);
            delete countDown;
        }

        EndDrawing();
    };
    UnloadTexture(background);
    CloseWindow();
    return 0;
}