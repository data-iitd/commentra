def max(lhs, rhs):
    return max(lhs, rhs)

def main():
    # Read the number of items and maximum weight capacity
    N, M = map(int, input().split())
    # Read the weight and value of each item
    values = []
    weights = []
    for _ in range(N):
        w, v = map(int, input().split())
        weights.append(w)
        values.append(v)
    
    # Initialize the DP table
    dp = [[0] * (M + 1) for _ in range(N + 1)]
    
    # Fill the DP table
    for i in range(1, N + 1):
        for j in range(M + 1):
            dp[i][j] = dp[i - 1][j]  # Inherit the maximum value from the previous item
            if j >= weights[i - 1]:
                dp[i][j] = max(dp[i][j], dp[i - 1][j - weights[i - 1]] + values[i - 1])  # Update the DP table with the current item
    
    # Print the maximum value that can be achieved
    print(dp[N][M])

# Call the main function
main()
