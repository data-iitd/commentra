import os, sys, io, math
from tokenize import Triple
from math import *

# Define a lambda function to read a list of integers from input
I = lambda: [*map(int, sys.stdin.readline().split())]
# Define a lambda function to read a single line of input as a string
IS = lambda: input()
# Define a lambda function to read a single integer from input
IN = lambda: int(input())
# Define a lambda function to read a single float from input
IF = lambda: float(input())

# Read the number of intervals
n = IN()

# Initialize the index for the result
id = 0

# Read the first interval's bounds
l, r = map(int, input().split())

# Iterate through the remaining intervals
for i in range(1, n):
    # Read the current interval's bounds
    li, ri = map(int, input().split())
    
    # Check if the current interval completely contains the previous one
    if li <= l and r <= ri:
        id = i  # Update the index to the current interval
    # Check if the current interval overlaps with the previous one
    elif li < l or r < ri:
        id = n  # Mark as overlapping by setting id to n
    
    # Update the bounds of the union of intervals
    l = min(l, li)  # Update the left bound
    r = max(r, ri)  # Update the right bound

# Print the result: -1 if no valid interval found, otherwise print the 1-based index of the interval
print(-1 if id == n else id + 1)
