import sys

# Define a large constant for infinity
INF = 123456789012

def main():
    # Read the number of keys (n) and the number of items (m)
    n, m = map(int, sys.stdin.readline().split())

    # Arrays to store the keys and costs
    key = [0] * (m + 1)
    cost = [0] * (m + 1)

    # DP table to store the minimum costs for each state
    dp = [[INF] * (m + 1) for _ in range(1 << n)]

    # Base case: cost of obtaining no keys is 0
    dp[0][0] = 0

    # Read the costs and keys for each item
    for i in range(1, m + 1):
        b, *keys = map(int, sys.stdin.readline().split())
        cost[i] = b
        for c in keys:
            key[i] += (1 << (c - 1))  # Update the key bitmask for item i

    # Fill the DP table
    for i in range(1 << n):
        for j in range(m):
            # Update the DP table for not taking the (j+1)th item
            dp[i][j + 1] = min(dp[i][j], dp[i][j + 1])
            # Update the DP table for taking the (j+1)th item
            dp[i | key[j + 1]][j + 1] = min(dp[i | key[j + 1]][j + 1], dp[i][j] + cost[j + 1])

    # Check if it's possible to obtain all keys
    if dp[(1 << n) - 1][m] == INF:
        print(-1)  # If not possible, print -1
    else:
        print(dp[(1 << n) - 1][m])  # Print the minimum cost to obtain all keys

if __name__ == "__main__":
    main()

# <END-OF-CODE>
