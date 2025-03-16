#######
# Code
#######

# Import necessary modules and functions
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

# Set recursion limit
sys.setrecursionlimit(10 ** 9)

# Define constants
INF = float('inf')
mod = 10 ** 9 + 7

# Read input number of balls and number of events
N, M = MAP()

# Initialize list of balls with their weight and position
balls = [ [ 1, 0 ] for _ in range(N) ]
balls[0] = [0, 1]

# Process each event
for _ in range(M):
    # Read x and y coordinates of the event
    x, y = MAP()
    
    # Get weight and position of balls at x and y
    w_x, r_x = balls[x - 1]
    w_y, r_y = balls[y - 1]
    
    # Update balls' weights and positions based on the event
    if w_x >= 1 and r_x >= 1:
        # Ball x collides with ball y
        balls[x - 1][0] -= 1
        balls[y - 1][1] += 1
    elif w_x == 0:
        # Ball x is stationary and ball y collides with another ball
        balls[x - 1][1] -= 1
        balls[y - 1][1] += 1
    else:
        # Ball x is moving and collides with ball y
        balls[x - 1][0] -= 1
        balls[y - 1][0] += 1

# Calculate answer
ans = 0
# Iterate through the list of balls and count the number of moving balls
for i in range(N):
    if balls[i][1]:
        ans += 1

# Print the answer
print(ans)
