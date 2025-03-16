# Sashimi

# Initialize constants and imports
import sys

# Constant
MAX_N = 4000

# Define a large constant for initialization
LINF = 1 << 60

# Main function
def main():
    # Read the number of items
    n = int(input())

    # Initialize prefix sums
    wis = [0] * MAX_N
    wsums = [0] * (MAX_N + 1)

    # Read the weight of each item and calculate prefix sums
    for i in range(n):
        wis[i] = int(input())
        wsums[i + 1] = wsums[i] + wis[i]

    # Initialize the dynamic programming and split point tables
    dp = [[LINF] * (MAX_N + 1) for _ in range(MAX_N)]
    ks = [[-1] * (MAX_N + 1) for _ in range(MAX_N)]

    # Base case: no cost to combine a single item
    for i in range(n):
        dp[i][i + 1] = 0
        ks[i][i + 1] = i

    # Fill the dynamic programming table
    for l in range(2, n + 1):  # Iterate over lengths of segments
        for i in range(n - l + 1):  # Iterate over starting index i and ending index j
            j = i + l
            mind = LINF  # Initialize minimum cost for this segment
            wsum = wsums[j] - wsums[i]  # Calculate the total weight of the segment

            # Iterate over possible split points
            for k in range(ks[i][j - 1], ks[i + 1][j] + 1):
                d = dp[i][k] + dp[k][j] + wsum  # Calculate the cost of this split
                if mind > d:
                    mind = d
                    mink = k  # Update minimum cost and best split point

            dp[i][j] = mind  # Store the minimum cost for segment (i, j)
            ks[i][j] = mink  # Store the best split point for segment (i, j)

    # Output the minimum cost to combine all items
    print(dp[0][n])  # Print the result

# Call the main function
if __name__ == "__main__":
    main()
