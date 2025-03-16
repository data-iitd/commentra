
#include <iostream> // Importingiostream for input and output operations
#include <fstream> // Importingfstream for file input and output operations
#include <string> // Importingstring for string manipulation

using namespace std;

int main() { // Main function is the entry point of the program
    ifstream fin("input.txt"); // Opening the input file for reading
    ofstream fout("output.txt"); // Opening the output file for writing

    int H, W, A, B; // Declaring variables to store the matrix dimensions and values of A and B

    fin >> H >> W >> A >> B; // Reading the matrix dimensions and values of A and B from the input file

    // Checking if the matrix dimensions are suitable for the given values of A and B
    if (W < 2 * A || H < 2 * B) {
        fout << -1 << endl; // Writing -1 to the output file if the matrix dimensions are not suitable
        return 0; // Exiting the program
    }

    // Nested loops to generate the matrix
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            // Assigning 0 or 1 based on the conditions specified
            if ((i < B && j < A) || (i >= B) && (j >= A)) {
                fout << 0 << " "; // Writing 0 to the output file
            } else {
                fout << 1 << " "; // Writing 1 to the output file
            }
        }
        fout << endl; // Moving to the next line after each row is written
    }

    fin.close(); // Closing the input file
    fout.close(); // Closing the output file

    return 0; // Returning 0 to indicate successful execution of the program
}

