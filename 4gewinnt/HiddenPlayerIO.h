//
// Created by Nicom on 26.06.2020.
//

#ifndef INC_4GEWINNT_HIDDENPLAYERIO_H
#define INC_4GEWINNT_HIDDENPLAYERIO_H
#include "PlayerIO.h"
#include "Player.h"

class HiddenPlayerIO : public PlayerIO {
public:
    HiddenPlayerIO();
    void print(const std::string& text) override;
    void printBoard(std::array<std::array<char, columns>,rows>& field) override;

};


#endif //INC_4GEWINNT_HIDDENPLAYERIO_H
