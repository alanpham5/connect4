// main.cpp

#include "BaseGame.hpp"
#include <iostream>

int main()
{

    BaseGame newGame;
    bool finished = newGame.isFinished();
    
    while (!finished)
    {
        newGame.printBoard();
        newGame.addPiece();
    }

    return 0;
}

