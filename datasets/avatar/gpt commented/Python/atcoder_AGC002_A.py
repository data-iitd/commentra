# Import necessary libraries
import bisect, collections, copy, heapq, itertools, math, numpy, string
import sys

# Function to read a line from standard input and remove trailing whitespace
def S(): 
    return sys.stdin.readline().rstrip()

# Function to read an integer from standard input
def I(): 
    return int(sys.stdin.readline().rstrip())

# Function to read a list of integers from standard input
def LI(): 
    return list(map(int, sys.stdin.readline().rstrip().split()))

# Function to read a list of strings from standard input
def LS(): 
    return list(sys.stdin.readline().rstrip().split())

# Read two integers from input
a, b = LI()

# Check if the first integer 'a' is positive
if a > 0:
    print('Positive')  # Output 'Positive' if 'a' is greater than 0
elif a <= 0 and b >= 0:
    print('Zero')  # Output 'Zero' if 'a' is non-positive and 'b' is non-negative
else:
    # If 'a' is negative and 'b' is also negative
    if (a + b) % 2 == 0:
        print('Negative')  # Output 'Negative' if the sum of 'a' and 'b' is even
    else:
        print('Positive')  # Output 'Positive' if the sum of 'a' and 'b' is odd
