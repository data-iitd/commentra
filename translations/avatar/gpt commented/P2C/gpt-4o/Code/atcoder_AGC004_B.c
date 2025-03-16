#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main() {
    // Read input values: n (number of elements) and x (a multiplier)
    int n, x;
    scanf("%d %d", &n, &x);
    
    // Read the list of integers 'a' from input
    int *a = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    
    // Initialize a 2D array 'b' to store minimum values
    int **b = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        b[i] = (int *)malloc(n * sizeof(int));
    }
    
    // Fill the 2D array 'b' with minimum values from 'a'
    for (int i = 0; i < n; i++) {
        int m = a[i];  // Start with the current element
        for (int j = 0; j < n; j++) {
            int k = i - j;  // Calculate the index to wrap around
            if (k < 0) {
                k += n;  // Wrap around if index is negative
            }
            m = (m < a[k]) ? m : a[k];  // Update m to be the minimum value found
            b[j][i] = m;  // Store the minimum value in the 2D array 'b'
        }
    }
    
    // Initialize a large value for comparison
    long long m = LLONG_MAX;
    
    // Calculate the minimum sum of elements in each row of 'b' plus the weighted index
    for (int i = 0; i < n; i++) {
        long long sum = 0;
        for (int j = 0; j < n; j++) {
            sum += b[i][j];  // Sum the elements in the row
        }
        m = (m < sum + x * i) ? m : (sum + x * i);  // Update m with the minimum found
    }
    
    // Print the final minimum value
    printf("%lld\n", m);
    
    // Free allocated memory
    free(a);
    for (int i = 0; i < n; i++) {
        free(b[i]);
    }
    free(b);
    
    return 0;
}

// <END-OF-CODE>
