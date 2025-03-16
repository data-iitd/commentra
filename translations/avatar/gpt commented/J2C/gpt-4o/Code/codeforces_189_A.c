#include <stdio.h>
#include <limits.h>

int main() {
    // Read the total number of items (n) to be processed
    int n;
    scanf("%d", &n);
    
    // Define the maximum size for the dp array
    int maxn = 4010;
    
    // Read three integer values (a, b, c) which represent the sizes of items
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    
    // Store the sizes of items in an array for easier access
    int arr[3] = { a, b, c };
    
    // Initialize a dp array to store the maximum number of items that can be formed
    int dp[maxn];
    
    // Set all dp values to INT_MIN to indicate uncomputed states
    for (int i = 0; i < n; i++) {
        dp[i] = INT_MIN;
    }
    
    // Base case: zero items can be formed with zero size
    dp[0] = 0;
    
    // Iterate through each item size (a, b, c)
    for (int i = 0; i < 3; i++) {
        // Update the dp array for each possible size from the current item size
        for (int j = arr[i]; j < maxn; j++) {
            // Calculate the maximum number of items that can be formed
            if (dp[j - arr[i]] != INT_MIN) {
                dp[j] = (dp[j] > dp[j - arr[i]] + 1) ? dp[j] : (dp[j - arr[i]] + 1);
            }
        }
    }
    
    // Output the maximum number of items that can be formed with size n
    printf("%d\n", dp[n]);
    
    return 0;
}
// <END-OF-CODE>
