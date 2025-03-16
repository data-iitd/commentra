# Include the iostream library for input and output operations
# Include the cmath library for mathematical operations
import math
import os
import random
import re
import sys

# Declare a variable named N and initialize it to 0
N = 0

# Read a single integer value from STDIN
N = int(input())

# Declare a list of N empty lists
A = [[] for i in range(N)]

# Read N lines of input from STDIN and save it to our list
for i in range(N):
    A[i] = int(input())

# Initialize the variable m to the first element of the list A
m = A[0]

# Initialize the variable M to the first element of the list A
M = A[0]

# Start a loop that iterates through the list A
for i in range(N):
    # If the current element is less than m, update m to the current element
    if A[i] < m:
        m = A[i]
    # If the current element is greater than M, update M to the current element
    if A[i] > M:
        M = A[i]

# Print the difference between the maximum and minimum values in the list A
print(M - m)

# 