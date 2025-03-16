# This line is a Go generate command to download the problem statement from AtCoder.
# It is not necessary to understand its functionality for the given code.

import sys
import math

# Define a helper function for reading input efficiently.
def read_int():
    return int(sys.stdin.readline().strip())

def read_ints():
    return list(map(int, sys.stdin.readline().strip().split()))

# Define a helper function for calculating absolute value.
def iabs(x):
    return -x if x < 0 else x

# Define the main function to solve the problem.
def solve(n, heights):
    # Initialize a table t to store the minimum cost to reach each index.
    t = [math.inf] * (n + 1)
    # Set the base case, the cost to reach index 0 is 0.
    t[0] = 0

    # Iterate through the array from index 1 to n-1.
    for i in range(1, n):
        # Calculate the cost to reach index i from the previous index.
        prev_index_cost = t[i - 1]
        # Update the cost to reach index i if the difference between heights is beneficial.
        heights_diff = heights[i] - heights[i - 1]
        prev_index_cost += heights_diff if heights_diff < 0 else -heights_diff
        
        # Update the cost to reach index i if the difference between previous index is beneficial.
        if i - 2 >= 0:
            prev_prev_index_cost = t[i - 2]
            heights_diff = heights[i] - heights[i - 2]
            prev_prev_index_cost += heights_diff if heights_diff < 0 else -heights_diff
            
            t[i] = min(t[i], prev_index_cost, prev_prev_index_cost)
        else:
            t[i] = min(t[i], prev_index_cost)

    # Return the minimum cost to reach the last index.
    return t[n - 1]

# Define the main function to read input and call the solve function.
def main():
    # Read the number of test cases.
    n = read_int()
    for _ in range(n):
        # Read the number of heights and initialize an array to store them.
        heights = read_ints()
        # Call the solve function and print the result.
        ans = solve(len(heights), heights)
        print(ans)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
