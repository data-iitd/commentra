from functools import *  # Import all functions from functools module
from operator import *    # Import all functions from operator module

# Read an integer input N (not used in further calculations)
N = int(input())

# Read a list of integers from input and convert them to a list of integers
a = list(map(int, input().split()))

# Calculate the total using the XOR operation across all elements in the list 'a'
total = reduce(xor, a, 0)

# For each element in the list 'a', compute the XOR with 'total' and print the results
# The results are converted to strings and joined with a space for output
print(" ".join(list(map(lambda ai: str(ai ^ total), a))))
