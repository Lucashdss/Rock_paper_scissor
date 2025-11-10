#include "player.hpp"

player::player(): MoveIndex{0}{
}

player::~player(){
}

void player::setMoveIndex(AllowedMoves index){
    MoveIndex = index;
}

int player::getMoveIndex() const{
    return MoveIndex;
}  

void player::setMoveIndexToZero(){
    MoveIndex = 0;
}