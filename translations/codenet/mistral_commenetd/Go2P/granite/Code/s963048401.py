

import sys
from bisect import bisect_left

# Initialize the modulus value
mod = 1000000007

# Initialize a buffer to store the unique elements
buf = []

# Function to read input and process it
def main():
    # Read the number of elements in the array
    n = int(input())

    # Initialize an array of size n to store the elements
    as = [int(input()) for _ in range(n)]

    # Initialize an empty list xs to store the unique elements
    xs = [as[0]]

    # Iterate through the array and add unique elements to the xs list
    for j in range(1, n):
        # Binary search to find the index where the current element should be inserted in the xs list
        idx = bisect_left(xs, as[j])

        # If the current element is not already present in the xs list, insert it
        if idx == len(xs):
            xs.append(as[j])
        else:
            # Otherwise, replace the element at the found index with the current element
            xs[idx] = as[j]

    # Print the length of the xs list
    print(len(xs))

