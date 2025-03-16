#include <stdio.h>  // Including standard input-output library
#include <stdlib.h> // Including standard library for dynamic memory allocation
#include <stdbool.h> // Including library for boolean type
#include <string.h> // Including string library for string manipulation

#define MAX_SIZE 1000 // Defining a maximum size for the grid

int main() {
    int n, m; // Variables for number of rows and number of banned cells
    scanf("%d %d", &n, &m); // Reading the number of rows and banned cells

    bool bannedRows[MAX_SIZE] = {false}; // Array to track banned rows
    bool bannedCols[MAX_SIZE] = {false}; // Array to track banned columns

    for (int i = 0; i < m; i++) {
        int r, c; // Variables for row and column of banned cells
        scanf("%d %d", &r, &c); // Reading banned cell coordinates

        if (r > 1 && r < n) bannedRows[r] = true; // Marking the row as banned
        if (c > 1 && c < n) bannedCols[c] = true; // Marking the column as banned
    }

    int answer = (n - 2) * 2; // Initializing answer as the total number of cells in the grid minus the banned cells
    for (int i = 1; i < n; i++) {
        if (bannedRows[i]) answer--; // Subtracting the number of banned rows
    }
    for (int j = 1; j < n; j++) {
        if (bannedCols[j]) answer--; // Subtracting the number of banned columns
    }

    if (n % 2 != 0) {
        // Special case when the number of rows is odd
        int mid = (n + 1) / 2; // Finding the middle row
        if (!bannedRows[mid] && !bannedCols[mid]) {
            // If the middle cell is not banned, decrement the answer
            answer--;
        }
    }

    printf("%d\n", answer); // Printing the answer
    return 0; // Returning 0 to indicate successful execution
}

// <END-OF-CODE>
