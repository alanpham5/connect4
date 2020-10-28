// BaseGame.hpp

#ifndef BASEGAME_HPP
#define BASEGAME_HPP

#include <vector>
#include <map>
#include "ScoreKeeper.hpp"

class BaseGame
{
public:
    BaseGame();
    int whoseTurn();
    void changeTurn();
    void addPiece();
    bool isFinished();
    int checkWinner(int col, int row);
    void printBoard();

private:
    std::vector<std::vector<int>> gameBoard;
    std::map<int,int> colFillLevel;
    int turn;
    ScoreKeeper checker;
    bool finished;
};

#endif
