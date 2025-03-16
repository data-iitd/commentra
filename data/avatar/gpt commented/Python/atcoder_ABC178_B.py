# Import necessary libraries for mathematical operations, data structures, and system functions
import math, itertools, fractions, heapq, collections, bisect, sys, queue, copy

# Set the maximum recursion limit to handle deep recursion cases
sys.setrecursionlimit(10 ** 7)

# Define a large constant for infinity
inf = 10 ** 20

# Define a modulus value commonly used in competitive programming
mod = 10 ** 9 + 7

# Define directional movements for 4 directions (up, right, down, left)
dd = [(-1, 0), (0, 1), (1, 0), (0, -1)]

# Define diagonal movements for 8 directions (including diagonals)
ddn = [(-1, 0), (-1, 1), (0, 1), (1, 1), (1, 0), (1, -1), (0, -1), (-1, -1)]

# Function to read a line of input and return it as a list of integers
def LI():
    return [int(x) for x in sys.stdin.readline().split()]

# Function to read a single integer from input
def I():
    return int(sys.stdin.readline())

# Function to read a single float from input
def F():
    return float(sys.stdin.readline())

# Function to read a line of input and return it as a list of strings
def LS():
    return sys.stdin.readline().split()

# Function to read a single string from input
def S():
    return input()

# Main function to execute the core logic of the program
def main():
    # Read four integers from input
    a, b, c, d = LI()
    
    # Calculate the maximum value from the products of the pairs and return it
    return max(a * c, b * d, a * d, b * c)

# Print the result of the main function
print(main())
