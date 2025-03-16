import sys

INF = 123456789012  # Constant for infinity

def main():
    n, m = map(int, input().split())  # Read the number of keys (n) and items (m)
    key = [0] * (m + 1)  # Array to store the keys in a binary format
    cost = [0] * (m + 1)  # Array to store the cost of each item
    dp = [[INF] * (m + 1) for _ in range(1 << n)]  # 2D array for dynamic programming

    dp[0][0] = 0  # Base case: no keys and no cost

    for i in range(1, m + 1):  # Read the cost and keys for each item
        b = int(input())
        cost[i] = int(input())
        for _ in range(b):
            c = int(input())
            key[i] += (1 << (c - 1))  # Convert key information into binary format

    for i in range(1 << n):  # Iterate through all possible states
        for j in range(m):
            dp[i][j + 1] = min(dp[i][j], dp[i][j + 1])  # Update the dp array based on the current state
            dp[i | key[j + 1]][j + 1] = min(dp[i | key[j + 1]][j + 1], dp[i][j] + cost[j + 1])  # Update the dp array based on the next state

    if dp[(1 << n) - 1][m] == INF:
        print(-1)  # Check if it's not possible to collect all keys and output -1
    else:
        print(dp[(1 << n) - 1][m])  # Output the minimum cost to collect all keys

if __name__ == "__main__":
    main()

# <END-OF-CODE>
