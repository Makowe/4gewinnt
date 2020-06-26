//
// Created by Nicom on 24.06.2020.
//

#include "Bot2.h"

Bot2::Bot2(std::string name,PlayerIO* playerIo)
:
Player(std::move(name),playerIo)
{

}

int Bot2::chooseColumn(std::array<std::array<char, columns>, rows> & field ){
    _playerIo->printBoard(field);
    int column = 0;
    while(field[column][rows-1])
    {
        column+=1;
    }
    return column;
}