//
// Created by Nicom on 24.06.2020.
//

#include "Bot1.h"

#include <utility>

Bot1::Bot1(std::string name,PlayerIO* playerIo)
:
Player(std::move(name),playerIo)
{

}

int Bot1::chooseColumn(std::array<std::array<char, columns>, rows> & field ){
    _playerIo->printBoard(field);
    int column;
    do {
        static std::random_device rd;
        static std::mt19937 engine(rd());
        std::uniform_int_distribution<int> dist(0,columns-1);
        column = dist(rd);
    } while(field[column][rows-1]);
    return column;
}
