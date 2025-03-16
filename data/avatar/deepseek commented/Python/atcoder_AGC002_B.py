import sys, re  # Importing necessary modules for input/output and regular expressions
from collections import deque, defaultdict, Counter  # Importing specialized data structures
from math import ceil, sqrt, hypot, factorial, pi, sin, cos, radians  # Importing mathematical functions
from itertools import accumulate, permutations, combinations, product  # Importing itertools for combinatorial functions
from operator import itemgetter, mul  # Importing operators for functional programming
from copy import deepcopy  # Importing deepcopy for deep copying of objects
from string import ascii_lowercase, ascii_uppercase, digits  # Importing string constants
from bisect import bisect, bisect_left  # Importing bisect for binary search
from fractions import gcd  # Importing gcd for greatest common divisor
from heapq import heappush, heappop  # Importing heapq for priority queue operations
from functools import reduce  # Importing reduce for functional programming

# Function to read a single line of input from stdin
def input():
    return sys.stdin.readline().strip()

# Function to convert a single input line to an integer
def INT():
    return int(input())

# Function to read multiple integers from a single line of input
def MAP():
    return map(int, input().split())

# Function to read a list of integers from a single line of input
def LIST():
    return list(map(int, input().split()))

# Function to read multiple lines of input and return them as a list of tuples
def ZIP(n):
    return zip(*(MAP() for _ in range(n)))

# Setting the recursion limit to a higher value to avoid recursion errors
sys.setrecursionlimit(10**9)

# Defining a constant for infinity
INF = float('inf')

# Defining a constant for modulo operation
mod = 10**9 + 7

# Reading the number of balls (N) and the number of operations (M)
N, M = MAP()

# Initializing the list of balls with pairs [white pieces, red pieces]
balls = [[1, 0] for _ in range(N)]

# Special initialization for the first ball
balls[0] = [0, 1]

# Loop to process each operation
for _ in range(M):
    x, y = MAP()  # Reading the indices of the balls to be swapped
    w_x, r_x = balls[x - 1]  # Extracting the current state of ball x
    w_y, r_y = balls[y - 1]  # Extracting the current state of ball y
    
    # Swapping the balls if possible
    if w_x >= 1 and r_x >= 1:
        balls[x - 1][0] -= 1
        balls[y - 1][1] += 1
    elif w_x == 0:
        balls[x - 1][1] -= 1
        balls[y - 1][1] += 1
    else:
        balls[x - 1][0] -= 1
        balls[y - 1][0] += 1

# Counting the number of balls with at least one red or white piece
ans = 0
for i in range(N):
    if balls[i][1]:
        ans += 1

# Printing the final count
print(ans)
