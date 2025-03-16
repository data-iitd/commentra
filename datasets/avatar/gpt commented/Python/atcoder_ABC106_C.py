# Importing necessary libraries for various functionalities
import math, string, itertools, fractions, heapq, collections, re, array, bisect, sys, random, time, copy, functools

# Setting the recursion limit to a high value to allow deep recursion
sys.setrecursionlimit(10 ** 7)

# Defining constants for infinity, epsilon, and a modulus value
inf = 10 ** 20
eps = 1.0 / 10 ** 10
mod = 10 ** 9 + 7

# Defining direction vectors for 4-way and 8-way movement
dd = [(-1, 0), (0, 1), (1, 0), (0, -1)]
ddn = [(-1, 0), (-1, 1), (0, 1), (1, 1), (1, 0), (1, -1), (0, -1), (-1, -1)]

# Function to read a line of integers from input
def LI(): 
    return [int(x) for x in sys.stdin.readline().split()]

# Function to read a line of integers from input and convert them to zero-based index
def LI_(): 
    return [int(x) - 1 for x in sys.stdin.readline().split()]

# Function to read a line of floats from input
def LF(): 
    return [float(x) for x in sys.stdin.readline().split()]

# Function to read a line of strings from input
def LS(): 
    return sys.stdin.readline().split()

# Function to read a single integer from input
def I(): 
    return int(sys.stdin.readline())

# Function to read a single float from input
def F(): 
    return float(sys.stdin.readline())

# Function to read a single string from input
def S(): 
    return input()

# Function to print a string and flush the output buffer
def pf(s): 
    return print(s, flush=True)

# Main function to process the input and return the result
def main():
    # Reading a string from input
    s = S()
    # Reading an integer k from input
    k = I()
    l = 0  # Initialize a counter for leading '1's

    # Count the number of leading '1's in the string
    for c in s:
        if c != '1':
            break
        l += 1
    
    # If the count of leading '1's is greater than or equal to k, return 1
    if l >= k:
        return 1
    
    # Otherwise, return the character at position l in the string
    return s[l]

# Print the result of the main function
print(main())
