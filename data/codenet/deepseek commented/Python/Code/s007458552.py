
# coding:utf-8

import sys
from collections import Counter, defaultdict

INF = float('inf')  # Define a constant for infinity
MOD = 10 ** 9 + 7  # Define a constant for modulo operation

def LI(): return [int(x) for x in sys.stdin.readline().split()]  # Function to read a list of integers
def LI_(): return [int(x) - 1 for x in sys.stdin.readline().split()]  # Function to read a list of integers decremented by 1
def LS(): return sys.stdin.readline().split()  # Function to read a list of strings
def II(): return int(sys.stdin.readline())  # Function to read an integer
def SI(): return input()  # Function to read a string


def main():
    n = II()  # Read the number of characters
    S = SI()  # Read the string S
    C = Counter(S)  # Create a Counter object from the string S

    # Check if the count of 'R' characters is greater than the count of non-'R' characters
    return 'Yes' if C['R'] > n - C['R'] else 'No'


print(main())  # Print the result of the main function


