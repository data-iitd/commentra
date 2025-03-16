from math import *  # Import all mathematical functions and constants

# Function to read a single integer from input
def next_int():
    return int(input())

# Function to read a list of integers from input
def next_ints():
    return list(map(int, input().split()))

# Read the number of iterations or elements
n = next_int()

# Initialize a counter for odd indices
t = 0

# Loop through the range of n
for i in range(n):
    # Check if the current index (i + 1) is odd
    if (i + 1) & 1:
        t += 1  # Increment the counter for odd indices

# Calculate and print the ratio of odd indices to total elements
print(t / n)
