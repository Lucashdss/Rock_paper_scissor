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

void player::playerInput(){
    std::string input;
    
    std::cout << "enter your move (rock, paper, scissors): ";
    std::cin >> input;
    
    std::transform(input.begin(), input.end(), input.begin(), ::tolower);

    if (input == "rock"){
        setMoveIndexToRock();
    } else if (input == "paper"){
        setMoveIndexToPaper();
    } else if (input == "scissors"){
        setMoveIndexToScissors();
    } else {
        std::cout << "invalid move. please try again." << std::endl;
        playerInput();
    }
}