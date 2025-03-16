#include <stdio.h>

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    
    // Initialize a 2D array to keep track of the black cells, with padding to avoid boundary checks
    int black[N + 2][N + 2];
    for (int i = 0; i < N + 2; i++) {
        for (int j = 0; j < N + 2; j++) {
            black[i][j] = 0;
        }
    }
    
    // Loop through each move
    for (int m = 1; m <= M; m++) {
        int x, y;
        scanf("%d %d", &x, &y);
        
        // Increment the count of black cells in the surrounding 3x3 area
        for (int xx = x - 1; xx <= x + 1; xx++) {
            for (int yy = y - 1; yy <= y + 1; yy++) {
                // Increment the count for the current cell
                black[xx][yy]++;
                if (black[xx][yy] == 9) { // Check if the count reaches 9
                    printf("%d\n", m); // Print the move number where the condition is met
                    return 0; // Exit the program
                }
            }
        }
    }
    
    // If no cell reached the count of 9 after all moves, print -1
    printf("-1\n");
    
    return 0;
}

