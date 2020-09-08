// BaseGame.hpp

#ifndef BASEGAME_HPP
#define BASEGAME_HPP

#include <vector>
#include <map>

class BaseGame
{
public:
    BaseGame();
//    BaseGame(const BaseGame game);
    int whoseTurn();
    void changeTurn();
    void addPiece();
    bool isFinished();
    void printBoard();

private:
    std::vector<std::vector<int>> gameBoard;
    std::map<int,int> colFillLevel;
    int turn;
    bool finished;
};

#endif
