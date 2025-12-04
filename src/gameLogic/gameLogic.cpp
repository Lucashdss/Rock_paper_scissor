#include <iostream>
#include <thread>
#include "raylib.h"
#include "player/player.hpp"
#include "player/cpuEnemy/cpuEnemy.hpp"
#include "animation/animation.hpp"
#include "animation/animationEnemy.hpp"
#include "gameLogic/gameLogic.hpp"

void GameLogic::updateCountDownText()
{
    if (countDown)
    CountDownText = std::to_string(*countDown);
};

void GameLogic::MakeThreadSleepAndCountDown(){
    if (countDown != nullptr && *countDown > 0)
        {
            std::this_thread::sleep_for(1000ms);
            (*countDown)--;
        }
};

void GameLogic::DrawCountDownText(){
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

void GameLogic::drawPlayerMoveAnimation(int &playerMoveIndex, Animation& HandSigns){
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

void GameLogic::drawEnemyMoveAnimation(int &EnemyMoveIndex, AnimationEnemy& HandSignsEnemy){
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

int GameLogic::CheckWhoWins(int &player1, int &player2){
    int result = (3 + player1 - player2) % 3;
    return result;
};

void GameLogic::PrintBlankSpaces(int lines){
    for (int i = 0; i < lines; i++){
        std::cout << std::endl;
    }
};

bool GameLogic::PlayerWantsToPlayAgain() {
    char choice;
    std::cout << "Do you want to play again? (y/n): ";
    std::cin >> choice;
    return (choice == 'y' || choice == 'Y');
};

bool GameLogic::RunGameLoop(){

    Texture background = LoadTexture("assets/background.png");
    std::unique_ptr<Animation> HandSigns = std::make_unique<Animation>();
    std::unique_ptr<AnimationEnemy> HandSignsEnemy = std::make_unique<AnimationEnemy>();
    std::unique_ptr<player> Player = std::make_unique<player>();
    std::unique_ptr<cpuEnemy> CpuEnemy = std::make_unique<cpuEnemy>();

    PrintBlankSpaces(50);
    Player->playerInput();
    int playerMoveIndex = Player->getMoveIndex();
    int EnemyMoveIndex = CpuEnemy->generateRandomMoveIndex();

    while (!WindowShouldClose())
    {
    
        if (CountEachFrame > 400) {
            CountDownValue = 4;
            countDown = &CountDownValue;
            CountEachFrame = 0;
            HandSigns->ResetAnimationFrames(playerMoveIndex);
            HandSignsEnemy->ResetAnimationFrames(EnemyMoveIndex);
            break;   
        }

        MakeThreadSleepAndCountDown();
        updateCountDownText();

        BeginDrawing();
        ClearBackground(BLACK);
        DrawTexture(background, 0, 0, WHITE);

        DrawCountDownText();

        if(countDown == nullptr){
            drawPlayerMoveAnimation(playerMoveIndex, *HandSigns);
            drawEnemyMoveAnimation(EnemyMoveIndex, *HandSignsEnemy);
            CountEachFrame++;
        }

        if(CountEachFrame > 150){
            HandSigns->DrawWinner(CheckWhoWins(playerMoveIndex, EnemyMoveIndex));
        }

        EndDrawing();
    };
    UnloadTexture(background);

    PrintBlankSpaces(50);
    return PlayerWantsToPlayAgain();
};