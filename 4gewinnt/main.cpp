#include <iostream>
#include "head.h"
#include "Human.h"
#include "Game.h"
#include "HiddenGameIO.h"
#include "HiddenPlayerIO.h"
#include "Bot1.h"
#include "Bot2.h"
#include "Bot3.h"
#include "Bot4.h"
#include "functions.h"

int main() {

    //IO for Players
    PlayerIO pio1;
    HiddenPlayerIO pio2;

    Human h1("Nico",&pio1);
    Human h2("Tom",&pio1);
    Bot1 b1("randomBot",&pio2);
    Bot2 b2("leftBot",&pio2);
    Bot3 b3("bottomBot",&pio2);
    Bot4 b4("intelligent",&pio1);

    //IO for game
    GameIO gio1;
    HiddenGameIO gio2("result.txt");


    for (int i = 0; i < 1; i++) {
        Game g1(&b3, &b4, &gio2);
        g1.play();
    }

    analyze("result.txt", b3.getName(),b4.getName());

}
