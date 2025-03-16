import sys, re
from collections import deque, defaultdict, Counter
from math import ceil, sqrt, hypot, factorial, pi, sin, cos, radians
from itertools import accumulate, permutations, combinations, combinations_with_replacement, product, groupby
from operator import itemgetter, mul
from copy import deepcopy, copy
from string import ascii_lowercase, ascii_uppercase, digits
from bisect import bisect, bisect_left, insort, insort_left
from fractions import gcd
from heapq import heappush, heappop
from functools import reduce

# Function to read a single line of input
def input():
    return sys.stdin.readline().strip()

# Function to convert input to an integer
def INT():
    return int(input())

# Function to read a map of integers
def MAP():
    return map(int, input().split())

# Function to convert input to a list of integers
def LIST():
    return list(map(int, input().split()))

# Function to create combinations from a list of tuples
def ZIP(n):
    return zip(*(MAP() for _ in range(n)))

# Set recursion limit to prevent recursion errors
sys.setrecursionlimit(10**9)

# Define constants
INF = float('inf')
mod = 10**9 + 7

# Import numpy for numerical operations
import numpy as np

# Read the number of strings
N = INT()

# Read the list of strings
S = [input() for _ in range(N)]

# List of characters that can be selected
march = ["M", "A", "R", "C", "H"]

# Initialize a list to count occurrences of each character in 'march'
march_lis = [0] * 5

# Count the occurrences of characters in 'march' in the list of strings
for s in S:
    if s[0].upper() in march:
        march_lis[march.index(s[0].upper())] += 1

# Initialize the answer variable
ans = 0

# Calculate the number of combinations of three elements from march_lis
for x, y, z in combinations(march_lis, 3):
    ans += x * y * z

# Print the final answer
print(ans)
