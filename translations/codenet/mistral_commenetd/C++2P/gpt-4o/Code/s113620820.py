# Sashimi

import sys

# Define constants
MAX_N = 4000
LINF = 1 << 60

# Initialize global variables
wis = [0] * MAX_N
wsums = [0] * (MAX_N + 1)
dp = [[LINF] * (MAX_N + 1) for _ in range(MAX_N)]
ks = [[-1] * (MAX_N + 1) for _ in range(MAX_N)]

# Main function
def main():
    # Read input
    n = int(sys.stdin.readline().strip())

    # Initialize arrays
    for i in range(n):
        wis[i] = int(sys.stdin.readline().strip())
        wsums[i + 1] = wsums[i] + wis[i]

    # Initialize dp and ks with default values
    for i in range(n):
        dp[i][i + 1] = 0
        ks[i][i + 1] = i

    # Calculate dp and ks for all subarrays of size 2 to n
    for l in range(2, n + 1):
        for i in range(n - l + 1):
            j = i + l
            mind = LINF
            wsum = wsums[j] - wsums[i]
            mink = -1

            # Find the minimum cost and index of the previous subarray that can be combined with the current subarray
            for k in range(ks[i][j - 1], ks[i + 1][j] + 1):
                # Calculate the cost of combining the current subarray with the previous subarray
                d = dp[i][k] + dp[k][j] + wsum

                # Update minimum cost and index if found a better combination
                if mind > d:
                    mind = d
                    mink = k

            # Update dp and ks for the current subarray
            dp[i][j] = mind
            ks[i][j] = mink

    # Print the result
    print(dp[0][n])

# Terminate the program
if __name__ == "__main__":
    main()

# <END-OF-CODE>
