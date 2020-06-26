//
// Created by Nicom on 25.06.2020.
//

#include "iostream"
#include "fstream"

void analyze(std::string textDocument, std::string name1, std::string name2)
{
    using namespace std;

    ifstream resultFile(textDocument);
    std::string line;

    int winner[2] = {0,0};
    while(std::getline(resultFile,line))
    {
        if(line == name1) winner[0] += 1;
        if(line == name2) winner[1] += 1;
    }

    std::cout << name1 << " has " << winner[0] << " wins.\n";
    std::cout << name2 << " has " << winner[1] << " wins.\n";

    resultFile.close();
}