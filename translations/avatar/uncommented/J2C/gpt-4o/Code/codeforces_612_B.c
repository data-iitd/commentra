#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    
    int dp[200001] = {0}; // Initialize the array to 0
    for (int i = 0; i < n; i++) {
        int value;
        scanf("%d", &value);
        dp[value] = i;
    }
    
    long long ans = 0; // Use long long for large sums
    for (int i = 2; i <= n; i++) {
        ans += abs(dp[i] - dp[i - 1]);
    }
    
    printf("%lld\n", ans); // Print the result
    return 0;
}

// <END-OF-CODE>
