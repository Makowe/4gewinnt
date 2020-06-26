//
// Created by Nicom on 23.06.2020.
//

#include "Game.h"
#include "iostream"


void Game::play()
{
    int round = 0;
    int winner = 0;
    while(!winner) {

        if (!(round % 2)) {

            //turn of PlayerA
            _gameIO->PrintTurn(_a);
            int choice = _a->chooseColumn(_board);
            if(_board[choice][rows-1] or choice >= columns or choice < 0)
            {
                _gameIO->error();
                std::cout << "\nPlayer 1 tried to put his chip in column: " << choice << "\n";
                return;
            }
            else {
                place(symbolA, choice);
            }
        }
        else
        {
            //turn of PlayerB
            _gameIO->PrintTurn(_b);
            int choice = _b->chooseColumn(_board);
            if(_board[choice][rows-1] or choice >= columns or choice < 0)
            {
                _gameIO->error();
                std::cout << "\nPlayer 2 tried to put his chip in column: " << choice << "\n";
                return;
            }
            else {
                place(symbolB, choice);
            }
        }
        winner = checkWin();
        round++;
    }
    if(winner == 1) _gameIO->printWinner(_a);
    if(winner == 2) _gameIO->printWinner(_b);
    if(winner == 3) _gameIO->printDraw();
}

int Game::place(char symbol, int column) {
    int i = 0;
    while(_board[column][i] and i<rows) i++;

    if(i>=rows) return 0;

    _board[column][i] = symbol;
    return 0;
}

int Game::checkWin() {
    //check for winner
    if(checkHorizontal(symbolA) or checkVertical(symbolA) or checkDiagonalDown(symbolA) or checkDiagonalUp(symbolA)) return 1;
    if(checkHorizontal(symbolB) or checkVertical(symbolB) or checkDiagonalDown(symbolB) or checkDiagonalUp(symbolB)) return 2;

    //check for draw (both players have 0 possibilities to win the game
    if(!(checkHorizontal(symbolA,0) or checkVertical(symbolA,0) or checkDiagonalDown(symbolA,0) or checkDiagonalUp(symbolA,0),
         checkHorizontal(symbolB,0) or checkVertical(symbolB,0) or checkDiagonalDown(symbolB,0) or checkDiagonalUp(symbolB,0)))
    {
        return 3;
    }

    return 0;
}

Game::Game(Player *a, Player *b, GameIO *gameIO)
:
_a(a), _b(b), _gameIO(gameIO)
{
    //Reset the whole field at the beginning of the game
    for(int column = 0; column<columns; column++)
    {
        for(int row = 0; row<rows; row++)
        {
            _board[column][row]=0;
        }
    }
}

int Game::checkVertical(char symbol, char symbol2) {
    for(int column = 0; column < columns; column++)    //test in every column
    {
        int rowFirst = 0;
        while(rowFirst <= rows - 4)   //test for every row
        {
            int row = 0;
            while(row < 4)           //test for 4 fields horizontally
            {
                if(_board[column][rowFirst + row] == symbol or _board[column][rowFirst + row] == symbol2) //the symbol is the right one -> test the next one
                {
                    row++;
                }
                else {
                    /*one symbol doesn't match -> cancel the test and push rowFirst some rows down
                     * how many lines it should be pushed down depends on which of the 4 tests failed.
                     * If the first 3 tests were successful and the fourth isn't then it will push
                     * rowFirst four rows down, because the next three posibilities
                     * for having four in a column would also fail.*/
                    rowFirst += row + 1;
                    break;
                }
            }
            // four right symbols -> return successful
            if(row == 4) return 1;
        }
    }
    return 0;
}

int Game::checkHorizontal(char symbol, char symbol2) {
    for(int row = 0; row < rows; row++)    //test in every row
    {
        int columnFirst = 0;
        while(columnFirst <= columns - 4)   //test for every column
        {
            int column = 0;
            while(column < 4)           //test for 4 fields diagonally
            {
                if(_board[columnFirst + column][row] == symbol or _board[columnFirst + column][row] == symbol2) //one symbol is the right one -> test the next one
                {
                    column++;
                }
                else {
                    /*one symbol doesn't match -> cancel the test and push ColumnFirst some rows down
                     * how many lines it should push it down depends on which of the 4 tests failed
                     * if the first 3 tests were successful and the fourth isn't then it will push
                     * columnFirst four rows down, because the next three posibilities
                     * for having four in a row would also fail.*/
                    columnFirst += column + 1;
                    break;
                }
            }
            // four right symbols -> return successful
            if(column == 4) return 1;
        }
    }
    return 0;
}

int Game::checkDiagonalUp(char symbol, char symbol2)
{
    for(int rowFirst = 0; rowFirst <= rows - 4; rowFirst++)    //test in every row
    {
        for(int columnFirst = 0; columnFirst <= columns - 4; columnFirst++)   //test for every column
        {
            int diagonal = 0;
            while(diagonal<4)                         //iterate for diagonals
            {
                if(_board[columnFirst + diagonal][rowFirst + diagonal] == symbol or _board[columnFirst + diagonal][rowFirst + diagonal] == symbol2)
                {
                    //one symbol is the right one -> test the next one
                    diagonal++;
                }
                else break;
            }
            // four right symbols -> return successful
            if(diagonal == 4) return 1;
        }
    }
    return 0;
}

int Game::checkDiagonalDown(char symbol, char symbol2) {
    for(int rowFirst = 3; rowFirst < rows; rowFirst++)    //test in every row
    {
        for(int columnFirst = 0; columnFirst <= columns - 4; columnFirst++)   //test for every column
        {
            int diagonal = 0;
            while(diagonal<4)                         //iterate for diagonals
            {
                if(_board[columnFirst + diagonal][rowFirst - diagonal] == symbol or _board[columnFirst + diagonal][rowFirst - diagonal] == symbol2)
                {
                    //one symbol is the right one -> test the next one
                    diagonal++;
                }
                else break;
            }
            // four right symbols -> return successful
            if(diagonal == 4) return 1;
        }
    }
    return 0;
}