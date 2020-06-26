//
// Created by Nicom on 23.06.2020.
//

#ifndef INC_4GEWINNT_HIDDENGAMEIO_H
#define INC_4GEWINNT_HIDDENGAMEIO_H
#include "GameIO.h"

class HiddenGameIO : public GameIO {
public:
    explicit HiddenGameIO(std::string textDocument);
    void printWinner(Player* winner) override ;
    void PrintTurn(Player* playerNow) override ;
    void printDraw() override ;
    void error() override;

private:
    std::string _textDocument;

};


#endif //INC_4GEWINNT_HIDDENGAMEIO_H
