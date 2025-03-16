# coding:utf-8

import sys
from collections import Counter, defaultdict

# Define constants for infinity and modulo operations
INF = float('inf')
MOD = 10 ** 9 + 7

# Function to read a list of integers from input
def LI(): return [int(x) for x in sys.stdin.readline().split()]

# Function to read a list of integers from input and adjust by subtracting 1 from each
def LI_(): return [int(x) - 1 for x in sys.stdin.readline().split()]

# Function to read a list of strings from input
def LS(): return sys.stdin.readline().split()

# Function to read a single integer from input
def II(): return int(sys.stdin.readline())

# Function to read a single string from input
def SI(): return input()

def main():
    # Read the number of characters
    n = II()
    
    # Read the string of characters
    S = SI()
    
    # Count the occurrences of each character in the string
    C = Counter(S)

    # Determine if the count of 'R' is greater than the count of non-'R' characters
    return 'Yes' if C['R'] > n - C['R'] else 'No'

# Execute the main function and print the result
print(main())
