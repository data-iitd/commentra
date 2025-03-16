
# Define long long type for convenience
import sys

# Define a pair type for convenience
from collections import namedtuple
PP = namedtuple('PP', ['first','second'])

# Arrays to store the keys and costs
key = [0] * 1005
cost = [0] * 1005
# DP table to store the minimum costs for each state
dp = [[0] * 1005 for i in range(1 << 12 + 5)]
# Define a large constant for infinity
INF = 123456789012

# Read the number of keys (n) and the number of items (m)
n, m = map(int, sys.stdin.readline().split())

# Base case: cost of obtaining no keys is 0
dp[0][0] = 0

# Read the costs and keys for each item
for i in range(1, m + 1):
    b = int(sys.stdin.readline())
    cost[i], b = map(int, sys.stdin.readline().split())
    for j in range(b):
        c = int(sys.stdin.readline())
        key[i] += (1 << (c - 1))

# Fill the DP table
for i in range(1 << n):
    for j in range(m):
        # Update the DP table for not taking the (j+1)th item
        dp[i][j + 1] = min(dp[i][j], dp[i][j + 1])
        # Update the DP table for taking the (j+1)th item
        dp[i | key[j + 1]][j + 1] = min(dp[i | key[j + 1]][j + 1], dp[i][j] + cost[j + 1])

# Check if it's possible to obtain all keys
if dp[(1 << n) - 1][m] == INF:
    print(-1) # If not possible, print -1
else:
    print(dp[(1 << n) - 1][m]) # Print the minimum cost to obtain all keys

# 