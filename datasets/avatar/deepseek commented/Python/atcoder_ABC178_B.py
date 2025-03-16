import math, itertools, fractions, heapq, collections, bisect, sys, queue, copy
# Importing modules for various functionalities such as mathematical operations, data structures, and system operations.

sys.setrecursionlimit(10**7)
# Setting the recursion limit to a high value to allow deep recursion, useful for certain algorithms.

inf = 10**20
mod = 10**9 + 7
# Constants for infinity and modulo operations.

dd = [(-1, 0), (0, 1), (1, 0), (0, -1)]
ddn = [(-1, 0), (-1, 1), (0, 1), (1, 1), (1, 0), (1, -1), (0, -1), (-1, -1)]
# Direction vectors for grid-based movements.

def LI(): return [int(x) for x in sys.stdin.readline().split()]
# Function to read a list of integers from standard input.

def I(): return int(sys.stdin.readline())
# Function to read an integer from standard input.

def F(): return float(sys.stdin.readline())
# Function to read a float from standard input.

def LS(): return sys.stdin.readline().split()
# Function to read a list of strings from standard input.

def S(): return input()
# Function to read a string from standard input.

def main():
    a, b, c, d = LI()
    # Reading four integers from standard input.
    return max(a * c, b * d, a * d, b * c)
    # Calculating and returning the maximum of four possible products of two of the given numbers.

print(main())
# Printing the result of the main function.
