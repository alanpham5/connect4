// MonteCarlo.hpp

#ifndef MonteCarlo_HPP
#define MonteCarlo_HPP
#include "BaseGame.hpp"

class MonteCarlo {
    
    public:
        int chooseMove(const BaseGame game);
        float genScore(int row, BaseGame game);    

};


#endif /* MonteCarlo_h */
