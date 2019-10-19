#include "countLetters.hpp"
#include "outputLetters.hpp"
#include <fstream>

/*******************************************************************************
** Description:  2 params: ifstream of file to read & pointer to the initialized
 * 3d array tracking trigram counts.
*******************************************************************************/
void count_letters(std::ifstream& inFile, int* trigramCounts) {

    std::ofstream outFile;

    // Read while there is data.
    std::string line;
    int lineLength = 0;
    int n1,n2,n3;
    int *addr;

    if (inFile.is_open())
    {
        while (getline(inFile, line)){

            lineLength = line.length();

            // Iterate through chunking each line into trigrams and increment
            // their respective 3d array count.
            for (int i = 0; i < lineLength - 2; i++){
                n1 = (int)line[i];
                n2 = (int)line[i+1];
                n3 = (int)line[i+2];

                // Calculate the addr of the 3d array indices.
                // Essentially doing this: trigramCounts[n1][n2][n3]++;
                addr = trigramCounts + 16129 * n1 + 127 * n2 + n3;
                *(addr) = *(addr) + 1;
            }

            output_letters(outFile, trigramCounts);
            outFile.close();
        }
    }
    return;
}