

#include <stdio.h> // Include the standard input/output library

int main() {
    int N, M, x, y; // Declare variables for the size of the grid, number of operations, and coordinates of the current operation

    // Read the first integer input, which is the size of the grid
    scanf("%d", &N);

    // Read the second integer input, which is the number of operations
    scanf("%d", &M);

    // Initialize a 2D array 'black' with dimensions (N+2) x (N+2)
    int black[N + 2][N + 2] = {0};

    // Loop through M operations
    for (int m = 1; m <= M; m++) {
        // Read the x-coordinate of the current operation
        scanf("%d", &x);

        // Read the y-coordinate of the current operation
        scanf("%d", &y);

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

    return 0; // Return 0 to indicate successful execution
}
