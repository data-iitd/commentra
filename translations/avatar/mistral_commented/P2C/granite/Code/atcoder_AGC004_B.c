
#include <stdio.h>
#include <limits.h>

// Function to take input and convert it into list of integers
void main() {
    // Take input of number of test cases and number of elements in each test case
    int n, x;
    scanf("%d %d", &n, &x);

    // Initialize an array 'a' of size n to store the given elements
    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // Initialize a 2D array 'b' of size n x n with INT_MAX values
    int b[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            b[i][j] = INT_MAX;
        }
    }

    // Iterate through each row of array 'a'
    for (int i = 0; i < n; i++) {
        // Initialize a variable'm' to store the minimum element in the current row
        int m = a[i];

        // Iterate through each column of array 'b'
        for (int j = 0; j < n; j++) {
            // Calculate the index 'k' based on the current row and column indices
            int k = i - j;

            // If the index 'k' is negative, add the size of array 'n' to make it positive
            if (k < 0) {
                k += n;
            }

            // Update the minimum value of'm' with the minimum value of 'a[k]'
            m = (m < a[k])? m : a[k];

            // Update the corresponding cell in array 'b' with the minimum value of'm'
            b[j][i] = m;
        }
    }

    // Initialize a variable'm' with a large value to keep track of the minimum sum
    int m = INT_MAX;

    // Iterate through each row of array 'b'
    for (int i = 0; i < n; i++) {
        // Calculate the sum of elements in the current row and add 'x * i' to it
        int sum_row = 0;
        for (int j = 0; j < n; j++) {
            sum_row += b[j][i];
        }
        sum_row += x * i;

        // Update the minimum value of'm' with the sum of the current row
        m = (m < sum_row)? m : sum_row;
    }

    // Print the minimum sum
    printf("%d\n", m);
}

