//
// Created by Nicom on 23.06.2020.
//

#ifndef INC_4GEWINNT_PLAYERIO_H
#define INC_4GEWINNT_PLAYERIO_H
#include "string"
#include "iostream"
#include "array"
#include "head.h"

class PlayerIO {

public:
    PlayerIO();
    static int selectInt();
    virtual void print(const std::string& text);
    virtual void printBoard(std::array<std::array<char, columns>,rows>& field);
};


#endif //INC_4GEWINNT_PLAYERIO_H