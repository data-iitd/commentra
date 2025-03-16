#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    // Compare the first elements of the rows for sorting in descending order
    return (*(int *)b - *(int *)a);
}

int main() {
    // Read the number of rows (n) from user input
    int n;
    scanf("%d", &n);

    // Allocate memory for the 2D array (matrix) m
    int **m = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        m[i] = (int *)malloc(2 * sizeof(int)); // Assuming each row has 2 integers
        scanf("%d %d", &m[i][0], &m[i][1]); // Read two integers for each row
    }

    // Sort the matrix m in descending order based on the first element of each row
    qsort(m, n, sizeof(int *), compare);

    // Initialize a variable a with the first row of the sorted matrix
    int *a = m[0];

    // Iterate through the remaining rows of the sorted matrix
    for (int i = 1; i < n; i++) {
        // Check if the second element of the current row is greater than the second element of the previous row
        if (m[i][1] > a[1]) {
            // If true, print 'Happy Alex' and exit the loop
            printf("Happy Alex\n");
            break;
        }
        // Update a to the current row for the next iteration
        a = m[i];
    }
    // If the loop completes without finding a greater second element, print 'Poor Alex'
    if (a == m[n-1]) {
        printf("Poor Alex\n");
    }

    // Free allocated memory
    for (int i = 0; i < n; i++) {
        free(m[i]);
    }
    free(m);

    return 0;
}

// <END-OF-CODE>
