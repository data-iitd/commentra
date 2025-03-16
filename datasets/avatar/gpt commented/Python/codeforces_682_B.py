# Import necessary libraries
import os, sys, io, math
from array import array
from math import *

# Define lambda functions for input handling
I = lambda: [*map(int, sys.stdin.readline().split())]  # Read a line of integers
IS = lambda: input()                                   # Read a single line of input
IN = lambda: int(input())                             # Read a single integer
IF = lambda: float(input())                           # Read a single float

# Read the number of elements
n = IN()                                              # Number of elements in the list

# Read the list of integers
l = I()                                               # List of integers from input

# Initialize a variable to track unique counts
f = 1                                                 # Starting count for unique elements
l.sort()                                             # Sort the list to facilitate counting unique elements

# Initialize a counter for unique elements
c = 0                                                 # Counter for unique elements

# Iterate through the sorted list to count unique elements
for i in l:
    if i > c:                                        # Check if the current element is greater than the counter
        c += 1                                       # Increment the counter for unique elements

# Output the total count of unique elements
print(c + 1)                                         # Print the count of unique elements (including the first element)
