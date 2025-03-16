import sys
import math

def main():
    # Read the height H, width W, and number of obstacles N from the standard input.
    H, W, N = map(int, sys.stdin.readline().split())
    # Calculate the maximum dimension A between H and W.
    A = max(H, W)
    # Print the result, which is the number of rows or columns needed to place all obstacles without overlapping.
    print(math.ceil((N + A - 1) / A))

def max(a, b):
    # If a is smaller than b, return b.
    if a < b:
        return b
    # Otherwise, return a.
    return a

