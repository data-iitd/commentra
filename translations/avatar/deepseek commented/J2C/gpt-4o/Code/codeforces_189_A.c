#include <stdio.h>
#include <limits.h>

int main() {
    // Initialize variables
    int n;
    scanf("%d", &n);
    
    int maxn = 4010;
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    
    // Store the coin values in an array
    int arr[3] = {a, b, c};
    
    // Initialize a dp array with all elements set to INT_MIN
    int dp[maxn];
    for (int i = 0; i < maxn; i++) {
        dp[i] = INT_MIN;
    }
    
    // Set the base case where dp[0] is 0
    dp[0] = 0;
    
    // Iterate over the coin values and update the dp array
    for (int i = 0; i < 3; i++) {
        for (int j = arr[i]; j < maxn; j++) {
            if (dp[j - arr[i]] != INT_MIN) {
                dp[j] = (dp[j] > dp[j - arr[i]] + 1) ? dp[j] : (dp[j - arr[i]] + 1);
            }
        }
    }
    
    // Print the value of dp[n]
    printf("%d\n", dp[n]);
    
    return 0;
}
// <END-OF-CODE>
