#include <stdio.h>

int main() {
    // Define the number of rows (n) and columns (m) of the grid
    int n, m;
    scanf("%d %d", &n, &m);

    // Initialize a 2D array to store the grid
    char grid[n][m + 1]; // +1 for the null terminator

    // Iterate through each row 'i' in the grid
    for (int i = 0; i < n; i++) {
        // Read the row as a string from user input
        scanf("%s", grid[i]);

        // Iterate through each cell 'j' in the row
        for (int j = 0; j < m; j++) {
            // If the cell contains a '.', assign it a color based on its position in the grid
            if (grid[i][j] == '.') {
                if ((i + j) % 2) {  // If the row index and column index have different parity
                    grid[i][j] = 'W'; // Assign the cell the color 'W'
                } else {
                    grid[i][j] = 'B'; // Assign the cell the color 'B'
                }
            }
        }
    }

    // Print each row of the grid
    for (int i = 0; i < n; i++) {
        printf("%s\n", grid[i]);
    }

    return 0;
}

// <END-OF-CODE>
