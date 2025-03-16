import sys, re  # Importing sys for system-related functions and re for regular expressions
from collections import deque, defaultdict, Counter  # Importing collections for data structures
from math import sqrt, hypot, factorial, pi, sin, cos, radians, gcd  # Importing math functions, including gcd for greatest common divisor
if sys.version_info.minor >= 5: from math import gcd  # Using built-in gcd if Python version is 3.5 or higher
else: from fractions import gcd  # Otherwise, using gcd from the fractions module
from heapq import heappop, heappush, heapify, heappushpop  # Importing heapq functions for heap operations
from bisect import bisect_left, bisect_right  # Importing bisect functions for binary search
from itertools import permutations, combinations, product  # Importing itertools functions for combinatorial operations
from operator import itemgetter, mul  # Importing operator functions for item selection and multiplication
from copy import deepcopy  # Importing deepcopy for deep copying of objects
from functools import reduce, partial  # Importing reduce and partial for functional programming
from fractions import Fraction  # Importing Fraction for rational number operations
from string import ascii_lowercase, ascii_uppercase, digits  # Importing string constants

def input(): return sys.stdin.readline().strip()  # Function to read input from stdin

def ceil(a, b=1): return int(-(-a // b))  # Function to calculate ceiling of a divided by b

def round(x): return int((x * 2 + 1) // 2)  # Function to round x to the nearest integer

def fermat(x, y, MOD): return x * pow(y, MOD - 2, MOD) % MOD  # Function to perform Fermat's little theorem

def lcm(x, y): return (x * y) // gcd(x, y)  # Function to calculate least common multiple

def lcm_list(nums): return reduce(lcm, nums, 1)  # Function to calculate lcm of a list of numbers

def INT(): return int(input())  # Function to read an integer input

def MAP(): return map(int, input().split())  # Function to read multiple integer inputs

def LIST(): return list(map(int, input().split()))  # Function to read a list of integers

sys.setrecursionlimit(10**9)  # Setting recursion limit to prevent stack overflow

INF = float('inf')  # Defining infinity for comparisons
MOD = 10**9 + 7  # Defining the modulo value

# Reading input values
q, h, s, d = MAP()
n = INT()

# Calculating the best price for single liters
best1L = min(q * 4, h * 2, s)

# Calculating the best price for double liters
best2L = min(d, best1L * 2)

# Checking if the quantity n is even or odd and printing the total cost accordingly
if n % 2 == 0:
    print(best2L * (n // 2))
else:
    print(best2L * (n // 2) + best1L)
