
# 2415.py: Sashimi

import sys

# Define a large constant for initialization
LINF = 1 << 60

# Read the number of items
n = int(input())

# Initialize arrays for weights, prefix sums, and dynamic programming table
wis = [0] * n # Array for weights
wsums = [0] * (n + 1) # Array for prefix sums
dp = [[LINF] * (n + 1) for _ in range(n)] # Dynamic programming table
ks = [[-1] * (n + 1) for _ in range(n)] # Array to store optimal split points

# Read the weight of each item and calculate prefix sums
for i in range(n):
    wis[i] = int(input())
    wsums[i + 1] = wsums[i] + wis[i]

# Initialize the dynamic programming and split point tables
for i in range(n):
    for j in range(i, n + 1):
        dp[i][j] = LINF
        ks[i][j] = -1
    dp[i][i + 1] = 0
    ks[i][i + 1] = i

# Fill the dynamic programming table
for l in range(2, n + 1):
    for i in range(n - l + 1):
        j = i + l
        wsum = wsums[j] - wsums[i]
        mind = LINF
        mink = -1
        for k in range(ks[i][j - 1], ks[i + 1][j] + 1):
            d = dp[i][k] + dp[k][j] + wsum
            if d < mind:
                mind = d
                mink = k
        dp[i][j] = mind
        ks[i][j] = mink

# Output the minimum cost to combine all items
print(dp[0][n]) # Print the result

Translate the above Python code to Java and end with comment "