// main.cpp
#include "BaseGame.hpp"
#include "MonteCarlo.hpp"
#include "MiniMax.hpp"
#include "MiniMaxLite.hpp"
#include "RandomAI.hpp"
#include <iostream>

int genUserMove(BaseGame newGame){
    int colNumber;
    do {
        std::cout << "Choose column to insert piece (1-7) or quit (0): ";
        std::cin >> colNumber;
    } while(colNumber < 0 or colNumber > 7);

    if (colNumber == 0)
        exit(0);
    
    while(newGame.isColumnFull(colNumber))
    {
        std::cout << "Column full, please pick another column (1-7) or quit (0): ";
        std::cin >> colNumber;

    }
    return colNumber - 1;
}
int main()
{
    // Creating AI objects
    MonteCarlo mcBot;
    MiniMax maxwell;
    MiniMaxLite maxJr;
    RandomAI rando;
    
    BaseGame newGame;
    int colNumber = 0;
    std::string turnCharacter;
    
    std::cout<<"   _____                            _     _  _ "<<std::endl;
    std::cout<<"  / ____|                          | |   | || | "<<std::endl;
    std::cout<<" | |     ___  _ __  _ __   ___  ___| |_  | || |_ "<<std::endl;
    std::cout<<" | |    / _ \\| '_ \\| '_ \\ / _ \\/ __| __| |__   _|"<<std::endl;
    std::cout<<" | |___| (_) | | | | | | |  __/ (__| |_     | |"<<std::endl;
    std::cout<<"  \\_____\\___/|_| |_|_| |_|\\___|\\___|\\__|    |_| "<<std::endl;
    std::cout<<std::endl;
    std::cout<<std::endl;
    std::cout<<std::endl;
    
    std::string player1Mode;
    std::string player2Mode;
    
    std::cout << "Player Index"<<std::endl;
    std::cout << "==================="<<std::endl;
    std::cout << "Human       ---> type 'h'"<<std::endl;
    std::cout << "Bot Level 1 (Random Move)       ---> type '1'"<<std::endl;
    std::cout << "Bot Level 2 (Simple MCTS)       ---> type '2'"<<std::endl;
    std::cout << "Bot Level 3 (MiniMax Full)      ---> type '3'"<<std::endl;
    std::cout << "Bot Level 4 (MMLite w/ Pruning) ---> type '4'"<<std::endl;
    std::cout << "==================="<<std::endl;
    std::cout<<std::endl;
    do{
        std::cout << "Select player 1 mode: ";
        std::cin >> player1Mode;
    }while(player1Mode != "h"
           and player1Mode != "1"
           and player1Mode != "2"
           and player1Mode != "3"
           and player1Mode != "4");

    do{
        std::cout << "Select player 2 mode: ";
        std::cin >> player2Mode;
    }while(player2Mode != "h"
           and player2Mode != "1"
           and player2Mode != "2"
           and player2Mode != "3"
           and player2Mode != "4");


    
    
    while (!newGame.isFinished())
    {
        std::cout<<std::endl;
        newGame.printBoard();
        switch(newGame.whoseTurn()){
            case 1:
                turnCharacter = "X";
                break;
            case 2:
                turnCharacter = "O";
                break;
        }
        
        std::cout << turnCharacter<< "'s turn. ";
        if (newGame.whoseTurn() == 1){
            if(player1Mode == "h"){
                colNumber = genUserMove(newGame);
            }
            else if (player1Mode == "1"){
                colNumber = rando.chooseMove(newGame);
                
            }
            else if (player1Mode == "2"){
                colNumber = mcBot.chooseMove(newGame);
                
            }
            else if (player1Mode == "3"){
                colNumber = maxwell.chooseMove(newGame);
            }
            else if (player1Mode == "4"){
                colNumber = maxJr.chooseMove(newGame);
            }
            
        }
        else{
            if(player2Mode == "h"){
                colNumber = genUserMove(newGame);
            }
            else if (player2Mode == "1"){
                colNumber = rando.chooseMove(newGame);
                
            }
            else if (player2Mode == "2"){
                colNumber = mcBot.chooseMove(newGame);
                
            }
            else if (player2Mode == "3"){
                colNumber = maxwell.chooseMove(newGame);
                
            }
            else if (player2Mode == "4"){
                colNumber = maxJr.chooseMove(newGame);
            }
        }
        if (colNumber > -1 and colNumber < 7){
            if(newGame.isColumnFull(colNumber)){
                std::cout<<turnCharacter<<" Invalid move was made"<<std::endl;
            }
            else{
                newGame.addPiece(colNumber);
            }
        }
    }
    std::cout<<std::endl;
    newGame.printBoard();

    std::cout<<turnCharacter<<" won the game!"<<std::endl;
    
    return 0;
}

