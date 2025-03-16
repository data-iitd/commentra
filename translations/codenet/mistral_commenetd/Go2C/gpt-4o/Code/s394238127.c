#include <stdio.h>

int main() {
    // Declare a 3x3 2D array 'c' to store input matrix elements
    int c[3][3];

    // Initialize two 1D arrays 'a' and 'b' to store differences between corresponding elements of rows and columns
    int a[3] = {0}, b[3] = {0};

    // Read input matrix elements from stdin and store them in 'c' array
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            // Read each element from stdin
            scanf("%d", &c[i][j]);

            // Add a comment explaining the current loop iteration
            // This comment will be helpful for understanding the code flow
            printf("Reading element %d,%d from input matrix\n", i, j);
        }
    }

    // Calculate differences between corresponding elements of rows and columns and store them in 'a' and 'b' arrays
    b[0] = c[0][0] - a[0];
    b[1] = c[0][1] - a[0];
    b[2] = c[0][2] - a[0];
    a[1] = c[1][0] - c[0][0];
    a[2] = c[2][0] - c[0][0];

    // Check if 'a' and 'b' arrays are equal to the differences between corresponding elements of the first row and the first column of the matrix
    if (a[1] == c[1][1] - c[0][1] && a[1] == c[1][2] - c[0][2] &&
        a[2] == c[2][1] - c[0][1] && a[2] == c[2][2] - c[0][2]) {
        // Print "Yes" if the condition is true, indicating that the matrix is a diagonal matrix
        printf("Yes\n");
    } else {
        // Print "No" if the condition is false, indicating that the matrix is not a diagonal matrix
        printf("No\n");
    }

    return 0;
}

// <END-OF-CODE>
