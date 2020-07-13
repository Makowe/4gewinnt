//
// Created by Nicom on 23.06.2020.
//

#ifndef INC_4GEWINNT_GAMEIO_H
#define INC_4GEWINNT_GAMEIO_H
#include "Player.h"

class GameIO {
public:
    virtual void printWinner(Player* winner);
    virtual void PrintTurn(Player* playerNow);
    virtual void printDraw();

};


#endif //INC_4GEWINNT_GAMEIO_H