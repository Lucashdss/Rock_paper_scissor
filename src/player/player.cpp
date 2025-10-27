#include "player.hpp"

player::player(): MoveIndex{0}{
}

player::~player(){
}

void player::setMoveIndex(int index){
    MoveIndex = index;
}

int player::getMoveIndex() const{
    return MoveIndex;
}  