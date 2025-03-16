# Import necessary libraries
import sys
import math

# Define constants for large values and mathematical constants
inf = int(1e9 + 7)
mod = int(1e9 + 7)
mod1 = 998244353
big = int(1e18)
PI = 2 * math.asin(1)

def main():
    # Read the number of elements
    N = int(input().strip())

    # Initialize a list to store the elements
    A = list(map(int, input().strip().split()))

    # Sort the list in descending order
    A.sort(reverse=True)

    # Initialize variables to track the minimum difference and the corresponding index
    index = -1
    max_diff = inf

    # Find the element in the list that minimizes the difference with twice the second largest element
    for i in range(1, N):
        # Calculate the absolute difference and update if it's smaller than the current max
        if max_diff > abs(A[0] - 2 * A[i]):
            max_diff = abs(A[0] - 2 * A[i])
            index = i  # Store the index of the element that gives the minimum difference

    # Output the largest element and the element that minimizes the difference
    print(A[0], A[index])

if __name__ == "__main__":
    main()

# <END-OF-CODE>
