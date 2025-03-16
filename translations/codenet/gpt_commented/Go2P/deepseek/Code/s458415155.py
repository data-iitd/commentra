import sys
import math

# Read input from stdin
def input():
    return sys.stdin.readline().strip()

# Read an integer
def read_int():
    return int(input())

# Read a list of integers
def read_int_list():
    return list(map(int, input().split()))

# Calculate the absolute value of an integer
def abs_int(x):
    return abs(x)

# Solve the problem using dynamic programming
def solve(n, heights):
    t = [math.inf] * (n + 1)  # Initialize the minimum costs with infinity
    t[0] = 0  # The cost to reach the first height is zero

    for i in range(1, n):
        # Calculate the cost to reach the current height from the previous height
        if t[i] > t[i - 1] + abs(heights[i] - heights[i - 1]):
            t[i] = t[i - 1] + abs(heights[i] - heights[i - 1])
        # Calculate the cost to reach the current height from two heights back
        if i > 1:
            if t[i] > t[i - 2] + abs(heights[i] - heights[i - 2]):
                t[i] = t[i - 2] + abs(heights[i] - heights[i - 2])

    return t[n - 1]  # Return the minimum cost to reach the last height

# Main function to execute the program
def main():
    n = read_int()  # Read the number of heights
    heights = read_int_list()  # Read the heights into a list
    ans = solve(n, heights)  # Solve for the minimum cost
    print(ans)  # Print the result

# Call the main function
if __name__ == "__main__":
    main()
