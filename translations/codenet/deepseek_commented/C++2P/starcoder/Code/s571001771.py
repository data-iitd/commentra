
# Python 3 program to find minimum cost to collect all keys
# in a locker

# Function to find minimum cost to collect all keys
# in a locker
def minCost(n, m, key, cost):
    # Create a 2D array to store the minimum cost
    # to collect all keys
    dp = [[INF for i in range(m + 1)] for j in range(1 << n)]

    # Base case: no keys and no cost
    for i in range(m + 1):
        dp[0][i] = 0

    # Iterate through all possible states
    for i in range(1 << n):
        for j in range(m):
            dp[i][j + 1] = min(dp[i][j], dp[i][j + 1])

            # If the jth key is present in the ith state
            if (i & key[j + 1]):
                dp[i | key[j + 1]][j + 1] = min(dp[i | key[j + 1]][j + 1], dp[i][j] + cost[j + 1])

    # Check if it's not possible to collect all keys
    if (dp[(1 << n) - 1][m] == INF):
        return -1

    return dp[(1 << n) - 1][m]

# Driver Code
if __name__ == '__main__':
    n, m = map(int, input().split())
    key = [0] * (m + 1)
    cost = [0] * (m + 1)

    # Read the cost and keys for each item
    for i in range(1, m + 1):
        cost[i], b = map(int, input().split())
        for j in range(b):
            key[i] += (1 << (int(input()) - 1))

    print(minCost(n, m, key, cost))

