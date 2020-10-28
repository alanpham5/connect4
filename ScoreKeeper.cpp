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
        return (board[column][row] == board[column][row-1]
            == board[column][row-2] == board[column][row-3]);
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

    int uLbR = 1;
    int bLuR = 1;

// Upper Left -> Bottom Right
    int coltemp = column;
    int rowtemp = row;

    while (coltemp > 0 and rowtemp < 5 and uLbR < 4)
    {
        coltemp--;
        rowtemp++;


        if (board[coltemp][rowtemp] == playertype)
        {
            uLbR++;
        }
        else
        {
            break;
        }
    }

    coltemp = column;
    rowtemp = row;


    while (coltemp < 6 and rowtemp > 0 and uLbR < 4)
    {
        coltemp++;
        rowtemp--;


        if (board[coltemp][rowtemp] == playertype)
        {
            uLbR++;
        }
        else
        {
            break;
        }
    }

// Bottom Left -> Upper Right 

    coltemp = column;
    rowtemp = row;

    while (coltemp > 0 and row > 0 and bLuR < 4)
    {
        coltemp--;
        rowtemp--;


        if (board[coltemp][rowtemp] == playertype)
        {
            bLuR++;
        }
        else
        {
            break;
        }
    }

    coltemp = column;
    rowtemp = row;


    while (coltemp < 6 and rowtemp < 5 and bLuR < 4)
    {
        coltemp++;
        rowtemp++;


        if (board[coltemp][rowtemp] == playertype)
        {
            bLuR++;
        }
        else
        {
            break;
        }
    }

    return (uLbR > 3 or bLuR > 3);
}
