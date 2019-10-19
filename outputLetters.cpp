#include "outputLetters.hpp"
#include <fstream>

/*******************************************************************************
** Description: Paramters: output file stream, pointer to an array of integers
**              that contains frequencies of letters. Writes to file.
*******************************************************************************/
void output_letters(std::ofstream& outFile, int* trigramCounts){

    const int ASCII_TOTAL = 127;
    int * addr;

    std::string outFilePath = "./trigram-mapping.txt";
    outFile.open(outFilePath);

    for (int n1 = 32; n1 < ASCII_TOTAL; n1++){
        for (int n2 = 32; n2 < ASCII_TOTAL; n2++){
            for (int n3 = 32; n3 < ASCII_TOTAL; n3++){
                addr = trigramCounts + 16129 * n1 + 127 * n2 + n3;
                if (*(addr) != 0) {
                    outFile << (char)n1 << (char)n2 << (char)n3 << "    ";
                    outFile << *(trigramCounts + 16129 * n1 + 127 * n2 + n3) << std::endl;
                }
            }
        }
    }
    outFile.close();
    return;
}
