
#include <stdio.h> // Include the standard input/output library

int main() {
    int N, M, x, y; // Declare variables for the dimensions of the grid, the number of moves, and the coordinates of the current move
    
    // Read the dimensions of the grid (N) and the number of moves (M)
    scanf("%d %d", &N, &M);
    
    // Initialize a 2D array to keep track of the black cells, with padding to avoid boundary checks
    int black[N + 2][N + 2] = {0};
    
    // Loop through each move
    for (int m = 1; m <= M; m++) {
        // Read the coordinates of the current move
        scanf("%d %d", &x, &y);
        
        // Increment the count of black cells in the surrounding 3x3 area
        for (int xx = x - 1; xx <= x + 1; xx++) {
            for (int yy = y - 1; yy <= y + 1; yy++) {
                // Increment the count for the current cell
                if (++black[xx][yy] == 9) { // Check if the count reaches 9
                    printf("%d\n", m); // Print the move number where the condition is met
                    return 0; // Exit the program
                }
            }
        }
    }
    
    // If no cell reached the count of 9 after all moves, print -1
    printf("-1\n");
    
    return 0; // Return 0 to indicate successful execution
}
