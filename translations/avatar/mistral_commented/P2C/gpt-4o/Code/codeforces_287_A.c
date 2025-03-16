#include <stdio.h>

int main() {
    char t[4][5]; // Initialize a 4x5 array to store the input strings (4 rows, 4 columns + 1 for null terminator)
    
    // Loop through 4 iterations to get input strings from user
    for (int i = 0; i < 4; i++) {
        scanf("%s", t[i]); // Read a string into the i-th row of the array
    }

    int black = 0; // Initialize black and white counters to 0
    int white = 0;
    int correct = 0;

    // Loop through the first 3 rows of the 4x4 grid represented by array 't'
    for (int i = 0; i < 3; i++) {
        // Loop through the first 3 columns of the current row
        for (int j = 0; j < 3; j++) {
            // Reset black and white counters for the current cell
            black = 0;
            white = 0;

            // Check the current cell
            if (t[i][j] == '#') {
                black++;
            } else {
                white++;
            }

            // Check the right neighbor
            if (t[i][j + 1] == '#') {
                black++;
            } else {
                white++;
            }

            // Check the bottom neighbor
            if (t[i + 1][j] == '#') {
                black++;
            } else {
                white++;
            }

            // Check the bottom-right neighbor
            if (t[i + 1][j + 1] == '#') {
                black++;
            } else {
                white++;
            }

            // Check for winning conditions
            if (black == 0 || black == 3 || white == 0 || white == 3 || white == 4 || black == 4) {
                correct = 1; // If a winning condition is met, set 'correct' to 1 and break out of the loop
                break;
            }
        }
        if (correct == 1) {
            break; // Break out of the outer loop if a winning condition is found
        }
    }

    // If 'correct' is set to 1, print 'YES'
    if (correct == 1) {
        printf("YES\n");
    } else { // If 'correct' is not set to 1, print 'NO'
        printf("NO\n");
    }

    return 0;
}
