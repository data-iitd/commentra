# Import necessary modules
from sys import stdin, stdout, setrecursionlimit
from math import gcd, ceil, sqrt
from collections import Counter
from bisect import bisect_left, bisect_right

# Define input functions for convenience
ii1 = lambda: int(stdin.readline().strip())  # Read an integer from input
is1 = lambda: stdin.readline().strip()        # Read a string from input
iia = lambda: list(map(int, stdin.readline().strip().split()))  # Read a list of integers from input
isa = lambda: stdin.readline().strip().split()  # Read a list of strings from input

# Set the recursion limit to a higher value to prevent recursion depth errors
setrecursionlimit(100000)

# Define a constant for modulo operations
mod = 1000000007

# Read the integer k from input
k = ii1()

# Initialize a variable to hold the current value of t
t = 0

# Loop through numbers from 1 to k
for i in range(1, k + 1):
    # Update t by appending a '7' at the end and taking modulo k
    t = (t % k) * 10 + 7
    
    # Check if the current value of t is divisible by k
    if t % k == 0:
        print(i)  # Print the current index if divisible
        break
else:
    # If no index was found, print -1
    print(-1)
