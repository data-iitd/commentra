#include <stdio.h>

#define MOD 1000000007

int main() {
    int n, p;
    scanf("%d", &n); // Read the value of n from standard input
    scanf("%d", &p); // Read the value of p from standard input

    long long mdans[p];
    for (int index = 0; index < p; index++) {
        scanf("%lld", &mdans[index]); // Read each value into the array mdans
    }

    long long dp[n+1];
    dp[0] = 1; // Initialize the first element of dp array
    dp[1] = 1; // Initialize the second element of dp array

    for (int i = 0; i < p; i++) {
        if (mdans[i] == 1) { // Check if the value 1 is in the array mdans
            dp[1] = 0; // Set dp[1] to 0 if 1 is in the array
        }
    }

    for (int i = 2; i <= n; i++) {
        int isInMdans = 0;
        for (int j = 0; j < p; j++) {
            if (mdans[j] == i) { // Check if the current value i is in the array mdans
                isInMdans = 1; // Set isInMdans to 1 if i is in the array
                break; // Break out of the loop if i is in the array
            }
        }
        if (isInMdans) { // Skip to the next iteration if i is in the array
            continue;
        }
        dp[i] = (dp[i-1] + dp[i-2]) % MOD; // Calculate dp[i] as the sum of dp[i-1] and dp[i-2], modulo MOD
    }

    printf("%lld\n", dp[n]); // Print the value at dp[n]
    return 0;
}
