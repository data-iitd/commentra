import sys

MOD = 998244353

# Create a 2D array for dynamic programming
dp = [[0 for i in range(3001)] for j in range(3001)]

# Method to solve the problem
def solve(A, B, C, D):
    # Initialize the starting point in the dp array
    dp[A][B] = 1

    # Iterate over the range from A to C and B to D
    for c in range(A, C + 1):
        for d in range(B, D + 1):
            # Skip the initial point
            if c == A and d == B:
                continue

            # Variable to store the current answer
            ans = 0

            # If moving down (increasing c)
            if c > A:
                part = dp[c - 1][d]
                ans = (part * d) # Calculate contribution from the previous row

            # If moving right (increasing d)
            if d > B:
                part = dp[c][d - 1]
                ans = (ans + (part * c)) # Calculate contribution from the previous column

            # If moving diagonally (increasing both c and d)
            if c > A and d > B:
                ans = (ans - (dp[c - 1][d - 1] * (c - 1) * (d - 1))) # Adjust for double counting

            # Store the result in the dp array with modulo adjustment
            dp[c][d] = ((ans % MOD) + MOD) % MOD

    # Output the final result for dp[C][D]
    print(dp[C][D])

# Main method to execute the program
if __name__ == "__main__":
    A, B, C, D = map(int, sys.stdin.readline().split())
    solve(A, B, C, D)

