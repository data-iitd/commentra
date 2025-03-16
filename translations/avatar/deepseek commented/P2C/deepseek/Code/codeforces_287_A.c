#include <stdio.h>
#include <string.h>

#define MAX_ROWS 5
#define MAX_COLS 5

int main() {
    char t[MAX_ROWS][MAX_COLS];  // Initialize a 2D array to store the input data.
    int black = 0, white = 0, correct = 0;  // Initialize the counts and the correct flag.

    // Loop to take input and store it in the 2D array t.
    for (int i = 0; i < 4; i++) {
        scanf("%s", t[i]);
    }

    // Nested loop to iterate over the 3x3 grid formed by the first 3 rows and columns of t.
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            // Count the number of black and white cells in the current 2x2 subgrid.
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
                correct = 1;
                break;  // If conditions are met, set correct to 1 and break out of the loop.
            }

            black = 0;  // Reset the count of black cells.
            white = 0;  // Reset the count of white cells.
        }
        if (correct == 1) {
            break;
        }
    }

    // Print 'YES' if correct is 1, otherwise print 'NO'.
    if (correct == 1) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}
