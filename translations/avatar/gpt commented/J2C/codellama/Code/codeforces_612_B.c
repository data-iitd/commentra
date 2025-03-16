#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    // Create a Scanner object to read input from the console
    int n;
    scanf("%d", &n);
    
    // Initialize a dp array to store the indices of the input elements
    int dp[200001];
    
    // Populate the dp array with the indices of the input elements
    for (int i = 0; i < n; i++) {
        // Read the next integer and store its index in the dp array
        scanf("%d", &dp[i]);
    }
    
    // Initialize a variable to accumulate the result
    long ans = 0;
    
    // Calculate the total distance between consecutive elements in the dp array
    for (int i = 2; i <= n; i++) {
        // Add the absolute difference of indices of consecutive elements to ans
        ans += abs(dp[i] - dp[i - 1]);
    }
    
    // Output the final result
    printf("%ld\n", ans);
    
    // End of code
    return 0;
}