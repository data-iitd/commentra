#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main() {
    // Take input of number of test cases and number of elements in each test case
    int n, x;
    scanf("%d %d", &n, &x);

    // Initialize an array 'a' to store the given elements
    int *a = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // Initialize a 2D array 'b' of size n x n
    int **b = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        b[i] = (int *)malloc(n * sizeof(int));
    }

    // Iterate through each row of list 'a'
    for (int i = 0; i < n; i++) {
        // Initialize a variable 'm' to store the minimum element in the current row
        int m = a[i];

        // Iterate through each column of list 'b'
        for (int j = 0; j < n; j++) {
            // Calculate the index 'k' based on the current row and column indices
            int k = i - j;

            // If the index 'k' is negative, add the size of list 'n' to make it positive
            if (k < 0) {
                k += n;
            }

            // Update the minimum value of 'm' with the minimum value of 'a[k]'
            if (a[k] < m) {
                m = a[k];
            }

            // Update the corresponding cell in list 'b' with the minimum value of 'm'
            b[j][i] = m;
        }
    }

    // Initialize a variable 'm' with a large value to keep track of the minimum sum
    long long min_sum = LLONG_MAX;

    // Iterate through each row of list 'b'
    for (int i = 0; i < n; i++) {
        // Calculate the sum of elements in the current row and add 'x * i' to it
        long long sum_row = 0;
        for (int j = 0; j < n; j++) {
            sum_row += b[i][j];
        }
        sum_row += x * i;

        // Update the minimum value of 'min_sum' with the sum of the current row
        if (sum_row < min_sum) {
            min_sum = sum_row;
        }
    }

    // Print the minimum sum
    printf("%lld\n", min_sum);

    // Free allocated memory
    free(a);
    for (int i = 0; i < n; i++) {
        free(b[i]);
    }
    free(b);

    return 0;
}

// <END-OF-CODE>
