#######
# Code
#######

# Import necessary libraries
import math, itertools, fractions, heapq, collections, bisect, sys, queue, copy

# Set recursion limit
sys.setrecursionlimit(10**7)

# Define constants
inf = 10**20
mod = 10**9 + 7
dd = [ (-1, 0), (0, 1), (1, 0), (0, -1) ]
ddn = [ (-1, 0), (-1, 1), (0, 1), (1, 1), (1, 0), (1, -1), (0, -1), (-1, -1) ]

# Function to read an integer list from standard input
def LI( ):
    return [int(x) for x in sys.stdin.readline().split()]

# Function to read an integer from standard input
def I( ):
    return int(sys.stdin.readline())

# Function to read a float from standard input
def F( ):
    return float(sys.stdin.readline())

# Function to read a list from standard input, split by space
def LS( ):
    return sys.stdin.readline().split()

# Function to read a string from standard input
def S( ):
    return input()

# Main function
def main( ):
    # Read input values
    a, b, c, d = LI()

    # Calculate the maximum product of pairs of numbers
    result = max(a*c, b*d, a*d, b*c)

    # Print the result
    print(result)

# Call the main function
main()
