# <go:generate echo "https://atcoder.jp/contests/dp/tasks/dp_a">

import sys
import math

# Function to read an integer from input
def read_int():
    return int(sys.stdin.readline().strip())

# Function to read a list of integers from input
def read_ints():
    return list(map(int, sys.stdin.readline().strip().split()))

# Function to compute the minimum cost to reach the last height using dynamic programming
def solve(n, heights):
    t = [math.inf] * (n + 1)  # Create a list to store minimum costs
    t[0] = 0  # The cost to reach the first height is zero

    for i in range(1, n):
        # Calculate the cost to reach the current height from the previous height
        t[i] = min(t[i], t[i - 1] + abs(heights[i] - heights[i - 1]))
        # Calculate the cost to reach the current height from two heights back
        if i > 1:
            t[i] = min(t[i], t[i - 2] + abs(heights[i] - heights[i - 2]))

    return t[n - 1]  # Return the minimum cost to reach the last height

# Main function to execute the program
if __name__ == "__main__":
    n = read_int()  # Read the number of heights
    heights = read_ints()  # Read the heights into a list
    ans = solve(n, heights)  # Solve for the minimum cost
    print(ans)  # Print the result

# <END-OF-CODE>
