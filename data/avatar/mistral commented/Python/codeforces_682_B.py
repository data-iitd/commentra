# Import necessary modules
import os, sys, io, math
from array import array
from math import *

# Function to read a list of integers from standard input
I = lambda : [ * map ( int, sys.stdin.readline().split() ) ]

# Function to read an integer from standard input
IS = lambda : input()

# Function to read an integer from standard input and convert it to an integer
IN = lambda : int(input())

# Function to read a float from standard input
IF = lambda : float(input())

# Read the number of test cases 'n'
n = IN()

# Read the list 'l' of length 'n' containing 'n' integers
l = I()

# Initialize variable 'f' to 1
f = 1

# Sort the list 'l' in ascending order
l.sort()

# Initialize variable 'c' to 0
c = 0

# Iterate through the list 'l'
for i in l:
    # If the current element 'i' is greater than the previous count 'c', increment 'c' by 1
    if i > c:
        c += 1

# Print the final result, which is the number of unique elements in the list 'l' plus 1
print(c + 1)
