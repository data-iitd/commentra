#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Initialize an empty vector to store the input grid
    vector<vector<char>> t(4, vector<char>(4));

    // Read 4 lines of input and store each line in the vector 't'
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> t[i][j];
        }
    }

    // Initialize counters for black and white cells
    int black = 0;
    int white = 0;
    // Initialize a flag to indicate if the grid is correct
    bool correct = false;

    // Iterate through the 3x3 grid (the first 3 rows and columns)
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            // Count the number of black cells ('#') in the 2x2 block
            black = 0;
            white = 0;

            // Check the current cell and the 2x2 block
            for (int x = 0; x < 2; x++) {
                for (int y = 0; y < 2; y++) {
                    if (t[i + x][j + y] == '#') {
                        black++;
                    } else {
                        white++;
                    }
                }
            }

            // Check if the current 2x2 block is valid (all black or all white)
            if (black == 0 || black == 4 || white == 0 || white == 4 || black == 3 || white == 3) {
                correct = true;  // Mark as correct if the condition is met
                break;
            }
        }
        if (correct) break; // Break outer loop if a valid block was found
    }

    // Output the result based on whether a correct block was found
    if (correct) {
        cout << "YES" << endl;  // Print 'YES' if a valid block was found
    } else {
        cout << "NO" << endl;   // Print 'NO' if no valid block was found
    }

    return 0;
}

// <END-OF-CODE>
