import collections
import heapq
import sys
import math
import itertools
import bisect
from io import BytesIO, IOBase
import os

# Function to check if the given indices (i, j) are within the bounds of a grid of size n x m
def valid(i, j, n, m):
    if i < n and i >= 0 and j >= 0 and j < m:
        return True
    return False

# Function to calculate the sum of integers from i to n using the formula for the sum of an arithmetic series
def sumn(i, n):
    return (n - i) * (i + n) / 2

# Function to solve a quadratic equation ax^2 + bx + c = 0 and return one of its roots
def sqfun(a, b, c):
    return (-b + math.sqrt(b * b - 4 * a * c)) / (2 * a)

# Function to read a single line of input and return it as a tuple of integers
def value():
    return tuple(map(int, input().split()))

# Function to read a single line of input from stdin and return it as a tuple of integers
def values():
    return tuple(map(int, sys.stdin.readline().split()))

# Function to read a single line of input and return it as a list of integers
def inlst():
    return [int(i) for i in input().split()]

# Function to read a single line of input from stdin and return it as a list of integers
def inlsts():
    return [int(i) for i in sys.stdin.readline().split()]

# Function to read a single integer from input
def inp():
    return int(input())

# Function to read a single integer from stdin
def inps():
    return int(sys.stdin.readline())

# Function to read a single line of input and return it as a string
def instr():
    return input()

# Function to read a single line of input and return it as a list of strings
def stlst():
    return [i for i in input().split()]

# Function to process a string by removing specific characters and converting it to lowercase
def f(s):
    r = ''
    for i in s:
        if i not in ['-', ';', '_']:
            r += i.lower()
    return r

# Main function to solve the problem
def solve():
    l = []
    # Read three lines of input, process them, and store the results in a list
    for i in range(3):
        l.append(f(input()))
    
    # Generate all permutations of the processed strings
    t = itertools.permutations(l, len(l))
    l = []
    # Create a list of concatenated permutations
    for i in t:
        l.append("".join(i))
    
    # Read the number of test cases and check if the processed input is in the list of permutations
    for i in range(inp()):
        if f(instr()) in l:
            print('ACC')  # Accepted
        else:
            print('WA')   # Wrong Answer

# Entry point of the program
if __name__ == "__main__":
    solve()
