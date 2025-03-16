
# Python code here
# Read input
n, m = map(int, input().split()) # n is the number of switches, m is the number of bulbs

# Initialize dynamic programming table with infinite values
dp = [[float('inf')] * (m + 1) for _ in range(1 << n)]
dp[0][0] = 0 # Set the initial value of dp[0][0] to 0

# Read bulbs' information
cost = [0] * (m + 1)
key = [0] * (m + 1)
for i in range(1, m + 1):
    cost[i], b = map(int, input().split())
    for j in range(b):
        c = int(input())
        key[i] |= 1 << (c - 1) # Set the corresponding bit in key[i] to 1

# Fill dynamic programming table
for i in range(1 << n): # Iterate through all possible combinations of switches
    for j in range(1, m + 1): # Iterate through all bulbs
        dp[i][j] = min(dp[i][j], dp[i][j - 1]) # Update dp[i][j] with the minimum value between dp[i][j] and dp[i][j - 1]
        dp[i | key[j]][j] = min(dp[i | key[j]][j], dp[i][j - 1] + cost[j]) # Update dp[i | key[j]][j] with the minimum value between dp[i | key[j]][j] and dp[i][j - 1] + cost[j]

# Output result
if dp[(1 << n) - 1][m] == float('inf'):
    print(-1) # Check if the minimum cost is infinite
else:
    print(dp[(1 << n) - 1][m]) # Output the minimum cost

