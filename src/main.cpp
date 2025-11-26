#include <iostream>
#include <thread>
#include "player/player.hpp"
#include "player/cpuEnemy/cpuEnemy.hpp"
#include "animation/animation.hpp"
#include "animation/animationEnemy.hpp"
#include "raylib.h"

void updateCountDownText();
void MakeThreadSleepAndCountDown();
void DrawCountDownText();

int *countDown = new int(4);
std::string CountDownText;

int main()
{
    InitWindow(800, 600, "My Game");
    SetTargetFPS(60);

    Texture background = LoadTexture("assets/background.png");
    std::unique_ptr<Animation> HandSigns = std::make_unique<Animation>();
    std::unique_ptr<AnimationEnemy> HandSignsEnemy = std::make_unique<AnimationEnemy>();
    std::unique_ptr<player> Player = std::make_unique<player>();

    Player->playerInput();

    while (!WindowShouldClose())
    {
        MakeThreadSleepAndCountDown();
        updateCountDownText();

        BeginDrawing();
        ClearBackground(BLACK);
        DrawTexture(background, 0, 0, WHITE);

        DrawCountDownText();

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

    UnloadTexture(background);
    CloseWindow();

    return 0;
}

void updateCountDownText()
{
    if (countDown)
    CountDownText = std::to_string(*countDown);
};

void MakeThreadSleepAndCountDown(){
    if (countDown != nullptr && *countDown > 0)
        {
            std::this_thread::sleep_for(1000ms);
            (*countDown)--;
        }
    else if (countDown == nullptr)
    {
        delete countDown;
    }
};

void DrawCountDownText(){
    int fontSizeCountdown = 100;
    int textWidth = MeasureText(CountDownText.c_str(), fontSizeCountdown);

    if (countDown != nullptr && *countDown > 0){
        DrawText(CountDownText.c_str(), (800 - textWidth) / 2, (600 - fontSizeCountdown) / 2, fontSizeCountdown, WHITE);
    }
    else if (countDown != nullptr && *countDown == 0)
    {
        DrawText("Go!", (800 - textWidth) / 2, (600 - fontSizeCountdown) / 2, fontSizeCountdown, WHITE);
        countDown = nullptr;
    }
};