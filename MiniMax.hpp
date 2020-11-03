//  MiniMax.hpp

#ifndef MINIMAX_HPP
#define MINIMAX_HPP
#include "BaseGame.hpp"
#include <vector>

class MiniMax{
    
    public:
        int chooseMove(const BaseGame game);
        int search(BaseGame game, int depth);
        int eval(std::vector<std::vector<int>> board);
        
};

#endif /* MiniMax_h */
