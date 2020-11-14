// MiniMaxLite.cpp

#include "MiniMaxLite.hpp"
#include "BaseGame.hpp"
#include <vector>
#include <random>

int MiniMaxLite::chooseMove(const BaseGame game){
    std::random_device device;
    std::default_random_engine engine{device()};
    std::uniform_int_distribution<int> distribution{0, 1};
    
    BaseGame clone = game.cloneGame();
    int id = clone.whoseTurn();
    int min = 9999; // "Maximum Player1 Score"
    int max = -9999; // "Maximum Player2 Score"
    int idealMove = 0;
    int score;
    
    for (int col = 0; col < 7; col++){
        if (!clone.isColumnFull(col)){
            clone.addPiece(col);
            score = search(clone, 8, -999, 999);
            
            switch(id){
                case 1:
                    if (score < min){
                        min = score;
                        idealMove = col;
                    }
                    else if (score == min){
                        if (distribution(engine) == 1)
                        {
                            min = score;
                            idealMove = col;
                        }
                    }
                    break;
                    
                case 2:
                    if (score > max){
                        max = score;
                        idealMove = col;
                    }
                    else if (score == max){
                        if (distribution(engine) == 1)
                        {
                            max = score;
                            idealMove = col;
                        }
                    }
                    break;
                    
            }
        }
    }
    
    return idealMove;
}
int MiniMaxLite::search(BaseGame game, int depth, int alpha, int beta){
    if(game.isFinished()){
        if(game.getWinner() == 1){
            return (int)-100/(eval(game.getGameBoard()) + 1);
        }
        else{
            return (int)100/(eval(game.getGameBoard()) + 1);
        }
    }
    if (depth == 0){
        return 0;
    }
    
    if(game.whoseTurn() == 1){
        int min = 999;
        int score = 999;
        for (int i = 0; i < 7; i++){
            BaseGame myClone = game.cloneGame();
            if(!game.isColumnFull(i)){
                game.addPiece(i);
                score = search(myClone, depth - 1, alpha, beta);
            }
            if(score <= min){
                min = score;
                if (beta > min){
                    beta = min;
                }
            }
            if (alpha >= beta){
                return min;
            }
        }
        return min;
    }
    else{
        int max = -999;
        int score = -999;
        for (int i = 0; i < 7; i++){
            BaseGame myClone = game.cloneGame();
            if(!game.isColumnFull(i)){
                game.addPiece(i);
                score = search(myClone, depth - 1, alpha, beta);
            }
            if(score >= max){
                max = score;
                if (alpha < max){
                    alpha = max;
                }
            }
            if (alpha >= beta){
                return max;
            }
            
        }
        return max;
    }
}
int MiniMaxLite::eval(std::vector<std::vector<int>> board){
    int total = 0;
    for (int i = 0; i < board.size(); i++){
        for (int j = 0; j < board[i].size(); j++){
            if (board[i][j] != 0){
                total++;
            }
        }
    }
    return total;
}
