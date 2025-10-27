#include <iostream>
#include "player/player.hpp"
#include "cpuEnemy/cpuEnemy.hpp"

int main(){

    player testPlayer;
    cpuEnemy testcpu;

    testPlayer.setMoveIndex(2);
    std::cout << testPlayer.getMoveIndex(); 

    int RandomMove = testcpu.generateRandomMoveIndex();
    std::cout << "\nCPU Move Index: " << RandomMove;
    return 0;
}