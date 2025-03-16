# Declare variables for the number of items (N) and the maximum weight (M).
N, M = map(int, input().split())

# Initialize slices to hold the weights and values of the items.
values = [0] * N
weights = [0] * N

# Read the weights and values of each item from standard input.
for i in range(N):
    values[i], weights[i] = map(int, input().split())

# Initialize a 2D slice for dynamic programming table.
dp = [[0] * (M + 1) for _ in range(N + 1)]

# Fill the dynamic programming table.
for i in range(1, N + 1):
    for j in range(0, M + 1):
        # If the current item is not included, carry forward the previous value.
        dp[i][j] = dp[i - 1][j]

        # If the current item's weight is less than or equal to the current capacity.
        if j >= weights[i - 1]:
            # Calculate the maximum value by including the current item.
            dp[i][j] = max(dp[i][j], dp[i - 1][j - weights[i - 1]] + values[i - 1])

# Output the maximum value that can be obtained with the given weight limit.
print(dp[N][M])

