# Import necessary libraries
import sys
from collections import defaultdict

# Declare global variables
N = 0
A = [0] * (1 << 18)  # N is the number of elements, A is the array to hold the elements
dp = [[[-float('inf')] * 20 for _ in range(2)] for _ in range(1 << 18)]  # dp array for dynamic programming

def main():
    global N, A, dp

    # Read the number of elements
    N = int(input().strip())

    # Read the elements into the array A
    for i in range(1, N + 1):
        A[i] = int(input().strip())

    # Base case: when no elements are considered, the value at dp[0][0][10] is 0
    dp[0][0][10] = 0

    # Fill the dp array based on previous states
    for i in range(1, N + 1):
        for j in range(6, 15):
            # If the previous state in dp[i-1][0][j] is valid
            if dp[i - 1][0][j] != -float('inf'):
                # Update the state dp[i][1][j + 1] by adding the current element A[i]
                dp[i][1][j + 1] = max(dp[i][1][j + 1], dp[i - 1][0][j] + A[i])
                # Update the state dp[i][0][j - 1] without adding the current element
                dp[i][0][j - 1] = max(dp[i][0][j - 1], dp[i - 1][0][j])
            # If the previous state in dp[i-1][1][j] is valid
            if dp[i - 1][1][j] != -float('inf'):
                # Update the state dp[i][0][j - 1] without adding the current element
                dp[i][0][j - 1] = max(dp[i][0][j - 1], dp[i - 1][1][j])

    # Calculate the target value V based on the number of elements
    V = 10 + (N // 2) - (N - (N // 2))

    # Retrieve the maximum values from the last state of dp
    T1 = dp[N][0][V]
    T2 = dp[N][1][V]

    # Output the maximum value obtained from the two states
    print(max(T1, T2))

if __name__ == "__main__":
    main()  # Run the main function

# <END-OF-CODE>
