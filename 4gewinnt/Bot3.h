//
// Created by Nicom on 25.06.2020.
//

#ifndef INC_4GEWINNT_BOT3_H
#define INC_4GEWINNT_BOT3_H
#include "Player.h"
#include "array"
#include "random"
#include "head.h"
#include "PlayerIO.h"

class Bot3 : public Player {
public:
    explicit Bot3(std::string name,PlayerIO* playerIo);
    int chooseColumn(std::array<std::array<char, columns>,rows>&) override;
};


#endif //INC_4GEWINNT_BOT3_H
