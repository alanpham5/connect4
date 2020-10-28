// ScoreKeeper.hpp

#ifndef SCOREKEEPER_HPP
#define SCOREKEEPER_HPP

#include <vector>

class ScoreKeeper
{
public:
    bool isVerticallyConnected(std::vector<std::vector<int>> board, int column, int row);
    bool isHorizontallyConnected(std::vector<std::vector<int>> board, int column, int row);
    bool isDiagonallyConnected(std::vector<std::vector<int>> board, int column, int row);
};


#endif
