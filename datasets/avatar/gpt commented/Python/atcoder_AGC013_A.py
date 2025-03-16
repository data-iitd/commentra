# Import necessary libraries
import sys, re
from collections import deque, defaultdict, Counter
from math import ceil, sqrt, hypot, factorial, pi, sin, cos, radians
from itertools import groupby, accumulate, permutations, combinations, product
from operator import itemgetter, mul
from copy import deepcopy
from string import ascii_lowercase, ascii_uppercase, digits
from bisect import bisect, bisect_left
from fractions import gcd
from heapq import heappush, heappop
from functools import reduce

# Function to read a line of input and strip whitespace
def input(): 
    return sys.stdin.readline().strip()

# Function to read an integer from input
def INT(): 
    return int(input())

# Function to read a list of integers from input
def MAP(): 
    return map(int, input().split())

# Function to read a list of integers and return it as a list
def LIST(): 
    return list(map(int, input().split()))

# Function to read multiple lists of integers and return them as tuples
def ZIP(n): 
    return zip(*(MAP() for _ in range(n)))

# Set the recursion limit to a high value
sys.setrecursionlimit(10 ** 9)

# Define a constant for infinity
INF = float('inf')

# Define a constant for the modulo value
mod = 10 ** 9 + 7

# Read the number of elements
N = INT()

# Read the list of integers
A = LIST()

# Remove consecutive duplicates from the list
A = [k for k, g in groupby(A)]

# Update N to the new length of A after removing duplicates
N = len(A)

# Initialize the index and answer counter
i = 1
ans = 0

# Loop through the list to count the number of peaks and valleys
while i < N - 1:
    # Check if the current element is a peak or a valley
    if A[i - 1] < A[i] > A[i + 1] or A[i - 1] > A[i] < A[i + 1]:
        ans += 1  # Increment the answer for each peak/valley found
        i += 1    # Skip the next element to avoid double counting
    i += 1  # Move to the next element

# Print the total count of peaks and valleys plus one
print(ans + 1)
