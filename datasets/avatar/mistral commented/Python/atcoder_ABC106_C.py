#######
# Code
#######

# Importing necessary libraries
import math, string, itertools, fractions, heapq, collections, re, array, bisect, sys, random, time, copy, functools

# Setting recursion limit for the program
sys.setrecursionlimit(10**7)

# Defining constants
inf = 10**20
eps = 1.0 / 10**10
mod = 10**9 + 7

# Defining direction vectors
dd = [ (-1, 0), (0, 1), (1, 0), (0, -1) ]
ddn = [ (-1, 0), (-1, 1), (0, 1), (1, 1), (1, 0), (1, -1), (0, -1), (-1, -1) ]

# Function to read a list of integers from standard input
def LI( ): return [int(x) for x in sys.stdin.readline().split()]

# Function to read a list of integers from standard input, subtracting 1 from each element
def LI_( ): return [int(x) - 1 for x in sys.stdin.readline().split()]

# Function to read a list of floats from standard input
def LF( ): return [float(x) for x in sys.stdin.readline().split()]

# Function to read a single line from standard input as a list of strings
def LS( ): return sys.stdin.readline().split()

# Function to read a single integer from standard input
def I( ): return int(sys.stdin.readline())

# Function to read a single float from standard input
def F( ): return float(sys.stdin.readline())

# Function to read a single string from standard input
def S( ): return input()

# Function to print a string with a newline character at the end
def pf(s): return print(s, flush=True)

# Main function
def main( ):
    # Reading input string and number of occurrences of '1' required
    s = S( )
    k = I( )

    # Finding the length of the substring consisting only of '1's
    l = 0
    for c in s:
        if c != '1':
            # If the length of the substring is greater than or equal to the required number of occurrences, return 1
            if l >= k:
                return 1
            break
        l += 1

    # If the length of the substring is less than the required number of occurrences, return the character after the substring
    return s[l]

# Calling the main function and printing the result
print(main())
