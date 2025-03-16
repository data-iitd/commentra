
import sys
from typing import List

def main():
    # Read the number of elements from standard input
    n = int(sys.stdin.readline())

    # Initialize a list to hold the float64 numbers
    a = []

    # Read n float64 numbers from standard input into the list
    for _ in range(n):
        a.append(float(sys.stdin.readline()))

    # Perform a series of operations to reduce the list
    for _ in range(n-1):
        # Sort the list in ascending order
        a.sort()

        # Create a new list to hold the modified values
        na = []

        # Append all elements from the third element onward to the new list
        na.extend(a[2:])

        # Calculate the average of the first two elements and append it to the new list
        na.append((a[0] + a[1]) / 2)

        # Update the original list to be the new list
        a = na

    # Print the final remaining element in the list
    print(a[0])

# 