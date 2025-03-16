#include <stdio.h>
#include <stdlib.h>

// Define a constant for the modulo value
#define MOD 1000000007

int main() {
    // Read the number of characters (n) and the number of queries (q)
    int n, q;
    scanf("%d %d", &n, &q);
    
    // Read the character array from input
    char c[n + 1];
    scanf("%s", c);
    
    // Initialize a 2D array to store the ranges for each query
    int range[q][2];
    
    // Read the ranges for each query
    for (int i = 0; i < q; i++) {
        scanf("%d %d", &range[i][0], &range[i][1]);
    }
    
    // Initialize arrays to track fragments and cumulative sums
    int frag[n + 1]; // To count occurrences of "AC"
    int rui[n + 1];  // To store cumulative sums of fragments
    
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
    
    return 0;
}

