# Import necessary libraries
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

# Function to read a line of input and strip whitespace
def input(): 
    return sys.stdin.readline().strip()

# Function to read an integer from input
def INT(): 
    return int(input())

# Function to read a map of integers from input
def MAP(): 
    return map(int, input().split())

# Function to read a list of integers from input
def LIST(): 
    return list(map(int, input().split()))

# Function to read multiple lists of integers and zip them together
def ZIP(n): 
    return zip(*(MAP() for _ in range(n)))

# Set the recursion limit to a high value
sys.setrecursionlimit(10 ** 9)

# Define constants for infinity and modulo
INF = float('inf')
mod = 10 ** 9 + 7

# Import numpy for numerical operations (though not used in the code)
import numpy as np

# Read the number of strings to process
N = INT()

# Read N strings from input
S = [input() for _ in range(N)]

# Define the target characters to count
march = ["M", "A", "R", "C", "H"]

# Initialize a list to count occurrences of each target character
march_lis = [0] * 5

# Count the occurrences of each character in the input strings
for s in S:
    if s[0].upper() in march:
        march_lis[march.index(s[0].upper())] += 1

# Initialize the answer variable to store the result
ans = 0

# Calculate the number of ways to choose 3 different characters from the counts
for x, y, z in combinations(march_lis, 3):
    ans += x * y * z

# Print the final answer
print(ans)
