//
// Created by Nicom on 23.06.2020.
//

#include "Human.h"

int Human::chooseColumn(std::array<std::array<char, columns>, rows>& field) {

    _playerIo->printBoard(field);
    int choice;
    do {
        _playerIo->print(getName());
        _playerIo->print(", Choose a column\n");
        choice = PlayerIO::selectInt()-1;       //remove 1 to convert from human numbers to code numbers

        if (field[choice][rows - 1]) _playerIo->print("This column is already full.\n");

    } while(field[choice][rows-1] or choice >= columns or choice <0);
    return choice;
}


Human::Human(std::string name, PlayerIO* playerIo)
:
Player(name,playerIo)
{
}
