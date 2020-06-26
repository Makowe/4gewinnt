//
// Created by Nicom on 23.06.2020.
//

#ifndef INC_4GEWINNT_HUMAN_H
#define INC_4GEWINNT_HUMAN_H
#include "Player.h"
#include "PlayerIO.h"

class Human : public Player {

public:
    explicit Human(std::string name, PlayerIO* playerIo);
    int chooseColumn(std::array<std::array<char, columns>,rows>& field) override;

private:

};


#endif //INC_4GEWINNT_HUMAN_H
