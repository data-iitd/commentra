def max(lhs, rhs):
    return max(lhs, rhs)

def main():
    N, M = map(int, input().split())  # Read the number of items and maximum weight capacity
    values = []  # List to store values of items
    weights = []  # List to store weights of items
    for _ in range(N):
        weight, value = map(int, input().split())  # Read the weight and value of each item
        weights.append(weight)
        values.append(value)

    dp = [[0] * (M + 1) for _ in range(N + 1)]  # Initialize the DP table
    for i in range(1, N + 1):
        for j in range(M + 1):
            dp[i][j] = dp[i - 1][j]  # Inherit the maximum value from the previous item
            if j >= weights[i - 1]:
                dp[i][j] = max(dp[i][j], dp[i - 1][j - weights[i - 1]] + values[i - 1])  # Update the DP table with the current item

    print(dp[N][M])  # Print the maximum value that can be achieved

if __name__ == "__main__":
    main()

# <END-OF-CODE>
