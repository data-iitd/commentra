#include <stdio.h>
<<<<<<< HEAD
#include <stdlib.h>
=======
>>>>>>> 98c87cb78a (data updated)
#include <limits.h>

typedef long long ll;

ll key[1005] = {0}; // Array to store the keys in a binary format
ll cost[1005] = {0}; // Array to store the cost of each item
ll dp[(1 << 12) + 5][1005]; // 2D array for dynamic programming
const ll INF = 123456789012; // Constant for infinity

int main() {
    ll n, m;
    scanf("%lld %lld", &n, &m); // Read the number of keys (n) and items (m)

    // Initialize the dp array with infinity
    for (int i = 0; i < (1 << 12) + 5; i++) {
        for (int j = 0; j < 1005; j++) {
            dp[i][j] = INF;
        }
    }
    dp[0][0] = 0; // Base case: no keys and no cost

    for (int i = 1; i <= m; i++) { // Read the cost and keys for each item
        ll b;
        scanf("%lld %lld", &cost[i], &b);
        for (int j = 0; j < b; j++) {
            ll c;
            scanf("%lld", &c);
            key[i] += (1 << (c - 1)); // Convert key information into binary format
        }
    }

    for (ll i = 0; i < (1 << n); i++) { // Iterate through all possible states
        for (int j = 0; j < m; j++) {
            dp[i][j + 1] = (dp[i][j] < dp[i][j + 1]) ? dp[i][j] : dp[i][j + 1]; // Update the dp array based on the current state
            dp[i | key[j + 1]][j + 1] = (dp[i | key[j + 1]][j + 1] < dp[i][j] + cost[j + 1]) ? dp[i | key[j + 1]][j + 1] : (dp[i][j] + cost[j + 1]); // Update the dp array based on the next state
        }
    }

    if (dp[(1 << n) - 1][m] == INF) {
        printf("-1\n"); // Check if it's not possible to collect all keys and output -1
    } else {
        printf("%lld\n", dp[(1 << n) - 1][m]); // Output the minimum cost to collect all keys
    }

    return 0;
}

// <END-OF-CODE>
