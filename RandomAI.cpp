//  RandomAI.cpp

#include <random>
#include "BaseGame.hpp"
#include "RandomAI.hpp"

int RandomAI::chooseMove(const BaseGame game){
    std::random_device device;
    std::default_random_engine engine{device()};
    std::uniform_int_distribution<int> distribution{0, 6};
    
    BaseGame clone = game.cloneGame();
    int move;
    
    do{
        move = distribution(engine);
    } while(clone.isColumnFull(move));
    
    return move;
}

