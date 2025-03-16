# Importing necessary libraries
import collections
import heapq
import sys
import math
import itertools
import bisect
from io import BytesIO, IOBase
import os

# Function to read a single value as a tuple
def value():
    return tuple(map(int, input().split()))

# Function to read multiple values as a tuple
def values():
    return tuple(map(int, sys.stdin.readline().split()))

# Function to read a single value as a list
def inlst():
    return [int(i) for i in input().split()]

# Function to read multiple values as a list
def inlsts():
    return [int(i) for i in sys.stdin.readline().split()]

# Function to read a single value as an integer
def inp():
    return int(input())

# Function to read a single value as an integer from stdin
def inps():
    return int(sys.stdin.readline())

# Function to read a single line as a string
def instr():
    return input()

# Function to read a list of strings
def stlst():
    return [i for i in input().split()]

# Helper function to check if a sub-array of given size exists in a list
def help(a, b, l):
    """
    This function checks if there exists a sub-array of size 'a' in the list 'l' whose sum is equal to 'b'.
    """
    tot = []
    for i in range(b):
        tot.append(l[i * a: i * a + a])
    for i in zip(*tot):
        if sum(i) == b:
            return True
    return False

# Main function to solve the problem
def solve():
    """
    This function reads a string 'x' and checks if there exists any sub-array of size 1, 2, 3, ..., 12 whose sum is equal to 12.
    If such a sub-array is found, it is added to the list 'tot'. Finally, the number of such sub-arrays and their sizes are printed.
    """
    x = instr()
    s = []
    for i in x:
        if i == 'O':
            s.append(0)
        else:
            s.append(1)

    for i in range(1, 13):
        if 12 % i == 0:
            if help(i, 12 // i, s):
                tot.append((12 // i, i))

    print(len(tot), end=' ')
    for a, b in sorted(tot):
        print(f'{a}x{b}', end=' ')
    print()

# Main function to run the code
if __name__ == "__main__":
    for i in range(inp()):
        solve()
