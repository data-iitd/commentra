

#include <stdio.h>
#include <string.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    // Read the number of rows and columns
    char grid[n][m];
    // Declare a 2D array to store the grid
    for (int i = 0; i < n; i++) {
        scanf("%s", grid[i]);
        // Read each row of the grid
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '.') {
                // Check if the cell is a dot
                if ((i + j) % 2 == 0) {
                    grid[i][j] = 'B';
                    // If the sum of row index and column index is even, color the cell 'B'
                } else {
                    grid[i][j] = 'W';
                    // Otherwise, color the cell 'W'
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%s\n", grid[i]);
        // Print each row of the grid
    }
    return 0;
}
// Print each row of the grid as a string



Translate the above C code to Java and end with comment "