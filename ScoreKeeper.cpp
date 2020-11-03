// ScoreKeeper.cpp

#include "ScoreKeeper.hpp"

bool ScoreKeeper::isVerticallyConnected
    (std::vector<std::vector<int>> board, int column, int row)
{

    if (row < 3)
    {
        return false;
    }
    else
    {
        return (board[column][row] == board[column][row-1] and
                board[column][row]== board[column][row-2] and
                board[column][row]== board[column][row-3]);
    }
}

bool ScoreKeeper::isHorizontallyConnected
    (std::vector<std::vector<int>> board, int column, int row)
{
    int playertype = board[column][row];
    int connectiveness = 1;
    
    int colTemp = column;
    while (colTemp > 0 and connectiveness < 4)
    {
        colTemp--;
        
        if (board[colTemp][row] == playertype)
        {
            connectiveness++;
        }
        else
        {
            break;
        }
    }
    
    int colTemp2 = column;
    while (colTemp2 < 6 and connectiveness < 4)
    {
        colTemp2++;

        if (board[colTemp2][row] == playertype)
        {
            connectiveness++;
        }
        else
        {
            break;
        }
    }
    
    return (connectiveness > 3);
}

bool ScoreKeeper::isDiagonallyConnected
    (std::vector<std::vector<int>> board, int column, int row)
{
    int playertype = board[column][row];

    int uLbR = 0;
    int bLuR = 0;

// Upper Left -> Bottom Right
    int coltemp = column;
    int rowtemp = row;
    
    while (coltemp > 0 and rowtemp < 5){
        rowtemp++;
        coltemp--;
    }

    while (uLbR < 4 and coltemp <= 6 and rowtemp >= 0)
    {
        if (board[coltemp][rowtemp] == playertype)
        {
            uLbR++;
        }
        else
        {
            uLbR = 0;
        }
        coltemp++;
        rowtemp--;
    }


// Bottom Left -> Upper Right 

    coltemp = column;
    rowtemp = row;

    while (coltemp < 6 and rowtemp < 5){
        rowtemp++;
        coltemp++;
    }

    while (bLuR < 4 and coltemp >= 0 and rowtemp >= 5)
    {
        if (board[coltemp][rowtemp] == playertype)
        {
            bLuR++;
        }
        else
        {
            bLuR = 0;
        }
        coltemp--;
        rowtemp--;
    }
    return (uLbR > 3 or bLuR > 3);
}
