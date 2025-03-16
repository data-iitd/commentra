
#include <stdio.h>

int main() {
    // Define the number of rows (n) and columns (m) of the grid
    int n, m;
    scanf("%d %d", &n, &m);

    // Initialize an empty list 'l' to store the rows of the grid
    char l[n][m];

    // Iterate through each row 'i' in the grid
    for (int i = 0; i < n; i++) {
        // Read the row as a string from user input
        for (int j = 0; j < m; j++) {
            char c;
            scanf(" %c", &c);
            l[i][j] = c;
        }
    }

    // Iterate through each cell 'j' in the row
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // If the cell contains a '.', assign it a color based on its position in the grid
            if (l[i][j] == '.') {
                if ((i + j) % 2) {  // If the row index and column index have different parity
                    l[i][j] = 'W';   // Assign the cell the color 'W'
                } else {
                    l[i][j] = 'B';   // Assign the cell the color 'B'
                }
            }
        }
    }

    // Print each row of the grid
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%c", l[i][j]);
        }
        printf("\n");
    }

    return 0;
}
