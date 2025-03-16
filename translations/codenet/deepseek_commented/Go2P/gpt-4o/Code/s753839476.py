import sys
import math

# Function to read input values, calculate the minimum difference, and return the index.
def main():
    n, t, a = map(float, sys.stdin.readline().split())
    n = int(n)
    heights = list(map(float, sys.stdin.readline().split()))

    min_diff = abs(t - heights[0] * 0.006 - a)  # Calculate the initial minimum difference.
    min_idx = 0  # Initialize the index of the minimum difference.

    for i in range(1, n):  # Iterate through the heights starting from the second element.
        diff = abs(t - heights[i] * 0.006 - a)  # Calculate the difference for the current height.
        if diff < min_diff:  # Update the minimum difference and index if a smaller difference is found.
            min_diff = diff
            min_idx = i

    print(min_idx + 1)  # Print the index (plus one for 1-based indexing).

if __name__ == "__main__":
    main()

# <END-OF-CODE>
