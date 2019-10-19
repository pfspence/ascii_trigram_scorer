#include <iostream>
#include <fstream>
#include "countLetters.hpp"

void printUsage(char *progName){
    std::cout << std::endl;
    std::cout << "Usage:" << std::endl;
    std::cout << progName << " <input file>" << std::endl;
    std::cout << std::endl;
    return;
}

int main(int argc, char *argv[]) {
    if (argc != 2){
        printUsage(argv[0]);
    }

    const int ASCII_TOTAL = 127;
    int trigramCounts[ASCII_TOTAL][ASCII_TOTAL][ASCII_TOTAL];

    for (int i = 0; i < ASCII_TOTAL; i++){
        for (int j = 0; j < ASCII_TOTAL; j++){
            for (int k = 0; k < ASCII_TOTAL; k++){
                trigramCounts[i][j][k] = 0;
            }
        }
    }

    std::ifstream inFile;
    inFile.open(argv[1]);

    count_letters(inFile, &trigramCounts[0][0][0]);

    inFile.close();

    return 0;
}