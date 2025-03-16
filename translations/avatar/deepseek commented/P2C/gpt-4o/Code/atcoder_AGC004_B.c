#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main() {
    // Read the values of n and x
    int n, x;
    scanf("%d %d", &n, &x);
    
    // Read the list of integers a
    int *a = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    
    // Initialize a 2D array b
    int **b = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        b[i] = (int *)malloc(n * sizeof(int));
    }
    
    // Calculate the minimum value in a circular array for each starting position i and ending position j
    for (int i = 0; i < n; i++) {
        int m = a[i];  // Initialize m with the current element
        for (int j = 0; j < n; j++) {
            int k = i - j;  // Calculate the index in the circular array
            if (k < 0) {
                k += n;  // Adjust k if it is negative
            }
            m = (m < a[k]) ? m : a[k];  // Update m with the minimum value in the circular array
            b[j][i] = m;  // Store the minimum value in b
        }
    }
    
    // Find the minimum sum of each row in b plus x times the row index
    long long min_value = LLONG_MAX;
    for (int i = 0; i < n; i++) {
        long long sum = 0;
        for (int j = 0; j < n; j++) {
            sum += b[i][j];
        }
        min_value = (min_value < sum + x * i) ? min_value : (sum + x * i);
    }
    
    // Print the minimum value found
    printf("%lld\n", min_value);
    
    // Free allocated memory
    free(a);
    for (int i = 0; i < n; i++) {
        free(b[i]);
    }
    free(b);

    return 0;
}

// <END-OF-CODE>
