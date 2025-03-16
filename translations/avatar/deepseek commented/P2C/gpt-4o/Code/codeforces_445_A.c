#include <stdio.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    // Read the number of rows and columns

    char grid[n][m + 1]; // +1 for the null terminator

    for (int i = 0; i < n; i++) {
        // Loop through each row
        scanf("%s", grid[i]);
        // Read the row as a string

        for (int j = 0; j < m; j++) {
            // Loop through each column in the row
            if (grid[i][j] == '.') {
                // Check if the cell is a dot
                if ((i + j) % 2 == 1) {
                    grid[i][j] = 'W';
                    // If the sum of row index and column index is odd, color the cell 'W'
                } else {
                    grid[i][j] = 'B';
                    // Otherwise, color the cell 'B'
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        printf("%s\n", grid[i]);
        // Print each row as a string
    }

    return 0;
}
// <END-OF-CODE>
