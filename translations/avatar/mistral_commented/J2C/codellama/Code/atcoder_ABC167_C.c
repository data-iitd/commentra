
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    // Initialize scanner to read input from the console
    int n, m, x, i, j, k, flag;
    scanf("%d %d", &n, &m); // Read the number of rows and columns from the input

    // Read the 2D array 'a' from the input
    int** a = (int**)malloc(n * sizeof(int*));
    for (i = 0; i < n; i++) {
        a[i] = (int*)malloc((m + 1) * sizeof(int));
        for (j = 0; j <= m; j++) {
            scanf("%d", &a[i][j]); // Read an element of the array 'a'
        }
    }

    // Initialize variables for binary search tree traversal
    int min = INT_MAX;
    scanf("%d", &x); // Value to search for

    // Perform binary tree traversal
    for (i = 0; i < pow(2, n); i++) {
        int* status = (int*)malloc(n * sizeof(int)); // Initialize status array for current binary tree node

        // Set the status of each node based on the current binary tree node
        for (j = 0; j < n; j++) {
            if ((1 & i >> j) == 1) { // If the current binary tree node has a '1' at the j-th position
                status[j] = 1; // Set the status of the j-th node to '1'
            }
        }

        // Initialize result array for the current binary tree node
        int* res = (int*)malloc((m + 1) * sizeof(int));

        // Calculate the sum of elements in the current row for each column
        for (j = 0; j < n; j++) {
            if (status[j] == 1) { // If the j-th node is included in the current binary tree
                for (k = 0; k <= m; k++) {
                    res[k] += a[j][k]; // Add the element in the current column to the sum
                }
            }
        }

        // Check if the sum of elements in the current row for each column is greater than or equal to 'x'
        flag = 1;
        for (j = 1; j <= m; j++) {
            if (res[j] < x) { // If the sum of elements in the current column is less than 'x'
                flag = 0; // Set the flag to 'false' and break the loop
                break;
            }
        }

        // If the sum of elements in all columns for the current binary tree node is greater than or equal to 'x', update the minimum value
        if (flag) {
            min = min < res[0] ? min : res[0]; // Update the minimum value with the sum of elements in the first column
        }
    }

    // Print the minimum value if it exists, otherwise print '-1'
    if (min == INT_MAX) {
        printf("-1\n");
    } else {
        printf("%d\n", min);
    }

    // Free memory
    for (i = 0; i < n; i++) {
        free(a[i]);
    }
    free(a);
    free(status);
    free(res);

    return 0;
}

