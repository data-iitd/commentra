import sys, re  # Importing necessary modules for input/output and regular expressions
from collections import deque, defaultdict, Counter  # Importing specialized data structures
from math import ceil, sqrt, hypot, factorial, pi, sin, cos, radians  # Importing mathematical functions
from itertools import groupby, accumulate, permutations, combinations, product  # Importing itertools for combinatorial functions
from operator import itemgetter, mul  # Importing operators for functional programming
from copy import deepcopy  # Importing for deep copy operations
from string import ascii_lowercase, ascii_uppercase, digits  # Importing string constants
from bisect import bisect, bisect_left  # Importing bisect for binary search
from fractions import gcd  # Importing gcd for greatest common divisor
from heapq import heappush, heappop  # Importing heap queue for priority queue operations
from functools import reduce  # Importing reduce for functional programming

def input(): return sys.stdin.readline().strip()  # Function to read input line
def INT(): return int(input())  # Function to read an integer input
def MAP(): return map(int, input().split())  # Function to read map of integers
def LIST(): return list(map(int, input().split()))  # Function to read list of integers
def ZIP(n): return zip(*(MAP() for _ in range(n)))  # Function to read zip of n maps

sys.setrecursionlimit(10**9)  # Setting recursion limit
INF = float('inf')  # Defining infinity constant
mod = 10**9 + 7  # Defining modulo constant

# Reading number of elements
N = INT()
# Reading list of elements
A = LIST()

# Removing consecutive duplicates from list A
A = [k for k, g in groupby(A)]
# Updating N to reflect the new length of A
N = len(A)

# Initializing variables for main logic
i = 1
ans = 0

# Main logic to find peaks
while i < N - 1:
    if A[i - 1] < A[i] > A[i + 1] or A[i - 1] > A[i] < A[i + 1]:
        ans += 1
        i += 1  # Skip next element as it's already checked
    i += 1

# Output the total number of peaks found
print(ans + 1)
