#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007

int main() {
    // Initialize variables for n and k
    int n, k;
    
    // Read the values of n and k from input
    scanf("%d %d", &n, &k);
    
    // Create an array to store the lengths of segments
    int *len = (int *)malloc(n * sizeof(int));
    int len_size = 0;
    
    // Initialize the starting point for segment calculation
    int l = 1;
    
    // Calculate the lengths of segments based on the value of n
    while (l <= n) {
        // Calculate the right endpoint of the current segment
        int r = n / (n / l);
        // Add the length of the current segment to the array
        len[len_size++] = r - l + 1;
        // Move to the next segment
        l = r + 1;
    }
    
    // Initialize a dynamic programming array to store results
    long long *dp = (long long *)malloc((k * (len_size + 1)) * sizeof(long long));
    
    // Fill the dp array for the first segment
    for (int j = 1; j <= len_size; j++) {
        dp[j] = len[j - 1] + dp[j - 1];
    }
    
    // Fill the dp array for subsequent segments
    for (int i = 1; i < k; i++) {
        for (int j = 1; j <= len_size; j++) {
            // Calculate the number of ways to form segments
            dp[i * (len_size + 1) + j] = (dp[i * (len_size + 1) + j - 1] + 
                                           dp[(i - 1) * (len_size + 1) + len_size - j + 1] * len[j - 1]) % MOD;
        }
    }
    
    // Output the final result, which is the number of ways to form k segments
    printf("%lld\n", dp[k * (len_size + 1) - 1]);
    
    // Free allocated memory
    free(len);
    free(dp);
    
    return 0;
}

// <END-OF-CODE>
