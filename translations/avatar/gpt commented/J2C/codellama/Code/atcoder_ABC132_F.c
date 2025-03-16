#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int main() { 
    // Define the modulo constant for calculations to prevent overflow
    long mod = 1000000007; 
    
    // Initialize scanner to read input values
    int n, k; 
    scanf("%d %d", &n, &k); 
    
    // Create a list to store the lengths of segments
    int *len = (int *) malloc(sizeof(int) * n); 
    
    // Initialize the starting point for segment calculation
    int l = 1; 
    
    // Calculate the lengths of segments based on the value of n
    int q = 0; 
    while (l <= n) { 
        // Calculate the right endpoint of the current segment
        int r = n / (n / l); 
        // Add the length of the current segment to the list
        len[q++] = r - l + 1; 
        // Move to the next segment
        l = r + 1; 
    } 
    
    // Initialize a dynamic programming array to store results
    long *dp = (long *) malloc(sizeof(long) * k * (q + 1)); 
    
    // Fill the dp array for the first segment
    for (int j = 1; j <= q; j++) { 
        dp[j] = len[j - 1] + dp[j - 1]; 
    } 
    
    // Fill the dp array for subsequent segments
    for (int i = 1; i < k; i++) { 
        for (int j = 1; j <= q; j++) { 
            // Calculate the number of ways to form segments
            dp[i * (q + 1) + j] = dp[i * (q + 1) + j - 1] + 
                                  dp[(i - 1) * (q + 1) + q - j + 1] * len[j - 1]; 
            // Apply modulo to keep the value within limits
            dp[i * (q + 1) + j] %= mod; 
        } 
    } 
    
    // Output the final result, which is the number of ways to form k segments
    printf("%ld\n", dp[k * (q + 1) - 1]); 
    
    // Free the memory allocated for the list
    free(len); 
    // Free the memory allocated for the dp array
    free(dp); 
    
    return 0; 
} 

