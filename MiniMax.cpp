//  MiniMax.cpp

#include "MiniMax.hpp"
#include "BaseGame.hpp"
#include <vector>
#include <random>

int MiniMax::chooseMove(const BaseGame game){
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
            score = search(clone, 4);
            
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
int MiniMax::search(BaseGame game, int depth){
    if(game.isFinished()){
        if(game.getWinner() == 1){
            return -999;
        }
        else{
            return 999;
        }
    }
    if (depth == 0){
        return eval(game.getGameBoard());
    }
    
    if(game.whoseTurn() == 1){
        int min = 999;
        int score = 999;
        for (int i = 0; i < 7; i++){
            BaseGame myClone = game.cloneGame();
            if(!game.isColumnFull(i)){
                game.addPiece(i);
                score = search(myClone, depth - 1);
            }
            if(score <= min){
                min = score;
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
                score = search(myClone, depth - 1);
            }
            if(score >= max){
                max = score;
            }
            
        }
        return max;
    }
}
int MiniMax::eval(std::vector<std::vector<int>> board){
    
    std::vector<int> scorer ;
    scorer.push_back(0);
    scorer.push_back(0);
    
    // Eval Horizontal
    for (int j = 0; j < 6; j++){
        for(int i = 0; i < 3; i++){
            for(int piece = 1; piece < 3; piece++){
                if(board[i][j] != piece
                   and board[i+1][j] != piece
                   and board[i+2][j] != piece
                   and board[i+3][j] != piece
                   and (board[i][j] + board[i+1][j] + board[i+2][j] + board[i+3][j] > 0)){
                    
                    if (piece == 1){
                        scorer[1]++;
                    }
                    else{
                        scorer[0]++;
                    }
                    
                }
            }
        }
    }
    
    // Eval Vertical
    for (int i = 0; i < 7; i++){
        int lastPiece = 0;
        int j = 0;
        while (board[i][j] != 0 and j < 3){
            lastPiece = board[i][j];
            j++;
        }
        if (lastPiece > 0){
            scorer[lastPiece - 1]++;
        }

    }
    
    // Eval Diagonal
    for (int j = 5; j > 2; j--){
        for(int i = 0; i < j - 3; i++){
            for(int piece = 1; piece < 3; piece++){
                if(board[i][j] != piece
                   and board[i+1][j-1] != piece
                   and board[i+2][j-2] != piece
                   and board[i+3][j-3] != piece
                   and (board[i][j] + board[i+1][j-1] + board[i+2][j-2] + board[i+3][j-3] > 0)){
                    
                    if (piece == 1){
                        scorer[1]++;
                    }
                    else{
                        scorer[0]++;
                    }
                }
            }
        }
    }
    for (int i = 1; i < 4; i++){
        for (int j = 5; j > i + 1; j--){
            for(int piece = 1; piece < 3; piece++){
                if(board[i][j] != piece
                   and board[i+1][j-1] != piece
                   and board[i+2][j-2] != piece
                   and board[i+3][j-3] != piece
                   and (board[i][j] + board[i+1][j-1] + board[i+2][j-2] + board[i+3][j-3] > 0)){
                    
                    if (piece == 1){
                        scorer[1]++;
                    }
                    else{
                        scorer[0]++;
                    }
                }
            }
            
        }
    }
    for (int j = 0; j < 3; j++){
        for(int i = 0; i < 3-j; i++){
            for(int piece = 1; piece < 3; piece++){
                if(board[i][j] != piece
                   and board[i+1][j+1] != piece
                   and board[i+2][j+2] != piece
                   and board[i+3][j+3] != piece
                   and (board[i][j] + board[i+1][j+1] + board[i+2][j+2] + board[i+3][j+3] > 0)){
                    
                    if (piece == 1){
                        scorer[1]++;
                    }
                    else{
                        scorer[0]++;
                    }
                }
            }
        }
    }
    for (int i = 1; i < 4; i++){
        for (int j = 0; j < 7-i; j++){
            for(int piece = 1; piece < 3; piece++){
                if(board[i][j] != piece
                   and board[i+1][j+1] != piece
                   and board[i+2][j+2] != piece
                   and board[i+3][j+3] != piece
                   and (board[i][j] + board[i+1][j+1] + board[i+2][j+2] + board[i+3][j+3] > 0)){
                    
                    if (piece == 1){
                        scorer[1]++;
                    }
                    else{
                        scorer[0]++;
                    }
                }
            }
            
        }
    }

    
    
    return scorer[1] - scorer[0];
}

