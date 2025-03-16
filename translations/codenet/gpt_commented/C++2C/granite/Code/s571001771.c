
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <iostream>
#include <map>
#include <set>
#define END-OF-CODE

int main() {
    // Read the number of keys (n) and the number of items (m)
    int n, m;
    scanf("%d %d", &n, &m);

    // Initialize the DP table with infinity
    int dp[(1<<12)+5][1005] = {0};
    for(int i = 0; i < (1 << 12) + 5; i++) {
        for(int j = 0; j < 1005; j++) {
            dp[i][j] = 100000000; // Set each entry to infinity
        }
    }

    // Base case: cost of obtaining no keys is 0
    dp[0][0] = 0;

    // Read the costs and keys for each item
    int key[1005] = {0};
    int cost[1005] = {0};
    for(int i = 1; i <= m; i++) {
        scanf("%d %d", &cost[i], &b); // Read cost and number of keys for item i
        for(int j = 0; j < b; j++) {
            int c;
            scanf("%d", &c); // Read each key
            key[i] += (1 << (c - 1)); // Update the key bitmask for item i
        }
    }

    // Fill the DP table
    for(int i = 0; i < (1 << n); i++) {
        for(int j = 0; j < m; j++) {
            // Update the DP table for not taking the (j+1)th item
            dp[i][j + 1] = std::min(dp[i][j], dp[i][j + 1]);
            // Update the DP table for taking the (j+1)th item
            dp[i | key[j + 1]][j + 1] = std::min(dp[i | key[j + 1]][j + 1], dp[i][j] + cost[j + 1]);
        }
    }

    // Check if it's possible to obtain all keys
    if(dp[(1 << n) - 1][m] == 100000000)
        printf("-1\n"); // If not possible, print -1
    else
        printf("%d\n", dp[(1 << n) - 1][m]); // Print the minimum cost to obtain all keys

    return 0;
}
