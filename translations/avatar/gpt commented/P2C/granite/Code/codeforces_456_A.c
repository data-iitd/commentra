
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, j;
    int **m;

    // Read the number of rows (n) from user input
    scanf("%d", &n);

    // Allocate memory for the 2D array m
    m = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++) {
        m[i] = (int *)malloc(2 * sizeof(int));
    }

    // Read n rows of integers into the 2D array m
    for (i = 0; i < n; i++) {
        for (j = 0; j < 2; j++) {
            scanf("%d", &m[i][j]);
        }
    }

    // Sort the 2D array m in descending order based on the first element of each row
    qsort(m, n, sizeof(int *), cmp);

    // Initialize a variable a with the first row of the sorted array
    int *a = m[0];

    // Iterate through the remaining rows of the sorted array
    for (i = 1; i < n; i++) {
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
    if (i == n) {
        printf("Poor Alex\n");
    }

    // Free the memory allocated for the 2D array m
    for (i = 0; i < n; i++) {
        free(m[i]);
    }
    free(m);

    return 0;
}

int cmp(const void *a, const void *b) {
    // Compare the first element of two rows in the 2D array
    if (((int **)a)[0] > ((int **)b)[0]) {
        return -1;
    } else if (((int **)a)[0] < ((int **)b)[0]) {
        return 1;
    } else {
        return 0;
    }
}
