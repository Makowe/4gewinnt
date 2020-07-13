//
// Created by Nicom on 23.06.2020.
//

#ifndef INC_4GEWINNT_GAME_H
#define INC_4GEWINNT_GAME_H
#include "array"
#include "head.h"
#include "Player.h"
#include "GameIO.h"

class Game
{
public:
    Game(Player* a, Player* b, GameIO* gameIO);
    void play();
    int place(char symbol, int column);
    int checkWin();

    //the test functions can have two parameters to check if a win is still possible
    //e.g. checkHorizontal('X') checks if there are 4 X's in a row
    //checkHorizontal('X',0) checks if it is still possible to have four in a row
    //the 1 as a default values does not have a meaning, because no char on the field can be a 1
    int checkHorizontal(char symbol, char symbol2 = 1);
    int checkVertical(char symbol, char symbol2 = 1);
    int checkDiagonalDown(char symbol, char symbol2 = 1);
    int checkDiagonalUp(char symbol, char symbol2 = 1);

private:
    Player* _a;
    Player* _b;
    GameIO* _gameIO;
    std::array<std::array<char,columns>,rows> _board{};
};


#endif //INC_4GEWINNT_GAME_H
