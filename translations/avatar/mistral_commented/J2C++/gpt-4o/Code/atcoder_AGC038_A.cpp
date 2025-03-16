// Importing required headers for file I/O and Scanner
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

// Main method starts the execution of the program
int main() {
    int H; // Height of the grid
    int W; // Width of the grid
    int A; // Number of columns in the first row
    int B; // Number of rows in the last row

    // Read input values for H, W, A, and B
    cin >> H >> W >> A >> B;

    // Check if the grid dimensions meet the conditions
    if (W < 2 * A || H < 2 * B) {
        cout << -1 << endl; // Print -1 if the conditions are not met
        return 0; // Exit the program
    }

    // Write the grid to the output
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            // Write '0' if the current cell is outside the given rectangular region, otherwise write '1'
            if ((i < B && j < A) || (i >= B && j >= A))
                cout << "0";
            else
                cout << "1";
        }
        cout << endl; // Move to the next line after writing a row
    }

    return 0; // End of the program
}

// <END-OF-CODE>
