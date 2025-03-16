import collections
import heapq
import sys
import math
import itertools
import bisect
from io import BytesIO, IOBase
import os

# Function to read a single line of input and convert it to a tuple of integers
def value():
    return tuple(map(int, input().split()))

# Function to read a single line of input from stdin and convert it to a tuple of integers
def values():
    return tuple(map(int, sys.stdin.readline().split()))

# Function to read a single line of input and return a list of integers
def inlst():
    return [int(i) for i in input().split()]

# Function to read a single line of input from stdin and return a list of integers
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

# Helper function to determine if a specific arrangement is possible
def help(a, b, l):
    tot = []
    # Create sublists of length 'a' from the list 'l'
    for i in range(b):
        tot.append(l[i * a: i * a + a])
    
    # Check if any combination of the sublists sums to 'b'
    for i in zip(*tot):
        if sum(i) == b:
            return True
    return False

# Main function to solve the problem
def solve():
    tot = []
    x = instr()  # Read the input string
    s = []
    
    # Convert the input string into a list of integers (0 for 'O', 1 for 'X')
    for i in x:
        if i == 'O':
            s.append(0)
        else:
            s.append(1)
    
    # Check for all divisors of 12 to find valid arrangements
    for i in range(1, 13):
        if 12 % i == 0:  # Check if 'i' is a divisor of 12
            if help(i, 12 // i, s):  # Use the helper function to check arrangements
                tot.append((12 // i, i))  # Store valid arrangements as tuples
    
    # Print the number of valid arrangements
    print(len(tot), end=' ')
    
    # Print each valid arrangement in sorted order
    for a, b in sorted(tot):
        print(f'{a}x{b}', end=' ')
    print()  # Print a newline at the end

# Entry point of the program
if __name__ == "__main__":
    # Read the number of test cases and solve each case
    for i in range(inp()):
        solve()
