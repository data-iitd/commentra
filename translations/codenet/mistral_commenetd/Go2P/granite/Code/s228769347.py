
# Python code to solve the problem

# Importing required packages
import sys
import os
import io
import bisect

# Function to read the next word as a string
def getNextString():
    return input()

# Function to read the next integer from the input
def getNextInt():
    return int(getNextString())

# Function to read the next integer64 from the input
def getNextInt64():
    return int(getNextString())

# Function to read the next uint64 from the input
def getNextUint64():
    return int(getNextString())

# Function to read the next float64 from the input
def getNextFloat64():
    return float(getNextString())

# Main function to solve the problem
def main():
    # Initializing standard input and output file pointers
    fp = sys.stdin
    wfp = sys.stdout

    # If input file and output file are provided as command line arguments
    if len(sys.argv) > 1:
        # Open the input file
        fp = open(sys.argv[1])

        # If output file is provided, create it
        if len(sys.argv) > 2:
            wfp = open(sys.argv[2], 'w')

    # Initialize a new scanner for reading input
    scanner = bufio.Scanner(fp)
    writer = bufio.Writer(wfp)

    # Read the number of elements in the array
    n = getNextInt()

    # Initialize a list to store the elements
    ll = []

    # Read the elements of the array
    for i in range(n):
        ll.append(getNextInt())

    # Sort the list in ascending order
    ll.sort()

    # Initialize the answer variable to 0
    ans = 0

    # Iterate through all possible pairs of elements
    for i in range(n-2):
        # Iterate through all possible right pointers
        for j in range(i + 1, n-1):
            # Initialize the left and right pointers for binary search
            l = j + 1
            r = n

            # Binary search to find the index of the element greater than the sum of the current pair
            while l < r:
                m = (l + r) >> 1
                if ll[m] < ll[i]+ll[j]:
                    l = m + 1
                    continue
                r = m

            # Update the answer variable
            ans += l - (j + 1)

    # Write the answer to the output file
    writer.write(str(ans))

    # Flush the writer buffer
    writer.flush()

# "

