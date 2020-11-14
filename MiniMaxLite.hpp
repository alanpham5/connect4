//  MiniMaxLite.hpp

#ifndef MiniMaxLite_hpp
#define MiniMaxLite_hpp

#include "BaseGame.hpp"
#include <vector>

class MiniMaxLite{
    
    public:
        int chooseMove(const BaseGame game);
        int search(BaseGame game, int depth, int alpha, int beta);
        int eval(std::vector<std::vector<int>> board);
        
};

#endif /* MiniMaxLite_hpp */
