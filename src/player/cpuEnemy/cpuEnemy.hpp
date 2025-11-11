#include "player.hpp"
#pragma once

class cpuEnemy : public player{
    public:
        cpuEnemy();
        virtual ~cpuEnemy();
        int generateRandomMoveIndex();
        void setMoveIndex(AllowedMoves index);

    private:
    int RandomMoveIndex;
};