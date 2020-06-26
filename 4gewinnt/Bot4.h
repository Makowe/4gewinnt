//
// Created by Nicom on 25.06.2020.
//

#ifndef INC_4GEWINNT_BOT4_H
#define INC_4GEWINNT_BOT4_H
#include "Player.h"
#include "array"
#include "random"
#include "head.h"
#include "PlayerIO.h"

class Bot4 : public Player {
public:
    explicit Bot4(std::string name,PlayerIO* playerIo);
    int chooseColumn(std::array<std::array<char, columns>,rows>&) override;
    int checkOneHorizontal    (std::array<std::array<char, columns>, rows> & field, int columnFirst, int rowFirst, int& goodColumn, int* badColumn, char c1);
    int checkOneVertical      (std::array<std::array<char, columns>, rows> & field, int columnFirst, int rowFirst, int& goodColumn, int* badColumn, char c1);
    int checkOneDiagonalUp    (std::array<std::array<char, columns>, rows> & field, int columnFirst, int rowFirst, int& goodColumn, int* badColumn, char c1);
    int checkOneDiagonalDown  (std::array<std::array<char, columns>, rows> & field, int columnFirst, int rowFirst, int& goodColumn, int* badColumn, char c1);

};


#endif //INC_4GEWINNT_BOT4_H
