#include <iostream>
#include "player/player.hpp"
#include "cpuEnemy/cpuEnemy.hpp"

int main(){

    player testPlayer;
    cpuEnemy testcpu;

    testPlayer.setMoveIndex(testPlayer.Paper);
    std::cout << testPlayer.getMoveIndex(); 

    int RandomMove = testcpu.generateRandomMoveIndex();
    std::cout << "\nCPU Move Index: " << RandomMove;
    return 0;
}
