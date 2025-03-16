#include <stdio.h> // Include standard input-output library

int main() {
    int N, M; // Declare variables for grid size and number of operations
    scanf("%d %d", &N, &M); // Read the first two integers

    // Initialize a 2D array 'black' with dimensions (N+2) x (N+2)
    int black[N + 2][N + 2]; 
    for (int i = 0; i < N + 2; i++) {
        for (int j = 0; j < N + 2; j++) {
            black[i][j] = 0; // Initialize all elements to 0
        }
    }

    // Loop through M operations
    for (int m = 1; m <= M; m++) {
        int x, y; // Declare variables for coordinates
        scanf("%d %d", &x, &y); // Read the coordinates

        // Increment the elements in the 'black' array within the 3x3 neighborhood of (x, y)
        for (int xx = x - 1; xx <= x + 1; xx++) {
            for (int yy = y - 1; yy <= y + 1; yy++) {
                if (++black[xx][yy] == 9) { // Increment the element and check if it reaches 9
                    printf("%d\n", m); // Print the current operation number
                    return 0; // Exit the program
                }
            }
        }
    }

    // If no element reaches 9 after all operations, print -1
    printf("-1\n");
    return 0; // Return success
}

// <END-OF-CODE>
