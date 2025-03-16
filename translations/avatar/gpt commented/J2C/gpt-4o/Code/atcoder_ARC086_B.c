#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    // Read the number of elements in the array
    int n;
    scanf("%d", &n);
    
    // Initialize an array of size n to hold the integers
    int *a = (int *)malloc(n * sizeof(int));
    
    // Populate the array with user input
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    
    // Create a list to store the result pairs
    char **r = (char **)malloc(n * n * sizeof(char *));
    int r_count = 0;
    
    // Variable to track the index of the element with the maximum absolute value
    int m = 0;
    
    // Find the index of the element with the maximum absolute value
    for (int i = 1; i < n; ++i) {
        if (fabs(a[m]) < fabs(a[i])) {
            m = i;
        }
    }
    
    // Generate pairs of indices based on the sign of the maximum absolute value element
    for (int i = 0; i < n; ++i) {
        if ((a[m] >= 0) ^ (a[i] >= 0)) {
            r[r_count] = (char *)malloc(20 * sizeof(char)); // Allocate space for the string
            sprintf(r[r_count], "%d %d", m + 1, i + 1);
            r_count++;
        }
    }
    
    // If the maximum absolute value element is non-negative
    if (a[m] >= 0) {
        // Add pairs of consecutive indices in ascending order
        for (int i = 1; i < n; ++i) {
            r[r_count] = (char *)malloc(20 * sizeof(char)); // Allocate space for the string
            sprintf(r[r_count], "%d %d", i, i + 1);
            r_count++;
        }
    } else {
        // If the maximum absolute value element is negative, add pairs in descending order
        for (int i = n; i > 1; --i) {
            r[r_count] = (char *)malloc(20 * sizeof(char)); // Allocate space for the string
            sprintf(r[r_count], "%d %d", i, i - 1);
            r_count++;
        }
    }
    
    // Print the size of the result list
    printf("%d\n", r_count);
    
    // Print each pair in the result list
    for (int i = 0; i < r_count; ++i) {
        printf("%s\n", r[i]);
        free(r[i]); // Free the allocated memory for each string
    }
    
    // Free the allocated memory for the array and result list
    free(a);
    free(r);
    
    return 0;
}

// <END-OF-CODE>
