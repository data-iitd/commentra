# coding:utf-8
# Import necessary libraries
import sys
from collections import Counter, defaultdict

# Define constants
INF = float('inf')
MOD = 10 ** 9 + 7

def LI():
    """
    Read a line from standard input as a list of integers.
    """
    return [int(x) for x in sys.stdin.readline().split()]

def LI_():
    """
    Read a line from standard input as a list of integers, subtracting 1 from each element.
    """
    return [int(x) - 1 for x in sys.stdin.readline().split()]

def LS():
    """
    Read a line from standard input as a list of strings.
    """
    return sys.stdin.readline().split()

def II():
    """
    Read a single integer from standard input.
    """
    return int(sys.stdin.readline())

def SI():
    """
    Read a single string from standard input.
    """
    return input()

def main():
    """
    The main function where the problem is solved.
    """
    # Read the number of strings and the string itself
    n = II()
    S = SI()

    # Count the occurrences of each character in the string
    C = Counter(S)

    # Determine the answer based on the count of 'R'
    return 'Yes' if C['R'] > n - C['R'] else 'No'

# Run the main function
print(main())