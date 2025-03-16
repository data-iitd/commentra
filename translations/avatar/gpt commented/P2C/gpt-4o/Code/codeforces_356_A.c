#include <stdio.h>
#include <stdlib.h>

int main() {
    // Read the values of n and m from input
    int n, m;
    scanf("%d %d", &n, &m);

    // Initialize an output array with zeros
    int *out = (int *)calloc(n, sizeof(int));

    // Create an array 'comp' that holds values from 2 to n+1 (inclusive)
    int *comp = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        comp[i] = i + 2;
    }

    // Process each of the m operations
    for (int op = 0; op < m; op++) {
        // Read the values of l, r, and x for the current operation
        int l, r, x;
        scanf("%d %d %d", &l, &r, &x);
        
        // Start from the left index l
        int t = l;

        // Continue processing while t is within the range [l, r]
        while (t <= r) {
            // Get the next value from the 'comp' array
            int next_val = comp[t - 1];
            
            // If the current position in 'out' is still 0 and t is not equal to x
            if (out[t - 1] == 0 && t != x) {
                // Set the output at position t-1 to x
                out[t - 1] = x;
            }
            
            // Update the 'comp' array at position t-1 based on the current value of t and x
            comp[t - 1] = (t >= x) ? (r + 1) : x;
            
            // Move to the next index as determined by next_val
            t = next_val;
        }
    }

    // Print the final output array
    for (int i = 0; i < n; i++) {
        printf("%d", out[i]);
        if (i < n - 1) {
            printf(" ");
        }
    }
    printf("\n");

    // Free allocated memory
    free(out);
    free(comp);

    return 0;
}

// <END-OF-CODE>
