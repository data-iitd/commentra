#include <stdio.h>

#define MOD 1000000007

int main() {
    int n, p;
    scanf("%d %d", &n, &p);

    // Create an array to store the blocked positions
    int blocked[p];
    for (int i = 0; i < p; i++) {
        scanf("%d", &blocked[i]);
    }

    // Initialize an array to store the number of ways to reach each position
    long long dp[n+1];

    // Base cases: There is 1 way to reach the 0th and 1st positions
    dp[0] = 1;
    dp[1] = 1;

    // Check if the first position is blocked
    int blocked_first = 0;
    for (int i = 0; i < p; i++) {
        if (blocked[i] == 1) {
            blocked_first = 1;
            break;
        }
    }
    if (blocked_first) {
        dp[1] = 0;
    }

    // Iterate through positions from 2 to n to calculate the number of ways to reach each position
    for (int i = 2; i <= n; i++) {
        // Check if the current position is blocked
        int is_blocked = 0;
        for (int j = 0; j < p; j++) {
            if (blocked[j] == i) {
                is_blocked = 1;
                break;
            }
        }
        if (is_blocked) {
            continue;
        }

        // Calculate the number of ways to reach the current position using the previous two positions
        dp[i] = (dp[i-1] + dp[i-2]) % MOD;
    }

    // Print the number of ways to reach the nth position
    printf("%lld\n", dp[n]);

    return 0;
}
