import sys
import math

# Function to calculate absolute difference between two float numbers
def abs_diff_float(n1, n2):
    return abs(n1 - n2)

# Main function to handle input and output
def main():
    # Read input values
    n = int(sys.stdin.readline().strip())
    t = float(sys.stdin.readline().strip())
    a = float(sys.stdin.readline().strip())

    # Read heights
    heights = [float(sys.stdin.readline().strip()) for _ in range(n)]

    # Initialize variables for minimum difference
    min_diff = abs_diff_float(t - heights[0] * 0.006, a)
    min_idx = 0

    # Iterate through the remaining heights and find the minimum difference
    for i in range(1, n):
        h = heights[i]
        diff = abs_diff_float(t - h * 0.006, a)

        # Update minimum difference and index if the current difference is smaller
        if diff < min_diff:
            min_diff = diff
            min_idx = i

    # Print the result (1-based index)
    print(min_idx + 1)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
