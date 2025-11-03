#pragma once
#include <iostream>


class player{
    private:
        int MoveIndex;

    public:
        player();
        virtual ~player();
        int getMoveIndex() const;
        virtual void setMoveIndex(int index);
        void setMoveIndexToZero();
};