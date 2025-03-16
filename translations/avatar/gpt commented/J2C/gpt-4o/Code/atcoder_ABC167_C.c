#include <stdio.h>
#include <limits.h>
#include <math.h>

int main() {
    // Read the number of rows (n), columns (m), and the minimum required value (x)
    int n, m, x;
    scanf("%d %d %d", &n, &m, &x);
    
    // Initialize a 2D array to store the input values
    int a[n][m + 1];
    
    // Read the values into the 2D array
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= m; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    
    // Initialize the minimum value to a large number
    int min = INT_MAX;
    
    // Iterate through all possible combinations of rows using bit manipulation
    for (int i = 0; i < (1 << n); i++) {
        // Initialize an array to store the sum of the selected rows
        int res[m + 1];
        for (int k = 0; k <= m; k++) {
            res[k] = 0; // Initialize the result array
        }
        
        // Calculate the sum of the selected rows
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) { // Check if the j-th row is included
                for (int k = 0; k <= m; k++) {
                    res[k] += a[j][k];
                }
            }
        }
        
        // Check if the current combination meets the minimum requirement for each column
        int flag = 1; // Assume valid
        for (int j = 1; j <= m; j++) {
            if (res[j] < x) {
                flag = 0; // Not valid
                break;
            }
        }
        
        // If the combination is valid, update the minimum value found
        if (flag) {
            min = (min < res[0]) ? min : res[0]; // Update min if res[0] is smaller
        }
    }
    
    // Output the result: -1 if no valid combination was found, otherwise the minimum value
    if (min == INT_MAX) {
        printf("-1\n");
    } else {
        printf("%d\n", min);
    }
    
    return 0;
}
