//  MonteCarlo.cpp

#include "MonteCarlo.hpp"
#include "BaseGame.hpp"
#include <vector>
#include <random>

int MonteCarlo::chooseMove(const BaseGame game){
    BaseGame clone = game.cloneGame();
    int maxEval = -99999;
    int move = 0;
    
    std::random_device device;
    std::default_random_engine engine{device()};
    std::uniform_int_distribution<int> distribution{0, 1};
    
    for (int i = 0; i < 7; i++){
        if (!clone.isColumnFull(i)){
            float score = genScore(i, clone);
            if (score > maxEval){
                move = i;
                maxEval = score;
            }
            // Reduces inevitable right skew
            else if (score == maxEval){
                int flip = distribution(engine);
                if (flip == 1){
                    move = i;
                    maxEval = score;
                }
                
            }
        }
        
    }
    return move;
}

float MonteCarlo::genScore(int row, BaseGame game){
    std::random_device device;
    std::default_random_engine engine{device()};
    std::uniform_int_distribution<int> distribution{0, 6};
    int turn = game.whoseTurn();
    int x = 1;
    float scoreSum = 0;
    BaseGame clone = game.cloneGame();
    clone.addPiece(row);
    for (int i = 0; i < 2; i++){
        int turns = 1;
        BaseGame moveClone = clone.cloneGame();
        
        // Randomly simulates a game to completion
        while (!moveClone.isFinished()){
            x = distribution(engine);
            if(!moveClone.isColumnFull(x)){
                moveClone.addPiece(x);
            }
        }
        // Evaluates game outcome
        if(moveClone.getWinner() == turn){
            scoreSum += 100/turns;
        }
        else{
            scoreSum += (-100)/turns;
        }
    }
    
    // Return average of evaluation after 2 simulations
    return scoreSum/2;
}
