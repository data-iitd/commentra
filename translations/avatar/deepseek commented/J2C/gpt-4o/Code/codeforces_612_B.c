#include <stdio.h>
#include <stdlib.h> // For abs function

int main() {
    int n;
    scanf("%d", &n); // Reading the integer n from the input
    int dp[200001] = {0}; // Initializing an array to store positions

    // Storing positions of the integers in the array dp
    for (int i = 0; i < n; i++) {
        int value;
        scanf("%d", &value);
        dp[value] = i;
    }

    long long ans = 0; // Initializing the answer variable to 0

    // Calculating the sum of absolute differences between consecutive positions
    for (int i = 2; i <= n; i++) {
        ans += abs(dp[i] - dp[i - 1]);
    }

    printf("%lld\n", ans); // Printing the final answer
    return 0;
}

// <END-OF-CODE>
