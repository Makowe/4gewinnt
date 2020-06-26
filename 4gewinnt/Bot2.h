//
// Created by Nicom on 24.06.2020.
//

#ifndef INC_4GEWINNT_BOT2_H
#define INC_4GEWINNT_BOT2_H
#include "Player.h"
#include "array"
#include "random"
#include "head.h"

class Bot2 : public Player {
public:
    explicit Bot2(std::string name,PlayerIO* playerIo);
    int chooseColumn(std::array<std::array<char, columns>,rows>&) override;
};


#endif //INC_4GEWINNT_BOT2_H
