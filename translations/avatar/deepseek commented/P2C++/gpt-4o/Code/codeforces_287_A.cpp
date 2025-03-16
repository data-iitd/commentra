#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    vector<vector<char>> t(4, vector<char>(4));  // Initialize a 4x4 grid to store the input data.

    // Loop to take input and store it in the grid t.
    for (int i = 0; i < 4; i++) {
        string input;
        cin >> input;  // Take input as a string.
        for (int j = 0; j < 4; j++) {
            t[i][j] = input[j];  // Store each character in the grid.
        }
    }

    int black = 0;  // Initialize the count of black cells to 0.
    int white = 0;  // Initialize the count of white cells to 0.
    int correct = 0;  // Initialize the correct flag to 0.

    // Nested loop to iterate over the 3x3 grid formed by the first 3 rows and columns of t.
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            // Count the number of black and white cells in the current 2x2 subgrid.
            black = 0;  // Reset the count of black cells.
            white = 0;  // Reset the count of white cells.

            if (t[i][j] == '#') {
                black++;
            } else {
                white++;
            }
            if (t[i][j + 1] == '#') {
                black++;
            } else {
                white++;
            }
            if (t[i + 1][j] == '#') {
                black++;
            } else {
                white++;
            }
            if (t[i + 1][j + 1] == '#') {
                black++;
            } else {
                white++;
            }

            // Check if the counts of black and white cells meet any of the specified conditions.
            if (black == 0 || black == 3 || white == 0 || white == 3 || white == 4 || black == 4) {
                correct = 1;  // Set correct to 1 if conditions are met.
                break;  // Break out of the loop.
            }
        }
        if (correct == 1) {
            break;  // Break out of the outer loop if correct is set.
        }
    }

    // Print 'YES' if correct is 1, otherwise print 'NO'.
    if (correct == 1) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}

// <END-OF-CODE>
