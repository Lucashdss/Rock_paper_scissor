#include "cpuEnemy.hpp"
#include <random>

cpuEnemy::cpuEnemy(): player(){
}

cpuEnemy::~cpuEnemy(){
}

int cpuEnemy::generateRandomMoveIndex(){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(1, 3);

    int randomIndex = distr(gen);
    if (randomIndex != AllowedMoves::Rock || randomIndex != AllowedMoves::Paper || randomIndex != AllowedMoves::Scissors){
        std::cerr << "Generated invalid move index: " << randomIndex << std::endl;
    }
    return randomIndex;
};

void cpuEnemy::setMoveIndex(AllowedMoves index){
    RandomMoveIndex = index;
}

