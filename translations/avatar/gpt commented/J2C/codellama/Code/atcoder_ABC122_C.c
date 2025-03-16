#include <stdio.h>
#include <stdlib.h>

// Define a constant for the modulo value
const long mod = 1000000007;

int main() {
    // Create a Scanner object to read input
    int n, q;
    char *c;
    int **range;
    int *frag, *rui;
    
    // Read the number of characters (n) and the number of queries (q)
    scanf("%d %d", &n, &q);
    
    // Read the character array from input
    c = (char *)malloc((n + 1) * sizeof(char));
    scanf("%s", c);
    
    // Initialize a 2D array to store the ranges for each query
    range = (int **)malloc(q * sizeof(int *));
    for (int i = 0; i < q; i++) {
        range[i] = (int *)malloc(2 * sizeof(int));
    }
    
    // Read the ranges for each query
    for (int i = 0; i < q; i++) {
        scanf("%d %d", &range[i][0], &range[i][1]);
    }
    
    // Initialize arrays to track fragments and cumulative sums
    frag = (int *)malloc((n + 1) * sizeof(int));
    rui = (int *)malloc((n + 1) * sizeof(int));
    
    // Loop through the character array to count occurrences of "AC"
    for (int i = 2; i <= n; i++) {
        // Check if the current and previous characters form "AC"
        if (c[i - 2] == 'A' && c[i - 1] == 'C') {
            frag[i]++; // Increment the fragment count
        }
        // Update the cumulative sum of fragments
        rui[i] = rui[i - 1] + frag[i];
    }
    
    // Process each query to find the number of "AC" in the specified range
    for (int i = 0; i < q; i++) {
        int left = range[i][0];   // Get the left index of the query
        int right = range[i][1];  // Get the right index of the query
        
        // Calculate and print the result for the current query
        printf("%d\n", rui[right] - rui[left]);
    }
    
    // Free memory
    free(c);
    for (int i = 0; i < q; i++) {
        free(range[i]);
    }
    free(range);
    free(frag);
    free(rui);
    
    return 0;
}

