//
// Created by Nicom on 23.06.2020.
//

#ifndef INC_4GEWINNT_PLAYER_H
#define INC_4GEWINNT_PLAYER_H
#include "string"
#include "array"
#include "head.h"
#include "PlayerIO.h"

class Player {
public:
    explicit Player(std::string name, PlayerIO* playerIo);
    virtual int chooseColumn(std::array<std::array<char, columns>,rows>&) = 0;

    const std::string &getName() const;

protected:
    std::string _name;
    PlayerIO* _playerIo;
};


#endif //INC_4GEWINNT_PLAYER_H
