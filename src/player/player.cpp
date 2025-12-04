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

    if (input == "rock" || input == "r"){
        setMoveIndexToRock();
    } else if (input == "paper" || input == "p"){
        setMoveIndexToPaper();
    } else if (input == "scissors" || input == "s"){
        setMoveIndexToScissors();
    } else {
        std::cout << "invalid move. please try again." << std::endl;
        playerInput();
    }
}