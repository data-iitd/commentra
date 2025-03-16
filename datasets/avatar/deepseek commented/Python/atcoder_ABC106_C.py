import math, string, itertools, fractions, heapq, collections, re, array, bisect, sys, random, time, copy, functools
sys.setrecursionlimit(10 ** 7)  # Set a high recursion limit to prevent stack overflow
inf = 10 ** 20  # A very large number to represent infinity
eps = 1.0 / 10 ** 10  # A small number to handle precision issues
mod = 10 ** 9 + 7  # A large prime number used for modular arithmetic
dd = [(-1, 0), (0, 1), (1, 0), (0, -1)]  # Directions for movement in a grid (up, right, down, left)
ddn = [(-1, 0), (-1, 1), (0, 1), (1, 1), (1, 0), (1, -1), (0, -1), (-1, -1)]  # Directions for movement in a grid with diagonals

# Functions to read input more efficiently
def LI(): return [int(x) for x in sys.stdin.readline().split()]
def LI_(): return [int(x) - 1 for x in sys.stdin.readline().split()]
def LF(): return [float(x) for x in sys.stdin.readline().split()]
def LS(): return sys.stdin.readline().split()
def I(): return int(sys.stdin.readline())
def F(): return float(sys.stdin.readline())
def S(): return input()
def pf(s): return print(s, flush=True)

# Main function to execute the program
def main():
    s = S()  # Read the input string
    k = I()  # Read the integer k
    l = 0  # Initialize a counter for leading '1's
    for c in s:  # Loop through each character in the string
        if c != '1':  # Check if the character is not '1'
            break  # Exit the loop if a non-'1' character is found
        l += 1  # Increment the counter for each '1' found
    if l >= k:  # Check if the number of leading '1's is greater than or equal to k
        return 1  # Return 1 if true
    return s[l]  # Return the character at the position of the first non-'1' character

# Print the result of the main function
print(main())
