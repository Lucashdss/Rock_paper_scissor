#include <iostream>
#include <thread>
#include "player/player.hpp"
#include "player/cpuEnemy/cpuEnemy.hpp"
#include "animation/animation.hpp"
#include "animation/animationEnemy.hpp"
#include "raylib.h"

int *countDown = new int(4);

int main()
{
    InitWindow(800, 600, "My Game");
    SetTargetFPS(60);

    Texture background = LoadTexture("assets/background.png");
    std::unique_ptr<Animation> HandSigns = std::make_unique<Animation>();
    std::unique_ptr<AnimationEnemy> HandSignsEnemy = std::make_unique<AnimationEnemy>();


    while (!WindowShouldClose())
    {
        if (countDown != nullptr && *countDown > 0)
        {
            std::this_thread::sleep_for(1000ms);
            (*countDown)--;
        }

        std::string CountDownText = std::to_string(*countDown);
        int fontSize = 100;
        int textWidth = MeasureText(CountDownText.c_str(), fontSize);

        BeginDrawing();
        ClearBackground(BLACK);
        DrawTexture(background, 0, 0, WHITE);

        if (countDown != nullptr && *countDown > 0){
            DrawText(CountDownText.c_str(), (800 - textWidth) / 2, (600 - fontSize) / 2, fontSize, WHITE);
        }
        else if (countDown != nullptr && *countDown == 0)
        {
            DrawText("Go!", (800 - textWidth) / 2, (600 - fontSize) / 2, fontSize, WHITE);
            EndDrawing();
            std::this_thread::sleep_for(1000ms);
            countDown = nullptr;
        }

        if (countDown == nullptr){
            DrawTexturePro(HandSigns->DrawPaperAnimation(),
                        HandSigns->sourceRec,
                        HandSigns->destRec,
                        {0,0},
                        0.f,
                        WHITE);
            DrawTexture(HandSignsEnemy->DrawScissorsAnimation(), 200, 100, WHITE);
        }

        EndDrawing();
    };

    delete countDown;
    UnloadTexture(background);
    CloseWindow();
    return 0;
}