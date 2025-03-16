import sys

# Define a large constant for infinity
INF = 123456789012

# Read the number of keys (n) and the number of items (m)
n, m = map(int, sys.stdin.readline().split())

# Initialize the DP table with infinity
dp = [[INF] * (m + 1) for _ in range(1 << n)]

# Base case: cost of obtaining no keys is 0
dp[0][0] = 0

# Arrays to store the keys and costs
keys = [0] * (m + 1)
costs = [0] * (m + 1)

# Read the costs and keys for each item
for i in range(1, m + 1):
    b, *k = map(int, sys.stdin.readline().split())
    costs[i] = b
    for c in k:
        keys[i] |= (1 << (c - 1))  # Update the key bitmask for item i

# Fill the DP table
for i in range(1 << n):
    for j in range(1, m + 1):
        # Update the DP table for not taking the j-th item
        dp[i][j] = min(dp[i][j], dp[i][j - 1])
        # Update the DP table for taking the j-th item
        dp[i | keys[j]][j] = min(dp[i | keys[j]][j], dp[i][j] + costs[j])

# Check if it's possible to obtain all keys
if dp[(1 << n) - 1][m] == INF:
    print(-1)  # If not possible, print -1
else:
    print(dp[(1 << n) - 1][m])  # Print the minimum cost to obtain all keys

