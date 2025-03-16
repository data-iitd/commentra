# Import necessary modules
from sys import stdin, stdout, setrecursionlimit
from math import gcd, ceil, sqrt
from collections import Counter
from bisect import bisect_left, bisect_right

# Set recursion limit to avoid stack overflow errors
setrecursionlimit(100000)

# Define constants
mod = 1000000007

# Read an integer from standard input and return it
def ii1():
    return int(stdin.readline().strip())

# Read a string from standard input and return it
def is1():
    return stdin.readline().strip()

# Read a list of integers from standard input and return it
def iia():
    return list(map(int, stdin.readline().strip().split()))

# Read a list of strings from standard input and return it, split by spaces
def isa():
    return stdin.readline().strip().split()

# Set the value of k from standard input
k = ii1()

# Initialize a variable t to 0
t = 0

# Loop from 1 to k
for i in range(1, k+1):
    # Calculate the value of t using the current value of i and k
    t = ( (t % k) * 10 + 7 ) % k
    
    # Check if t is a multiple of k
    if t == 0:
        # Print the value of i and break out of the loop
        print(i)
        break

# If the loop completes without finding a multiple of k, print -1
if t != 0:
    print(-1)
