

#include <stdio.h>
#include <limits.h>

int main() {
    // Initialize variables for binary search tree traversal
    int n, m, x, min = INT_MAX;

    // Read the number of rows and columns from the input
    scanf("%d %d", &n, &m);

    // Read the 2D array 'a' from the input
    int a[n][m + 1];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= m; j++) {
            scanf("%d", &a[i][j]); // Read an element of the array 'a'
        }
    }

    // Read the value to search for from the input
    scanf("%d", &x);

    // Perform binary tree traversal
    for (int i = 0; i < (1 << n); i++) {
        int status[n], res[m + 1];

        // Set the status of each node based on the current binary tree node
        for (int j = 0; j < n; j++) {
            if ((1 & i >> j) == 1) { // If the current binary tree node has a '1' at the j-th position
                status[j] = 1; // Set the status of the j-th node to '1'
            }
        }

        // Initialize result array for the current binary tree node
        for (int j = 0; j <= m; j++) {
            res[j] = 0; // Set the sum of elements in the current column to 0
        }

        // Calculate the sum of elements in the current row for each column
        for (int j = 0; j < n; j++) {
            if (status[j] == 1) { // If the j-th node is included in the current binary tree
                for (int k = 0; k <= m; k++) {
                    res[k] += a[j][k]; // Add the element in the current column to the sum
                }
            }
        }

        // Check if the sum of elements in the current row for each column is greater than or equal to 'x'
        bool flag = true;
        for (int j = 1; j <= m; j++) {
            if (res[j] < x) { // If the sum of elements in the current column is less than 'x'
                flag = false; // Set the flag to 'false' and break the loop
                break;
            }
        }

        // If the sum of elements in all columns for the current binary tree node is greater than or equal to 'x', update the minimum value
        if (flag) {
            min = (min < res[0]? min : res[0]); // Update the minimum value with the sum of elements in the first column
        }
    }

    // Print the minimum value if it exists, otherwise print '-1'
    if (min == INT_MAX) {
        printf("-1\n");
    } else {
        printf("%d\n", min);
    }

    return 0;
}
