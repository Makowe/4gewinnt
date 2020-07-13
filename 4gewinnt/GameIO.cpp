//
// Created by Nicom on 23.06.2020.
//

#include "GameIO.h"
#include "iostream"

void GameIO::printWinner(Player* winner) {
    std::cout << "The winner is: " << winner->getName() << " Congratulations!\n";
}

void GameIO::PrintTurn(Player *playerNow) {
    std::cout << "It's the turn of: " << playerNow->getName() << "\n";
}

void GameIO::printDraw() {
    std::cout << "Nobody has won this game.\n";
}