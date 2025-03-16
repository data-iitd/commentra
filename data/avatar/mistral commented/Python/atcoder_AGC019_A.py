# Import necessary libraries and modules
import sys, re
from collections import deque, defaultdict, Counter
from math import sqrt, hypot, factorial, pi, sin, cos, radians
if sys.version_info.minor >= 5: from math import gcd
else: from fractions import gcd
from heapq import heappop, heappush, heapify, heappushpop
from bisect import bisect_left, bisect_right
from itertools import permutations, combinations, product
from operator import itemgetter, mul
from copy import deepcopy
from functools import reduce, partial
from fractions import Fraction
from string import ascii_lowercase, ascii_uppercase, digits

# Define helper functions
def input():
    """
    Reads a line from standard input and returns it as a string.
    """
    return sys.stdin.readline().strip()

def ceil(a, b=1):
    """
    Returns the smallest integer greater than or equal to the
    quotient of a and b.
    """
    return int(-(-a//b))

def round(x):
    """
    Rounds a number to the nearest integer.
    """
    return int((x*2+1)//2)

def fermat(x, y, MOD):
    """
    Calculates x^y modulo MOD using Fermat's little theorem.
    """
    return pow(x, y, MOD) % MOD

def lcm(x, y):
    """
    Returns the least common multiple of x and y.
    """
    return (x*y)//gcd(x, y)

def lcm_list(nums):
    """
    Returns the least common multiple of a list of numbers.
    """
    return reduce(lcm, nums, initial=1)

sys.setrecursionlimit(10**9)
INF = float('inf')
MOD = 10**9 + 7

# Read input
q, h, s, d = MAP()
n = INT()

# Calculate the length of the longest segment that can be formed
# using the given resources
best1L = min(q*4, h*2, s)
best2L = min(d, best1L*2)

# Check if n is even
if n % 2 == 0:
    # If it is, print the length of the longest segment that can be formed
    # by dividing n into pairs and using the best2L length for each pair
    print(best2L * (n//2))
else:
    # If n is odd, print the length of the longest segment that can be formed
    # by dividing n-1 into pairs and using the best2L length for each pair,
    # and adding the best1L length at the end
    print(best2L * (n//2) + best1L)
