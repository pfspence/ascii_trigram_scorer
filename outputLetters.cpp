//
// Created by Matthew Spencer on 10/19/19.
//

#include "outputLetters.hpp"
#include <fstream>

/*******************************************************************************
** Description: Returns the lowercase alpha character from a zero based index.
**              ie 0 returns 'a', 1 returns 'b'. Valid input is 0-25. Invalid
**              input will still return a lowercase character although probably
**              not what desired.
*******************************************************************************/
char getAsciiChar(int zbIndex) {

    const int ASCII_LOW_A = 97;
    const int EN_LETTER_COUNT = 26;
    int asciiVal = ASCII_LOW_A;

    // Ensure that our zero based index is 0-25.
    if(zbIndex < 0){
        zbIndex = 0;
    }
    zbIndex = zbIndex % EN_LETTER_COUNT;

    return (char)(asciiVal + zbIndex);
}

/*******************************************************************************
** Description: Paramters: output file stream, pointer to an array of integers
**              that contains frequencies of letters. Writes to file.
*******************************************************************************/
void output_letters(std::ofstream& outFile, int* letterFreqs){

    const int EN_LETTER_COUNT = 26;

    std::string outFilePath = "./output.txt";
    outFile.open(outFilePath);

    for (int i = 0; i < EN_LETTER_COUNT; i++){
        outFile << getAsciiChar(i) << ": ";
        outFile << letterFreqs[i] << std::endl;
    }
    outFile.close();
    return;
}
