import sys, re
from collections import deque, defaultdict, Counter
from math import sqrt, hypot, factorial, pi, sin, cos, radians

# Import gcd function based on Python version
if sys.version_info.minor >= 5:
    from math import gcd
else:
    from fractions import gcd

from heapq import heappop, heappush, heapify, heappushpop
from bisect import bisect_left, bisect_right
from itertools import permutations, combinations, product
from operator import itemgetter, mul
from copy import deepcopy
from functools import reduce, partial
from fractions import Fraction
from string import ascii_lowercase, ascii_uppercase, digits

# Function to read a line of input
def input():
    return sys.stdin.readline().strip()

# Function to compute the ceiling of a divided by b
def ceil(a, b=1):
    return int(-( -a // b))

# Function to round a number to the nearest integer
def round(x):
    return int((x * 2 + 1) // 2)

# Function to compute Fermat's little theorem for modular inverse
def fermat(x, y, MOD):
    return x * pow(y, MOD - 2, MOD) % MOD

# Function to compute the least common multiple of two numbers
def lcm(x, y):
    return (x * y) // gcd(x, y)

# Function to compute the least common multiple of a list of numbers
def lcm_list(nums):
    return reduce(lcm, nums, initial=1)

# Function to read an integer from input
def INT():
    return int(input())

# Function to read a list of integers from input
def MAP():
    return map(int, input().split())

# Function to read a list of integers into a list
def LIST():
    return list(map(int, input().split()))

# Set the maximum recursion limit
sys.setrecursionlimit(10 ** 9)

# Define constants for infinity and modulo
INF = float('inf')
MOD = 10 ** 9 + 7

# Read input values for costs of different types of drinks
q, h, s, d = MAP()

# Read the number of drinks to be purchased
n = INT()

# Calculate the best price for 1 liter of drink
best1L = min(q * 4, h * 2, s)

# Calculate the best price for 2 liters of drink
best2L = min(d, best1L * 2)

# Calculate and print the total cost based on whether n is even or odd
if n % 2 == 0:
    print(best2L * (n // 2))  # Total cost for even number of drinks
else:
    print(best2L * (n // 2) + best1L)  # Total cost for odd number of drinks
