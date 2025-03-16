#include <stdio.h>
#include <stdlib.h> // For abs function
#include <math.h>   // For fabs function

int main() {
    int n;
    scanf("%d", &n); // Reading the size of the array
    int *a = (int *)malloc(n * sizeof(int)); // Dynamically allocating the array 'a' of size 'n'

    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]); // Filling the array 'a' with 'n' integers from input
    }

    int m = 0; // Initializing the index of the maximum absolute value element

    // Finding the index of the element with the maximum absolute value in the array 'a'
    for (int i = 1; i < n; ++i) {
        if (fabs(a[m]) < fabs(a[i])) {
            m = i;
        }
    }

    // Array to store the operations
    char **r = (char **)malloc(n * n * sizeof(char *));
    int r_count = 0; // Counter for the number of operations

    // Finding pairs of indices where one element is non-negative and the other is negative
    for (int i = 0; i < n; ++i) {
        if ((a[m] >= 0) ^ (a[i] >= 0)) { // Using XOR to check if one is non-negative and the other is negative
            r[r_count] = (char *)malloc(20 * sizeof(char)); // Allocate space for the operation string
            sprintf(r[r_count], "%d %d", m + 1, i + 1); // Adding the operation to the array 'r'
            r_count++;
        }
    }

    // Generating operations based on whether the maximum absolute value element is non-negative or negative
    if (a[m] >= 0) {
        for (int i = 1; i < n; ++i) {
            r[r_count] = (char *)malloc(20 * sizeof(char)); // Allocate space for the operation string
            sprintf(r[r_count], "%d %d", i + 1, i + 2); // Adding the operation to the array 'r'
            r_count++;
        }
    } else {
        for (int i = n; i > 1; --i) {
            r[r_count] = (char *)malloc(20 * sizeof(char)); // Allocate space for the operation string
            sprintf(r[r_count], "%d %d", i, i - 1); // Adding the operation to the array 'r'
            r_count++;
        }
    }

    // Printing the number of operations and the operations themselves
    printf("%d\n", r_count);
    for (int i = 0; i < r_count; ++i) {
        printf("%s\n", r[i]);
        free(r[i]); // Freeing the allocated memory for each operation string
    }

    free(r); // Freeing the operations array
    free(a); // Freeing the array 'a'
    return 0;
}

// <END-OF-CODE>
