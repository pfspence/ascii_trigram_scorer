//
// Created by Matthew Spencer on 10/19/19.
//

#include "countLetters.hpp"
#include "outputLetters.hpp"
#include <fstream>

/*******************************************************************************
** Description: Handles calculating and returning the validated zero based index
**              for letters. Converts uppercase to lowercase. Returns 0 through
**              25 for valid alpha chars and -1 for invalid characters.
**              Uses ascii codes for conversion and validation.
*******************************************************************************/
int getAlphaIndex(char letter) {

    // Ascii decimal values for letters.
    const int ASCII_CAP_A = 65;
    const int ASCII_CAP_Z = 90;
    const int ASCII_LOW_A = 97;
    const int ASCII_LOW_Z = 132;
    const int ASCII_CAP_TO_LOW = 32;

    int index = -1;
    int letterAsciiVal = (int)letter;

    // Check if the character is uppercase char. Convert to lowercase if so.
    if (letterAsciiVal >= ASCII_CAP_A && letterAsciiVal <= ASCII_CAP_Z){
        // To convert an upper to lower, add 32 to the dec value.
        letterAsciiVal += ASCII_CAP_TO_LOW;
    }

    // If character is valid lowercase character, shift left 97 to get
    // a zero based index for an alphabet character.
    if (letterAsciiVal >= ASCII_LOW_A && letterAsciiVal <= ASCII_LOW_Z){
        index = letterAsciiVal - ASCII_LOW_A;
    }
    return index;
}

/*******************************************************************************
** Description:  count_letters takes 2 paramters, ifstream
**               by reference and a pointer to an array of type int. The
**               function first reads the paragraph string from the input file
**               stream, then counts the letter frequencies of that paragraph,
**               and store the frequencies in the array. Disregards upper/lower
**               case letters.
*******************************************************************************/
void count_letters(std::ifstream& inFile, int* letterFreqs) {

    const int EN_LETTER_COUNT = 26;

    std::string paragraph;
    int index = 0;
    int paragraphLength = 0;
    std::ofstream outFile;

    // Read while there is data.
    if (inFile.is_open())
    {
        while (getline(inFile, paragraph)){

            // For each new paragraph processed, initialize frequencies to 0.
            for (int i = 0; i < EN_LETTER_COUNT; i++) {
                letterFreqs[i] = 0;
            }

            // Only count characters if the paragraph is not just a newline.
            paragraphLength = paragraph.length();
            if (paragraphLength > 1){
                for (int i = 0; i < paragraphLength; i++){

                    // getAlphaIndex will return a -1 for invalid characters.
                    // otherwise it will be 0-25.
                    index = getAlphaIndex(paragraph[i]);
                    if (index != -1){
                        letterFreqs[index]++;
                    }
                }

                // Write letter frequencies to file
                output_letters(outFile, letterFreqs);
                outFile.close();
            }
        }
    }
    return;
}