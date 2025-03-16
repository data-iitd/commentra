#include <stdio.h>

int main() {
    char t[4][4]; // 4x4 grid to store input
    int black, white, correct;
    
    // Input the grid
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            scanf(" %c", &t[i][j]); // Read character input
        }
    }

    correct = 0; // Initialize correct flag

    // Check 3x3 subgrids
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            black = 0;
            white = 0;

            // Count black and white in the 2x2 subgrid
            for (int x = 0; x < 2; x++) {
                for (int y = 0; y < 2; y++) {
                    if (t[i + x][j + y] == '#') {
                        black++;
                    } else {
                        white++;
                    }
                }
            }

            // Check the conditions for correctness
            if (black == 0 || black == 3 || white == 0 || white == 3 || white == 4 || black == 4) {
                correct = 1;
                break;
            }
        }
        if (correct == 1) {
            break;
        }
    }

    // Output result
    if (correct == 1) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}

// <END-OF-CODE>
