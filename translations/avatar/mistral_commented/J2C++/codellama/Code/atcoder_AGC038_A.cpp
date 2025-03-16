// Including required header files for file I/O and Scanner
#include <iostream>
#include <fstream>
#include <string>

// Main method starts the execution of the program
int main ( ) {
    // Initialize Scanner for user input
    std::cin >> H >> W >> A >> B;

    // Check if the grid dimensions meet the conditions
    if ( W < 2 * A || H < 2 * B ) {
        std::cout << - 1 << std::endl; // Print -1 if the conditions are not met
        return 0; // Exit the program
    }

    // Write the grid to the output
    for ( int i = 0 ; i < H ; i ++ ) {
        for ( int j = 0 ; j < W ; j ++ ) {
            // Write '0' if the current cell is outside the given rectangular region, otherwise write '1'
            if ( ( i < B && j < A ) || ( i >= B ) && ( j >= A ) )
                std::cout << "0";
            else
                std::cout << "1";
        }
        std::cout << std::endl; // Move to the next line after writing a row
    }

    return 0;
}



