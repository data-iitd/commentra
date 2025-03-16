import sys

# Define necessary data types and constants
INF = 123456789012  # Constants
key = [0] * 1005  # Initialize arrays
cost = [0] * 1005
dp = [[INF] * 1005 for _ in range(1 << 12 + 5)]  # 2D dynamic programming table

def main():
    # Read input
    n, m = map(int, sys.stdin.readline().split())  # n is the number of switches, m is the number of bulbs

    dp[0][0] = 0  # Set the initial value of dp[0][0] to 0

    # Read bulbs' information
    for i in range(1, m + 1):
        b = int(sys.stdin.readline().strip())  # The number of switches needed to turn on this bulb
        cost[i] = int(sys.stdin.readline().strip())

        # Update key array
        for j in range(b):
            c = int(sys.stdin.readline().strip())  # The position of the switch
            key[i] += (1 << (c - 1))  # Set the corresponding bit in key[i] to 1

    # Fill dynamic programming table
    for i in range(1 << n):  # Iterate through all possible combinations of switches
        for j in range(m):
            dp[i][j + 1] = min(dp[i][j], dp[i][j + 1])  # Update dp[i][j+1]
            dp[i | key[j + 1]][j + 1] = min(dp[i | key[j + 1]][j + 1], dp[i][j] + cost[j + 1])  # Update dp[i|key[j+1]][j+1]

    # Output result
    if dp[(1 << n) - 1][m] == INF:
        print(-1)  # Check if the minimum cost is infinite
    else:
        print(dp[(1 << n) - 1][m])  # Output the minimum cost

if __name__ == "__main__":
    main()

# <END-OF-CODE>
