
import sys
import math
from collections import defaultdict
sys.setrecursionlimit(10 ** 7)

# Function to read input from standard input
def input():
    return sys.stdin.readline().rstrip()[:-1]

# Define the modulus value
mod = 10 ** 9 + 7

# Function to return an integer input
def I():
    return int(input())

# Function to return a list of integers as input
def III():
    return list(map(int, input().split()))

# Function to create a list of lists based on the given number of rows and columns
def Line(N, num):
    if N <= 0:
        return [[[]] * num]
    elif num == 1:
        return [list(map(int, input().split())) for _ in range(N)]
    else:
        read_all = [tuple(II()) for _ in range(N)]
        return list(map(list, zip(*read_all)))

# Initialize variables
N = I()
a = III()
max_val = 0
max_sign = 0
max_index = -1

# Iterate through the list 'a' to find the maximum absolute value and its sign
for i, a0 in enumerate(a):
    # Update the maximum value and its sign if the current value is greater
    if abs(a0) > max_val:
        max_val = abs(a0)
        max_sign = my_sign(a0)
        max_index = i

# Determine the output based on the sign of the maximum value
if max_sign == 0:
    # If the maximum value is zero, print zero
    print(0)
elif max_sign == 1:
    # If the maximum value is positive, print the required output
    print(2 * N - 1)
    # Print the indices of the maximum value and the first element
    print(max_index + 1, 1)
    # Print the indices of the other elements in pairs
    for i in range(1, N):
        print(i + 1, i + 2)
else:
    # If the maximum value is negative, print the required output
    print(2 * N - 1)
    # Print the indices of the maximum value and the first element
    print(max_index + 1, 1)
    # Print the indices of the other elements in reverse order
    for i in range(N - 1, 0, -1):
        print(i + 1, i)