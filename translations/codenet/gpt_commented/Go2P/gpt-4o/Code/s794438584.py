def max(lhs, rhs):
    # max function returns the maximum of two integers.
    return max(lhs, rhs)

def main():
    # Declare variables for the number of items (N) and the maximum weight (M).
    N, M = map(int, input().split())

    # Initialize lists to hold the weights and values of the items.
    values = []
    weights = []

    # Read the weights and values of each item from standard input.
    for _ in range(N):
        w, v = map(int, input().split())
        weights.append(w)
        values.append(v)

    # Initialize a 2D list for dynamic programming table.
    dp = [[0] * (M + 1) for _ in range(N + 1)]

    # Fill the dynamic programming table.
    for i in range(1, N + 1):
        for j in range(M + 1):
            # If the current item is not included, carry forward the previous value.
            dp[i][j] = dp[i - 1][j]

            # If the current item's weight is less than or equal to the current capacity.
            if j >= weights[i - 1]:
                # Calculate the maximum value by including the current item.
                dp[i][j] = max(dp[i][j], dp[i - 1][j - weights[i - 1]] + values[i - 1])

    # Output the maximum value that can be obtained with the given weight limit.
    print(dp[N][M])

if __name__ == "__main__":
    main()

# <END-OF-CODE>
