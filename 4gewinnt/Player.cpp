//
// Created by Nicom on 23.06.2020.
//

#include "Player.h"

#include <utility>

const std::string &Player::getName() const {
    return _name;
}

Player::Player(std::string name, PlayerIO* playerIo)
:
_name(std::move(name)),
_playerIo(playerIo)
{

}
