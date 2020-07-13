//
// Created by Nicom on 24.06.2020.
//

#ifndef INC_4GEWINNT_BOT1_H
#define INC_4GEWINNT_BOT1_H
#include "Player.h"
#include "array"
#include "random"
#include "head.h"
#include "PlayerIO.h"
#include <utility>

class Bot1 : public Player {
public:
    explicit Bot1(std::string name, PlayerIO* playerIo);
    int chooseColumn(std::array<std::array<char, columns>,rows>&) override;

};


#endif //INC_4GEWINNT_BOT1_H
