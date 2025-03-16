# https://atcoder.jp/contests/dp/tasks/dp_a

import sys
import math

# Function to read integers from input
def read_int():
    return int(sys.stdin.readline().strip())

# Function to read a list of integers from input
def read_ints():
    return list(map(int, sys.stdin.readline().strip().split()))

# Function to calculate the minimum cost to reach the last stone using dynamic programming
def solve(n, heights):
    # Initialize the minimum cost array with a large value
    t = [math.inf] * (n + 1)
    
    # The cost to reach the first stone is 0
    t[0] = 0

    # Calculate the minimum cost to reach each stone
    for i in range(1, n):
        # Cost to reach the current stone from the previous stone
        t[i] = min(t[i], t[i - 1] + abs(heights[i] - heights[i - 1]))
        
        # Cost to reach the current stone from two stones back (if possible)
        if i > 1:
            t[i] = min(t[i], t[i - 2] + abs(heights[i] - heights[i - 2]))

    # Return the minimum cost to reach the last stone
    return t[n - 1]

# Main function to read input, call the solve function, and print the result
if __name__ == "__main__":
    n = read_int()
    heights = read_ints()
    ans = solve(n, heights)
    print(ans)

# <END-OF-CODE>
