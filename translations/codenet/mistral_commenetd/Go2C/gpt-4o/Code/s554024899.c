#include <stdio.h>
#include <stdlib.h>

#define ROWS 3

int main() {
    // Initialize the 2D array
    int a[ROWS][7] = {
        {1, 3, 5, 7, 8, 10, 12},
        {4, 6, 9, 11, 0, 0, 0}, // Padding with zeros for uniformity
        {2, 0, 0, 0, 0, 0, 0}   // Padding with zeros for uniformity
    };

    int x, y;
    // Read the first two integers from standard input
    scanf("%d %d", &x, &y);

    // Initialize indices for x and y
    int xt = -1, yt = -1;

    // Iterate through the 2D array
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < 7; j++) {
            if (a[i][j] == 0) break; // Stop if we hit the padding zeros
            if (a[i][j] == x) xt = i; // Store index of x
            if (a[i][j] == y) yt = i; // Store index of y
        }
    }

    // Check if the indices are equal and print the result
    if (xt == yt) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    return 0;
}

// <END-OF-CODE>
