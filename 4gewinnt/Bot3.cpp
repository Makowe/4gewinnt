//
// Created by Nicom on 25.06.2020.
//

#include "Bot3.h"

#include <utility>

Bot3::Bot3(std::string name,PlayerIO* playerIo)
:
Player(std::move(name),playerIo) {

}

int Bot3::chooseColumn(std::array<std::array<char, columns>, rows> & field) {
    _playerIo->printBoard(field);
    for(int row=0; row<rows; row++)
    {
        for(int column=0; column<columns; column++)
        {
            if(!field[column][row]) return column;
        }
    }
}
