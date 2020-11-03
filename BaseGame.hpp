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
    BaseGame(int sTurn, bool sFinished, std::vector<std::vector<int>> sGameBoard, std::map<int,int> sCollFillLevel, int sWinner);
    BaseGame cloneGame() const;
    int whoseTurn();
    void changeTurn();
    void addPiece(int col);
    bool isColumnFull(int columnNumber);
    bool isFinished();
    bool checkWinner(int col, int row);
    int getWinner();
    void printBoard();

private:
    std::vector<std::vector<int>> gameBoard;
    std::map<int,int> colFillLevel;
    int turn;
    int winner;
    ScoreKeeper checker;
    bool finished;
};

#endif
