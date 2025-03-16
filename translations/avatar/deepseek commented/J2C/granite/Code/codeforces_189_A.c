

#include <stdio.h>

int main() {
    // Initialize variables
    int n, maxn = 4010, a, b, c;
    int arr[3], dp[maxn];
    
    // Read input from the user
    scanf("%d %d %d %d", &n, &maxn, &a, &b, &c);
    
    // Store the coin values in an array
    arr[0] = a;
    arr[1] = b;
    arr[2] = c;
    
    // Initialize dp array with all elements set to Integer.MIN_VALUE
    for (int i = 0; i < n; i++) {
        dp[i] = -100000000;
    }
    
    // Set the base case where dp[0] is 0
    dp[0] = 0;
    
    // Iterate over the coin values and update the dp array
    for (int i = 0; i < 3; i++) {
        for (int j = arr[i]; j < n; j++) {
            dp[j] = dp[j] > dp[j - arr[i]] + 1? dp[j] : dp[j - arr[i]] + 1;
        }
    }
    
    // Print the value of dp[n]
    printf("%d", dp[n]);
    
    // End of code
    return 0;
}
