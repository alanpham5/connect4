// BaseGame.cpp

#include "BaseGame.hpp"
#include <iostream>
#include <vector>

BaseGame::BaseGame()
    :turn{1}, finished{false}
{
// Create 2-d Vec, 1's turn
    for (int i = 0; i < 7; i++)
    {
        gameBoard.push_back({0,0,0,0,0,0});
        colFillLevel[i] =  0;
    }
}

int BaseGame::whoseTurn()
{
    return turn;
}

void BaseGame::changeTurn()
{
    if (turn == 1)
        turn = 2;

    else
        turn = 1;
}

void BaseGame::addPiece()
{
    int colNumber;
    
    std::cout << "Choose column to insert piece (1-7) or quit (0): ";
    std::cin >> colNumber;
    
    if (colNumber == 0)
        exit(0);

    bool isFull = (colFillLevel[colNumber-1] > 5);
    
    while(isFull)
    {
        std::cout << "Column full, please pick another column (1-7) or quit (0): ";
        std::cin >> colNumber;

        isFull = (colFillLevel[colNumber-1] > 6);
    }

    gameBoard[colNumber-1][colFillLevel[colNumber-1]] = turn;

    colFillLevel[colNumber-1]++;
    
    changeTurn();
}

bool BaseGame::isFinished()
{
    return finished;
}

void BaseGame::printBoard()
{
    int coordinate;

    std::cout << std::endl;

    for (int i = 5; i >= 0; i--)
    {
        std::cout << "|";
        for (int j = 0; j < 7; j++)
        {
            coordinate = gameBoard[j][i];
            
            switch (coordinate)
            {
                case 1:
                    std::cout<< "X";
                    break;

                case 2:
                    std::cout << "O";
                    break;
                
                default:
                    std::cout << "_";
                    break;
            }

            std::cout << "|";

        }
        std::cout << std::endl;

    }
    std::cout << " 1 2 3 4 5 6 7" << std::endl;
    std::cout << std::endl;

}
