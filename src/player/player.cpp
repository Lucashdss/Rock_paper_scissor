#include "player.hpp"

player::player(): MoveIndex{0}{
}

player::~player(){
}

void player::setMoveIndexToRock(){
    MoveIndex = AllowedMoves::Rock;
}

void player::setMoveIndexToPaper(){
    MoveIndex = AllowedMoves::Paper;
}

void player::setMoveIndexToScissors(){
    MoveIndex = AllowedMoves::Scissors;
}

int player::getMoveIndex() const{
    return MoveIndex;
}  

void player::setMoveIndexToZero(){
    MoveIndex = 0;
}