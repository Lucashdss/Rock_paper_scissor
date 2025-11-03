#include "player.hpp"
#pragma once

class cpuEnemy : public player{
    public:
        cpuEnemy();
        virtual ~cpuEnemy();
        int generateRandomMoveIndex();
        virtual void setMoveIndex(int index) override;

    private:
    int RandomMoveIndex;
};