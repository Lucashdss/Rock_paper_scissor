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
void drawPlayerMoveAnimation(int &playerMoveIndex, Animation& HandSigns);
void drawEnemyMoveAnimation(int &EnemyMoveIndex, AnimationEnemy& HandSignsEnemy);
int CheckWhoWins(int &playerMoveIndex, int &EnemyMoveIndex);

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
    std::unique_ptr<cpuEnemy> CpuEnemy = std::make_unique<cpuEnemy>();

    Player->playerInput();
    int playerMoveIndex = Player->getMoveIndex();
    int EnemyMoveIndex = CpuEnemy->generateRandomMoveIndex();
    
    CheckWhoWins(playerMoveIndex, EnemyMoveIndex);

    while (!WindowShouldClose())
    {
        MakeThreadSleepAndCountDown();
        updateCountDownText();

        BeginDrawing();
        ClearBackground(BLACK);
        DrawTexture(background, 0, 0, WHITE);

        DrawCountDownText();

        if(countDown == nullptr){
            drawPlayerMoveAnimation(playerMoveIndex, *HandSigns);
            drawEnemyMoveAnimation(EnemyMoveIndex, *HandSignsEnemy);
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

void drawPlayerMoveAnimation(int &playerMoveIndex, Animation& HandSigns){
    if (playerMoveIndex == 1){
        DrawTexturePro(HandSigns.DrawRockAnimation(),
                    HandSigns.sourceRec,
                    HandSigns.destRec,
                    {0,0},
                    0.f,
                    WHITE);
    }
    else if (playerMoveIndex == 2){
        DrawTexturePro(HandSigns.DrawPaperAnimation(),
                    HandSigns.sourceRec,
                    HandSigns.destRec,
                    {0,0},
                    0.f,
                    WHITE);
    }
    else if (playerMoveIndex == 3){
        DrawTexturePro(HandSigns.DrawScissorsAnimation(),
                    HandSigns.sourceRec,
                    HandSigns.destRec,
                    {0,0},
                    0.f,
                    WHITE);
    }
};

void drawEnemyMoveAnimation(int &EnemyMoveIndex, AnimationEnemy& HandSignsEnemy){
    int positionX = 200;
    int positionY = 200;
    
    if (EnemyMoveIndex == 1){
        DrawTexture(HandSignsEnemy.DrawRockAnimation(), positionX, positionY, WHITE);
    }
    else if (EnemyMoveIndex == 2){
        DrawTexture(HandSignsEnemy.DrawPaperAnimation(), positionX, positionY, WHITE);
    }
    else if (EnemyMoveIndex == 3){
        DrawTexture(HandSignsEnemy.DrawScissorsAnimation(), positionX, positionY, WHITE);
    }
};

int CheckWhoWins(int &player1, int &player2){
    int result = (3 + player1 - player2) % 3;

    if (result == 0)
        std::cout << "Draw!\n";
    else if (result == 1)
        std::cout << "Player 1 wins!\n";
    else
        std::cout << "Player 2 wins!\n";

    return result;
};