//
// Created by Nicom on 24.06.2020.
//

#include "Bot1.h"
#include "random"
#include "ctime"

Bot1::Bot1(std::string name,PlayerIO* playerIo)
:
Player(std::move(name),playerIo)
{
srand(time(NULL));
}

int Bot1::chooseColumn(std::array<std::array<char, columns>, rows> & field ){
    _playerIo->printBoard(field);
    int column;
    do {

        column = rand() % columns;
    } while(field[column][rows-1]);
    return column;
}
