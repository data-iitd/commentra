
// Importing required libraries for file I/O and Scanner
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <sstream>

// Main function starts the execution of the program
int main ( ) {
    std::ifstream fin ( "input.txt" ); // Initialize input file stream
    std::ofstream fout ( "output.txt" ); // Initialize output file stream
    int H; // Height of the grid
    int W; // Width of the grid
    int A; // Number of columns in the first row
    int B; // Number of rows in the last row

    // Read input values for H, W, A, and B from the input file
    fin >> H >> W >> A >> B;

    // Check if the grid dimensions meet the conditions
    if ( W < 2 * A || H < 2 * B ) {
        fout << - 1 << std::endl; // Print -1 if the conditions are not met
        return 0; // Exit the program
    }

    // Write the grid to the output file
    for ( int i = 0 ; i < H ; i ++ ) {
        for ( int j = 0 ; j < W ; j ++ ) {
            // Write '0' if the current cell is outside the given rectangular region, otherwise write '1'
            if ( ( i < B && j < A ) || ( i >= B ) && ( j >= A ) )
                fout << "0";
            else
                fout << "1";
        }
        fout << std::endl; // Move to the next line after writing a row
    }

    // Close the output file stream
    fout.close ( );

    return 0;
}

