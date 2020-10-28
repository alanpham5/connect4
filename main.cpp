// main.cpp
#include "BaseGame.hpp"
#include <iostream>

int main()
{

    BaseGame newGame;
    
    while (!newGame.isFinished())
    {
        newGame.printBoard();
        newGame.addPiece();
    }
    newGame.printBoard();
    std::string turnCharacter;
    switch(newGame.whoseTurn()){
        case 1:
            turnCharacter = "X";
            break;
        case 2:
            turnCharacter = "Y";
            break;
        default:
            throw "False Winner Error";
    }
    std::cout<<turnCharacter<<" won the game!"<<std::endl;
    
    return 0;
}

