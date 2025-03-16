# Import necessary libraries and modules
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
import numpy as np

# Define constants and global variables
N = INT()  # Number of inputs
S = [input().strip().split() for _ in range(N)]  # List of strings as inputs
march = ["M", "A", "R", "C", "H"]  # List of marching orders
march_lis = [0] * 5  # List to store the count of each marching order
ans = 0  # Variable to store the answer
INF = float('inf')  # Infinity value
mod = 10 ** 9 + 7  # Modulus value

# Define functions if any
# Function to read input as integer
def input(): return sys.stdin.readline().strip()
# Function to read input as list of integers
def LIST(): return list(map(int, input().split()))
# Function to read input as list of integers with given number of inputs
def ZIP(n): return zip(*(LIST() for _ in range(n)))
# Set recursion limit
sys.setrecursionlimit(10 ** 9)

# Main logic of the code
# Initialize march_lis with zeros
march_lis = [0] * 5
# Iterate through each string in S and increment the count of the corresponding marching order in march_lis
for s in S:
    if s[0].upper() in march:
        march_lis[march.index(s[0].upper())] += 1
# Calculate the answer by finding the triple product of the counts of each marching order
for x, y, z in combinations(march_lis, 3):
    ans += x * y * z
# Print the answer
print(ans)
