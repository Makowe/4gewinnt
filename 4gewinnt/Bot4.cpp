//
// Created by Nicom on 25.06.2020.
//

#include "Bot4.h"

#include <utility>
#include "algorithm"

Bot4::Bot4(std::string name,PlayerIO* playerIo)
:
Player(std::move(name),playerIo) {

}

int Bot4::chooseColumn(std::array<std::array<char, columns>, rows> & field) {
    _playerIo->printBoard(field);
    int goodColumn;
    std::vector<int> badColumn;

    //FIRST PRIORITY: WINNING IF POSSIBLE
    //horizontal
    for(int columnFirst = 0; columnFirst <= columns-4; columnFirst++)
    {
        for(int rowFirst = 0; rowFirst < rows; rowFirst++)
        {
            if (checkOneHorizontal(field, columnFirst, rowFirst,goodColumn,badColumn,symbolB))
            {
                return goodColumn;
            }
        }
    }

    //vertical
    for(int columnFirst = 0; columnFirst < columns; columnFirst++)
    {
        for(int rowFirst = 0; rowFirst <= rows-4; rowFirst++)
        {
            if (checkOneVertical(field, columnFirst, rowFirst,goodColumn,badColumn,symbolB))
            {
                return goodColumn;
            }
        }
    }

    //diagonalUp
    for(int columnFirst = 0; columnFirst <= columns-4; columnFirst++)
    {
        for(int rowFirst = 0; rowFirst <= rows-4; rowFirst++)
        {
            if (checkOneDiagonalUp(field, columnFirst, rowFirst,goodColumn,badColumn,symbolB))
            {
                return goodColumn;
            }
        }
    }

    //diagonalDown
    for(int columnFirst = 0; columnFirst <= columns-4; columnFirst++)
    {
        for(int rowFirst = 3; rowFirst < rows; rowFirst++)
        {
            if (checkOneDiagonalDown(field, columnFirst, rowFirst,goodColumn,badColumn,symbolB))
            {
                return goodColumn;
            }
        }
    }

    //SECOND PRIORITY: STOP OPPONENT FROM WINNING (exact same functions. it is only checked for the opponents symbol)

    //horizontal
    for(int columnFirst = 0; columnFirst <= columns-4; columnFirst++)
    {
        for(int rowFirst = 0; rowFirst < rows; rowFirst++)
        {
            if (checkOneHorizontal(field, columnFirst, rowFirst,goodColumn,badColumn,symbolA))
            {
                return goodColumn;
            }
        }
    }

    //vertical
    for(int columnFirst = 0; columnFirst < columns; columnFirst++)
    {
        for(int rowFirst = 0; rowFirst <= rows-4; rowFirst++)
        {
            if (checkOneVertical(field, columnFirst, rowFirst,goodColumn,badColumn,symbolA))
            {
                return goodColumn;
            }
        }
    }

    //diagonalUp
    for(int columnFirst = 0; columnFirst <= columns-4; columnFirst++)
    {
        for(int rowFirst = 0; rowFirst <= rows-4; rowFirst++)
        {
            if (checkOneDiagonalUp(field, columnFirst, rowFirst,goodColumn,badColumn,symbolA))
            {
                return goodColumn;
            }
        }
    }

    //diagonalDown
    for(int columnFirst = 0; columnFirst <= columns-4; columnFirst++)
    {
        for(int rowFirst = 3; rowFirst < rows; rowFirst++)
        {
            if (checkOneDiagonalDown(field, columnFirst, rowFirst,goodColumn,badColumn,symbolA))
            {
                return goodColumn;
            }
        }
    }

    //THIRD PRIORITY return the first possible and good column

    for(int column; column<columns-1; column++) {
        if (!field[column][rows - 1] and !(std::find(badColumn.begin(), badColumn.end(), column) != badColumn.end())) {
            return column;
        }
    }

    //FOURTH PRIORITY return any possible column because every column is either bad or impossible

    for(int column; column<columns-1; column++) {
        if (!field[column][rows - 1]) {
            return column;
        }
    }
}

//those 4 functions check if one player could win if it was his turn. when yes, the bot places his chip in the gap
//either he wins or he stops the opponent from winning

//additionally it is checked if one player could win when the other player places in one gap
//for example one player has 3 in row but can't place the 4th because there is air below the gap.
//--> It is a bad idea to place the own chip there because it would help the other player winning
//those bad columns are stored in badColumn[3]

int Bot4::checkOneHorizontal(std::array<std::array<char, columns>, rows> & field, int columnFirst, int rowFirst, int& goodColumn, std::vector<int>& badColumn, char c1) {
    int countSymbol = 0;
    int positionEmpty;
    for(int i = 0; i < 4; i++)
    {
        if(field[columnFirst+i][rowFirst] == c1) countSymbol ++;    //tested chip in position -> increment Numbercount
        else if(field[columnFirst+i][rowFirst]) return 0;           //other chip in position -> tested chip can't have 4 in a row
        else positionEmpty = i;                                     //no chip at all
    }
    if(countSymbol == 3) //already 3 in a row
    {
        if(rowFirst == 0 or field[columnFirst+positionEmpty][rowFirst-1] != 0)
        {
            //the fourth one can be placed (either the chip must be placed on the ground (rowFirst == 0) or below the position
            //is already a chip so the new chip fits inside the hole)
            goodColumn= columnFirst + positionEmpty;
            return 1;   //return to the other function that a good column is found
        }
        else if(rowFirst == 1 or field[columnFirst+positionEmpty][rowFirst-2] != 0)
        {
            //the fourth one can't be placed at the moment. There is one space below that should not be filled
            //because it either helps the opponent winning or helps the opponent to destroy the own chance.
            badColumn.push_back(columnFirst+positionEmpty);
        }
    }
    return 0;
}

int Bot4::checkOneVertical(std::array<std::array<char, columns>, rows> & field, int columnFirst, int rowFirst, int& goodColumn, std::vector<int>& badColumn, char c1) {
    int countSymbol = 0;
    for(int i = 0; i < 4; i++)
    {
        if(field[columnFirst][rowFirst+i] == c1) countSymbol++;    //tested Chip in position
        else if(field[columnFirst][rowFirst+i]) return 0;        //other chip in position
    }
    if(countSymbol == 3) //already 3 in a column, fourth can be placed
    {
        goodColumn = columnFirst;
        return 1;
    }
    return 0;
}

int Bot4::checkOneDiagonalUp(std::array<std::array<char, columns>, rows> &field, int columnFirst, int rowFirst, int& goodColumn, std::vector<int>& badColumn, char c1) {
    int countSymbol = 0;
    int positionEmpty;
    for(int i = 0; i < 4; i++)
    {
        if(field[columnFirst+i][rowFirst+i] == c1) countSymbol ++;      //tested chip
        else if(field[columnFirst+i][rowFirst+i]) return 0;             //other chip
        else positionEmpty = i;                                         //no chip
    }
    if(countSymbol == 3) //already 3 in a row
    {
        if(rowFirst+positionEmpty == 0 or field[columnFirst+positionEmpty][rowFirst+positionEmpty-1])
        {
            //the fourth one can be placed (either the chip must be placed on the ground (rowFirst == 0) or below the position
            //there is another chip so the chip fits inside the hole
            goodColumn= columnFirst + positionEmpty;
            return 1;   //return to the other function that a good column is found
        }
        else if(rowFirst+positionEmpty == 1 or field[columnFirst+positionEmpty][rowFirst+positionEmpty-2] != 0)
        {
            //the fourth one can't be placed at the moment. There is one space below that should not be filled
            //because it either helps the opponent winning or helps the opponent to destroy the own chance.
            badColumn.push_back(columnFirst+positionEmpty);
        }
    }
    return 0;
}

int Bot4::checkOneDiagonalDown(std::array<std::array<char, columns>, rows> &field, int columnFirst, int rowFirst, int& goodColumn, std::vector<int>& badColumn, char c1) {
    int countSymbol = 0;
    int positionEmpty;
    for(int i = 0; i < 4; i++)
    {
        if(field[columnFirst+i][rowFirst-i] == c1) countSymbol ++;  //tested chip
        else if(field[columnFirst+i][rowFirst-i])   return 0;       //other chip
        else positionEmpty = i;                                     //no chip
    }
    if(countSymbol == 3) //already 3 in a row
    {
        if(rowFirst-positionEmpty == 0 or field[columnFirst+positionEmpty][rowFirst-positionEmpty-1])
        {
            //the fourth one can be placed (either the chip must be placed on the ground (rowFirst == 0) or below the position
            //there is another chip so the chip fits inside the gap
            goodColumn= columnFirst + positionEmpty;
            return 1;   //return to the other function that a good column is found
        }
        else if(rowFirst-positionEmpty == 1 or field[columnFirst+positionEmpty][rowFirst-positionEmpty-2] != 0)
        {
            //the fourth one can't be placed at the moment. There is one space below that should not be filled
            //because it either helps the opponent winning or helps the opponent to destroy the own chance.
            badColumn.push_back(columnFirst+positionEmpty);
        }
    }
    return 0;
}