#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007

int main() {
    // Declare variables for the number of elements (n) and the number of blocked positions (p)
    int n, p;
    
    // Read the total number of elements (n) and the number of blocked positions (p) from input
    scanf("%d", &n);
    scanf("%d", &p);

    // Create an array to store the blocked positions
    int *blocked = (int *)calloc(n + 1, sizeof(int));
    
    // Read the blocked positions and store them in the array
    for (int index = 0; index < p; index++) {
        int n1;
        scanf("%d", &n1);
        blocked[n1] = 1; // Mark the position as blocked
    }

    // Initialize an array to store the number of ways to reach each position
    long long *dp = (long long *)calloc(n + 1, sizeof(long long));
    
    // Base cases: There is 1 way to reach the 0th and 1st positions
    dp[0] = 1;
    dp[1] = 1;

    // If the first position is blocked, set the number of ways to reach it to 0
    if (blocked[1]) {
        dp[1] = 0;
    }

    // Iterate through positions from 2 to n to calculate the number of ways to reach each position
    for (int i = 2; i <= n; i++) {
        // If the current position is blocked, skip the calculation
        if (blocked[i]) {
            continue;
        }
        // Calculate the number of ways to reach the current position using the previous two positions
        dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
    }

    // Print the number of ways to reach the nth position
    printf("%lld\n", dp[n]);

    // Free allocated memory
    free(blocked);
    free(dp);

    return 0;
}

// <END-OF-CODE>
