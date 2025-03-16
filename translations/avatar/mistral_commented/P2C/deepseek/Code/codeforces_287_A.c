#include <stdio.h>
#include <stdlib.h>

int main() {
    char t[4][4];
    int black = 0, white = 0, correct = 0;

    // Get input strings and store them in the 2D array 't'
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            scanf(" %c", &t[i][j]);
        }
    }

    // Loop through the first 3 rows of the 4x4 grid represented by array 't'
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            // Initialize black and white counters for the current cell
            black = 0;
            white = 0;

            // Check the current cell and its neighbors
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

            // Check the current cell and its neighbors for winning conditions
            if (black == 0 || black == 3 || white == 0 || white == 3 || white == 4 || black == 4) {
                correct = 1;
                break;
            }
        }
        if (correct == 1) {
            break;
        }
    }

    // Print the result
    if (correct == 1) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}

