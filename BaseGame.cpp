// BaseGame.cpp

#include "BaseGame.hpp"
#include <iostream>
#include <vector>

BaseGame::BaseGame()
:turn{1}, finished{false}, winner{0}
{
// Create 2-d Vec, 1's turn
    for (int i = 0; i < 7; i++)
    {
        gameBoard.push_back({0,0,0,0,0,0});
        colFillLevel[i] =  0;
    }
}

BaseGame::BaseGame(int sTurn, bool sFinished, std::vector<std::vector<int>> sGameBoard, std::map<int,int> sCollFillLevel, int sWinner)
:turn{sTurn}, finished{sFinished}, gameBoard{sGameBoard}, colFillLevel{sCollFillLevel}, winner{sWinner}
{
}

BaseGame BaseGame::cloneGame() const
{
    BaseGame clone(turn, finished, gameBoard, colFillLevel, winner);
    return clone;
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

void BaseGame::addPiece(int colNumber)
{
    if(!isColumnFull(colNumber)){
        //std::cout<<colNumber<<std::endl;
        //std::cout<<colFillLevel[colNumber]<<std::endl;
        
        gameBoard[colNumber][colFillLevel[colNumber]] = turn;

        if (!checkWinner(colNumber , colFillLevel[colNumber])){
            colFillLevel[colNumber]++;
            changeTurn();
        }
    }
}

bool BaseGame::isColumnFull(int colNumber){
    
    if (colFillLevel[colNumber] > 5){
        return true;
    }
    else{
        return false;
    }
}
bool BaseGame::isFinished()
{
    bool filled = true;
    for(int i = 0; i < 7; i++){
        if(!isColumnFull(i)){
            filled = false;
        }
    }
    
    return (filled or finished);
}
bool BaseGame::checkWinner(int col, int row)
{
    if (checker.isHorizontallyConnected(gameBoard, col, row)
        or checker.isVerticallyConnected(gameBoard, col, row)
        or checker.isDiagonallyConnected(gameBoard, col, row)){
        
        finished = true;
        winner = turn;
        return true;
    }

    return false;
    
}
int BaseGame::getWinner(){
    return winner;
}

std::vector<std::vector<int>> BaseGame::getGameBoard(){
    return gameBoard;
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
