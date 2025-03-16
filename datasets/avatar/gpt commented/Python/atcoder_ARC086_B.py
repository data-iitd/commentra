import sys
import math
from collections import defaultdict

# Set the recursion limit to a higher value to handle deep recursions
sys.setrecursionlimit(10 ** 7)

# Function to read a line of input and strip the newline character
def input():
    return sys.stdin.readline()[:-1]

# Define a modulo constant for later use
mod = 10 ** 9 + 7

# Function to read an integer from input
def I(): 
    return int(input())

# Function to read a list of integers from input
def II(): 
    return map(int, input().split())

# Function to read a list of integers and return it as a list
def III(): 
    return list(map(int, input().split()))

# Function to read a specific format of input based on the number of elements
def Line(N, num):
    # If N is less than or equal to 0, return an empty list
    if N <= 0:
        return [[]] * num
    # If num is 1, read N integers and return them as a list
    elif num == 1:
        return [I() for _ in range(N)]
    # Otherwise, read N tuples of integers and return them as a transposed list
    else:
        read_all = [tuple(II()) for _ in range(N)]
        return map(list, zip(*read_all))

# Function to determine the sign of a number
def my_sign(x):
    return (x > 0) - (x < 0)

# Read the number of elements
N = I()

# Read the list of integers
a = III()

# Initialize variables to track the maximum absolute value, its sign, and index
max_val = 0
max_sign = 0
max_index = -1

# Loop through the list to find the maximum absolute value and its properties
for i, a0 in enumerate(a):
    if abs(a0) > max_val:
        max_val = abs(a0)
        max_sign = my_sign(a0)
        max_index = i

# Check the sign of the maximum value and print results accordingly
if max_sign == 0:
    # If the maximum sign is zero, print 0
    print(0)
elif max_sign == 1:
    # If the maximum sign is positive, print the number of operations and the operations
    print(2 * N - 1)
    for i in range(N):
        print(max_index + 1, i + 1)
    for i in range(N - 1):
        print(i + 1, i + 2)
else:
    # If the maximum sign is negative, print the number of operations and the operations
    print(2 * N - 1)
    for i in range(N):
        print(max_index + 1, i + 1)
    for i in range(1, N)[::-1]:
        print(i + 1, i)
