#pragma once
#include <iostream>


class player{
    private:
        int MoveIndex;

    public:
        enum AllowedMoves 
        {
            Rock = 1,
            Paper,
            Scissors
        };

        player();
        virtual ~player();
        int getMoveIndex() const;
        virtual void setMoveIndex(AllowedMoves index);
        void setMoveIndexToZero();
};