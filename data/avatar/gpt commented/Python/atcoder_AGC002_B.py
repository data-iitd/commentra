# Import necessary libraries
import sys, re
from collections import deque, defaultdict, Counter
from math import ceil, sqrt, hypot, factorial, pi, sin, cos, radians
from itertools import accumulate, permutations, combinations, product
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

# Function to read multiple lists of integers and return them as zipped tuples
def ZIP(n): 
    return zip(*(MAP() for _ in range(n)))

# Set the recursion limit to a high value to allow deep recursion
sys.setrecursionlimit(10 ** 9)

# Define constants for infinity and modulo
INF = float('inf')
mod = 10 ** 9 + 7

# Read the number of balls (N) and the number of operations (M)
N, M = MAP()

# Initialize a list to represent the state of each ball (weight and radius)
balls = [[1, 0] for _ in range(N)]
balls[0] = [0, 1]  # Set the first ball's state

# Process each operation
for _ in range(M):
    x, y = MAP()  # Read the indices of the balls to operate on
    w_x, r_x = balls[x - 1]  # Get the state of ball x
    w_y, r_y = balls[y - 1]  # Get the state of ball y
    
    # Update the states of the balls based on their weights and radii
    if w_x >= 1 and r_x >= 1:
        balls[x - 1][0] -= 1  # Decrease weight of ball x
        balls[y - 1][1] += 1  # Increase radius of ball y
    elif w_x == 0:
        balls[x - 1][1] -= 1  # Decrease radius of ball x
        balls[y - 1][1] += 1  # Increase radius of ball y
    else:
        balls[x - 1][0] -= 1  # Decrease weight of ball x
        balls[y - 1][0] += 1  # Increase weight of ball y

# Calculate the number of balls with a non-zero radius
ans = 0
for i in range(N):
    if balls[i][1]:  # Check if the radius of the ball is non-zero
        ans += 1  # Increment the count of balls with non-zero radius

# Print the final count of balls with non-zero radius
print(ans)
