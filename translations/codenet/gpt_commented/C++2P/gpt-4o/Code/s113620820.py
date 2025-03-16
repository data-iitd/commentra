# Sashimi

import sys

# Constants
MAX_N = 4000  # Maximum number of items
LINF = 1 << 60  # Define a large constant for initialization

# Global variables
wis = [0] * MAX_N  # Array for weights
wsums = [0] * (MAX_N + 1)  # Prefix sums
dp = [[LINF] * (MAX_N + 1) for _ in range(MAX_N)]  # Dynamic programming table
ks = [[-1] * (MAX_N + 1) for _ in range(MAX_N)]  # Array to store optimal split points

# Main
def main():
    n = int(sys.stdin.readline().strip())  # Read the number of items

    # Initialize prefix sums
    for i in range(n):
        wis[i] = int(sys.stdin.readline().strip())  # Read the weight of each item
        wsums[i + 1] = wsums[i] + wis[i]  # Calculate prefix sums

    # Initialize the dynamic programming and split point tables
    for i in range(n):
        dp[i][i + 1] = 0  # Base case: no cost to combine a single item
        ks[i][i + 1] = i  # Base case: the split point is the item itself

    # Fill the dynamic programming table
    for l in range(2, n + 1):  # Iterate over lengths of segments
        for i in range(n - l + 1):  # Iterate over starting index i
            j = i + l  # Calculate ending index j
            mind = LINF  # Initialize minimum cost for this segment
            wsum = wsums[j] - wsums[i]  # Calculate the total weight of the segment
            mink = -1  # Initialize the best split point
            for k in range(ks[i][j - 1], ks[i + 1][j] + 1):  # Iterate over possible split points
                d = dp[i][k] + dp[k][j] + wsum  # Calculate the cost of this split
                if mind > d:  # Update minimum cost and best split point
                    mind = d
                    mink = k
            dp[i][j] = mind  # Store the minimum cost for segment (i, j)
            ks[i][j] = mink  # Store the best split point for segment (i, j)

    # Output the minimum cost to combine all items
    print(dp[0][n])  # Print the result

if __name__ == "__main__":
    main()  # Execute the main function

# <END-OF-CODE>
