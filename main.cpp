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

    const int EN_LETTER_COUNT = 26;
    int letterFreqs[EN_LETTER_COUNT];

    std::ifstream inFile;

    count_letters(inFile, letterFreqs);

    inFile.close();

    return 0;
}