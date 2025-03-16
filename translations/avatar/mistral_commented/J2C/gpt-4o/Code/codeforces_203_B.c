#include <stdio.h>  // Include standard input-output header

int main() {
    int N, M;  // Declare variables for grid size and number of stones
    scanf("%d %d", &N, &M);  // Read the size of the grid and number of stones

    int black[N + 2][N + 2];  // Create a 2D array of size (N+2) x (N+2) to represent the grid

    // Initialize the black array to 0
    for (int i = 0; i < N + 2; i++) {
        for (int j = 0; j < N + 2; j++) {
            black[i][j] = 0;
        }
    }

    for (int m = 1; m <= M; m++) {  // Iterate M times, once for each stone to be placed
        int x, y;  // Declare variables for the coordinates of the stone
        scanf("%d %d", &x, &y);  // Read the x and y coordinates of the next stone to be placed

        for (int xx = x - 1; xx <= x + 1; xx++) {  // Iterate over all the neighboring cells in the x-direction
            for (int yy = y - 1; yy <= y + 1; yy++) {  // Iterate over all the neighboring cells in the y-direction
                if (++black[xx][yy] == 9) {  // Check if the number of black cells around this cell becomes 9
                    printf("%d\n", m);  // If so, print the index of the stone that caused this condition and return
                    return 0;  // Exit the program
                }
            }
        }
    }

    printf("-1\n");  // If we finish iterating over all the stones without finding one that has 9 black neighbors, print -1 and return
    return 0;  // Exit the program
}

// <END-OF-CODE>
