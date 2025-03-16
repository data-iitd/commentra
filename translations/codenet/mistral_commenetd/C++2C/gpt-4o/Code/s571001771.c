#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef long long ll;
#define MAX_N 1005
#define MAX_M 12
#define INF 123456789012

ll key[MAX_N] = {0}; // Initialize arrays here
ll cost[MAX_N] = {0};
ll dp[(1 << MAX_M) + 5][MAX_N]; // 2D dynamic programming table

int main() {
    // Read input
    ll n, m; // n is the number of switches, m is the number of bulbs
    scanf("%lld %lld", &n, &m);

    // Initialize dynamic programming table with infinite values
    for (int i = 0; i < (1 << MAX_M) + 5; i++) {
        for (int j = 0; j < MAX_N; j++) {
            dp[i][j] = INF; // Set all values to infinite
        }
    }
    dp[0][0] = 0; // Set the initial value of dp[0][0] to 0

    // Read bulbs' information
    for (int i = 1; i <= m; i++) {
        ll b; // The number of switches needed to turn on this bulb
        scanf("%lld %lld", &cost[i], &b);

        // Update key array
        for (int j = 0; j < b; j++) {
            ll c; // The position of the switch
            scanf("%lld", &c);
            key[i] += (1 << (c - 1)); // Set the corresponding bit in key[i] to 1
        }
    }

    // Fill dynamic programming table
    for (ll i = 0; i < (1 << n); i++) { // Iterate through all possible combinations of switches
        for (int j = 0; j < m; j++) { // Iterate through all bulbs
            dp[i][j + 1] = (dp[i][j] < dp[i][j + 1]) ? dp[i][j] : dp[i][j + 1]; // Update dp[i][j+1] with the minimum value
            dp[i | key[j + 1]][j + 1] = (dp[i | key[j + 1]][j + 1] < dp[i][j] + cost[j + 1]) ? dp[i | key[j + 1]][j + 1] : (dp[i][j] + cost[j + 1]); // Update dp[i|key[j+1]][j+1]
        }
    }

    // Output result
    if (dp[(1 << n) - 1][m] == INF) {
        printf("-1\n"); // Check if the minimum cost is infinite
    } else {
        printf("%lld\n", dp[(1 << n) - 1][m]); // Output the minimum cost
    }

    return 0;
}

// <END-OF-CODE>
