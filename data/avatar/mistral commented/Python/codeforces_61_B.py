# Importing necessary libraries
import collections
import heapq
import sys
import math
import itertools
import bisect
from io import BytesIO, IOBase
import os

# Function to check if given indices are valid
def valid(i, j, n, m):
    """
    This function checks if given indices (i, j) are valid within the given dimensions (n, m).
    """
    if i < n and i >= 0 and j >= 0 and j < m:
        return True
    return False

# Function to calculate sum of first n natural numbers
def sumn(i, n):
    """
    This function calculates the sum of first n natural numbers.
    """
    return (n - i) * (i + n) // 2

# Function to calculate square root of a number using quadratic formula
def sqfun(a, b, c):
    """
    This function calculates the square root of a number using quadratic formula.
    """
    return (-b + math.sqrt(b * b - 4 * a * c)) // 2 * a

# Function to read a single line as a tuple of integers
def value():
    """
    This function reads a single line as a tuple of integers.
    """
    return tuple(map(int, input().split()))

# Function to read a single line as a list of integers
def values():
    """
    This function reads a single line as a list of integers.
    """
    return list(map(int, sys.stdin.readline().split()))

# Function to read a single integer
def inp():
    """
    This function reads a single integer from the standard input.
    """
    return int(input())

# Function to read a single integer from the standard input as a string
def instr():
    """
    This function reads a single string from the standard input.
    """
    return input()

# Function to read a list of integers
def inlst():
    """
    This function reads a list of integers from the standard input.
    """
    return [int(i) for i in input().split()]

# Function to read a list of integers from the standard input
def inlsts():
    """
    This function reads a list of integers from the standard input.
    """
    return [int(i) for i in sys.stdin.readline().split()]

# Function to read a single integer from the standard input
def inp():
    """
    This function reads a single integer from the standard input.
    """
    return int(input())

# Function to read a single integer from the standard input
def inps():
    """
    This function reads a single integer from the standard input.
    """
    return int(sys.stdin.readline())

# Function to read a single string from the standard input
def instr():
    """
    This function reads a single string from the standard input.
    """
    return input()

# Function to convert a string to a list
def stlst():
    """
    This function converts a string to a list.
    """
    return [i for i in input().split()]

# Main function to solve the problem
def solve():
    """
    This function reads three strings from the standard input, generates all possible permutations of these strings,
    and checks if the given string is present in the list of permutations. If it is, then the function prints 'ACC',
    otherwise it prints 'WA'.
    """
    l = []
    for i in range(3):
        l.append(f(input()))
    t = itertools.permutations(l, len(l))
    l = []
    for i in t:
        l.append("".join(i))
    for i in range(inp()):
        if f(instr()) in l:
            print('ACC')
        else:
            print('WA')

# Starting the program
if __name__ == "__main__":
    solve()
