#include <stdio.h>

int main() {
    int n, m;
    // Read two integers n and m from input
    scanf("%d %d", &n, &m);

    // Initialize a 2D array to store the resulting grid
    char grid[n][m + 1]; // +1 for the null terminator

    // Iterate over each row index i from 0 to n-1
    for (int i = 0; i < n; i++) {
        // Read a string input for the current row
        scanf("%s", grid[i]);

        // Iterate over each column index j from 0 to m-1
        for (int j = 0; j < m; j++) {
            // Check if the current cell is empty (represented by '.')
            if (grid[i][j] == '.') {
                // Assign 'W' or 'B' based on the parity of the sum of indices (i + j)
                if ((i + j) % 2 == 0) {
                    grid[i][j] = 'B';  // Assign 'B' for even sums
                } else {
                    grid[i][j] = 'W';  // Assign 'W' for odd sums
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
