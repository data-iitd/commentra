#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, a, b, c;
    scanf("%d %d %d %d", &n, &a, &b, &c);
    int maxn = 4010;
    int dp[maxn];

    // Initialize the dp array with all elements set to -2147483648
    for (int i = 0; i < maxn; i++) {
        dp[i] = -2147483648;
    }

    // Set the base case where dp[0] is 0
    dp[0] = 0;

    // Array to store the coin values
    int arr[] = {a, b, c};

    // Iterate over the coin values and update the dp array
    for (int i = 0; i < 3; i++) {
        for (int j = arr[i]; j < maxn; j++) {
            dp[j] = dp[j] > dp[j - arr[i]] + 1 ? dp[j] : dp[j - arr[i]] + 1;
        }
    }

    // Print the value of dp[n]
    printf("%d\n", dp[n]);

    return 0;
}

