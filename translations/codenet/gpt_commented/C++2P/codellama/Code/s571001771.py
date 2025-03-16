#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;

# Define long long type for convenience
ll = long long
# Define a pair type for convenience
PP = pair[ll, ll]

# Arrays to store the keys and costs
key = [0] * 1005
cost = [0] * 1005
# DP table to store the minimum costs for each state
dp = [[0] * 1005 for _ in range(1 << 12 + 5)]
# Define a large constant for infinity
INF = 123456789012

def main():
    # Read the number of keys (n) and the number of items (m)
    n, m = map(int, input().split())

    # Initialize the DP table with infinity
    for i in range(1 << 12 + 5):
        for j in range(1005):
            dp[i][j] = INF  # Set each entry to infinity

    # Base case: cost of obtaining no keys is 0
    dp[0][0] = 0

    # Read the costs and keys for each item
    for i in range(1, m + 1):
        b = int(input())
        cost[i], b = map(int, input().split())
        for j in range(b):
            c = int(input())
            key[i] += (1 << (c - 1))

    # Fill the DP table
    for i in range(0, (1 << n) + 5):
        for j in range(m):
            # Update the DP table for not taking the (j+1)th item
            dp[i][j + 1] = min(dp[i][j], dp[i][j + 1])
            # Update the DP table for taking the (j+1)th item
            dp[i | key[j + 1]][j + 1] = min(dp[i | key[j + 1]][j + 1], dp[i][j] + cost[j + 1])

    # Check if it's possible to obtain all keys
    if dp[(1 << n) - 1][m] == INF:
        print(-1)
    else:
        print(dp[(1 << n) - 1][m])


