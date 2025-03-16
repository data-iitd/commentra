
#include <stdio.h>

int main() {
    char t[3][3];  // Declare a 3x3 array to store the input data.
    int i, j;  // Declare variables i and j for loop iteration.
    int black = 0;  // Initialize the count of black cells to 0.
    int white = 0;  // Initialize the count of white cells to 0.
    int correct = 0;  // Initialize the correct flag to 0.

    // Loop to take input and store it in the array t.
    for (i = 0; i < 3; i++) {
        scanf("%s", t[i]);  // Take input and store it in the current row of t.
    }

    // Nested loop to iterate over the 3x3 grid formed by the first 3 rows and columns of t.
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
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
    }

    // Print 'YES' if correct is 1, otherwise print 'NO'.
    if (correct == 1) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}
