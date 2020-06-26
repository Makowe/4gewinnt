//
// Created by Nicom on 23.06.2020.
//

#include "PlayerIO.h"



int PlayerIO::selectInt() {
    int number;
    std::cin >> number;
    return number;
}

void PlayerIO::print(const std::string& text) {
    std::cout << text;
}

void PlayerIO::printBoard(std::array<std::array<char, columns>, rows>& board) {
    for(int row = rows-1; row>=0; row--)
    {
        for(int column= 0; column<columns; column++)
        {
            if(board[column][row]) std::cout << board[column][row] << " ";
            else std::cout << "_";
        }
        std::cout << "\n";
    }
}

PlayerIO::PlayerIO() {

}