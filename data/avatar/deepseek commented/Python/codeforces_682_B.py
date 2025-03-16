import os, sys, io, math  # Importing necessary modules
from array import array  # Importing array module
from math import *  # Importing everything from the math module

# Define input functions
I = lambda: [*map(int, sys.stdin.readline().split())]  # Read a list of integers
IS = lambda: input()  # Read a single string
IN = lambda: int(input())  # Read an integer
IF = lambda: float(input())  # Read a float

# Read the number of elements
n = IN()

# Read the list of elements
l = I()

# Initialize variables
f = 1  # Flag variable
l.sort()  # Sort the list
c = 0  # Counter variable

# Iterate through the list to find the maximum number of unique elements
for i in l:
    if i > c:
        c += 1  # Increment the counter if the current element is greater than the counter

# Print the result
print(c + 1)  # Print the maximum number of unique elements
