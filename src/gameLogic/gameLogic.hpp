#include "player/player.hpp"
#include "player/cpuEnemy/cpuEnemy.hpp"
#include "animation/animation.hpp"
#include "animation/animationEnemy.hpp"

class GameLogic {
    private:
    int CountDownValue = 4;
    int *countDown = &CountDownValue;
    std::string CountDownText;
    int CountEachFrame{};

    public:
    void updateCountDownText();
    void MakeThreadSleepAndCountDown();
    void DrawCountDownText();
    void drawPlayerMoveAnimation(int &playerMoveIndex, Animation& HandSigns);
    void drawEnemyMoveAnimation(int &EnemyMoveIndex, AnimationEnemy& HandSignsEnemy);
    int CheckWhoWins(int &playerMoveIndex, int &EnemyMoveIndex);
    void PrintBlankSpaces(int lines);
    bool PlayerWantsToPlayAgain();
    bool RunGameLoop();
};