//
// Created by Nicom on 23.06.2020.
//

#include "HiddenGameIO.h"

#include <utility>
#include "iostream"
#include "fstream"


void HiddenGameIO::printWinner(Player *winner) {
    using namespace std;
    ofstream resultFile;
    resultFile.open(_textDocument,ios::app);
    resultFile << winner->getName() << "\n";
    resultFile.close();
}

void HiddenGameIO::PrintTurn(Player *playerNow) {
    //do nothing
}

void HiddenGameIO::printDraw() {
    using namespace std;
    ofstream resultFile;
    resultFile.open(_textDocument,ios::app);
    resultFile << "draw\n";
    resultFile.close();
}

HiddenGameIO::HiddenGameIO(std::string textDocument)
:
_textDocument(std::move(textDocument))
{

}

