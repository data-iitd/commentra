
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Create a Scanner object to read input from the user
    int n;
    scanf("%d", &n);

    // Initialize an array of size n to hold the integers
    int a[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }

    // Create a list to store the result pairs
    int r[n][2];
    int r_size = 0;

    // Variable to track the index of the element with the maximum absolute value
    int m = 0;

    // Find the index of the element with the maximum absolute value
    for (int i = 1; i < n; ++i) {
        if (abs(a[m]) < abs(a[i])) {
            m = i;
        }
    }

    // Generate pairs of indices based on the sign of the maximum absolute value element
    for (int i = 0; i < n; ++i) {
        if ((a[m] >= 0) ^ (a[i] >= 0)) {
            r[r_size][0] = m + 1;
            r[r_size][1] = i + 1;
            r_size++;
        }
    }

    // If the maximum absolute value element is non-negative
    if (a[m] >= 0) {
        // Add pairs of consecutive indices in ascending order
        for (int i = 1; i < n; ++i) {
            r[r_size][0] = i;
            r[r_size][1] = i + 1;
            r_size++;
        }
    } else {
        // If the maximum absolute value element is negative, add pairs in descending order
        for (int i = n; i > 1; --i) {
            r[r_size][0] = i - 1;
            r[r_size][1] = i;
            r_size++;
        }
    }

    // Print the size of the result list
    printf("%d\n", r_size);

    // Print each pair in the result list
    for (int i = 0; i < r_size; ++i) {
        printf("%d %d\n", r[i][0], r[i][1]);
    }

    return 0;
}
