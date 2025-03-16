import sys
import math
from collections import defaultdict
sys.setrecursionlimit(10 ** 7)  # Setting recursion limit to prevent stack overflow

def input():
    return sys.stdin.readline()[:-1]  # Custom input function to read lines without newline

mod = 10 ** 9 + 7  # Modulo value for modulo operations

def I():
    return int(input())  # Function to read an integer input

def II():
    return map(int, input().split())  # Function to read multiple integers

def III():
    return list(map(int, input().split()))  # Function to read a list of integers

def Line(N, num):
    if N <= 0:
        return [[]] * num  # Return a list of empty lists if N is non-positive
    elif num == 1:
        return [I() for _ in range(N)]  # Return a list of N integers if num is 1
    else:
        read_all = [tuple(II()) for _ in range(N)]  # Read N pairs of integers
        return map(list, zip(*read_all))  # Return a list of lists

def my_sign(x):
    return (x > 0) - (x < 0)  # Function to determine the sign of a number

N = I()  # Read the number of elements
a = III()  # Read the list of elements

max_val = 0  # Initialize the maximum value to 0
max_sign = 0  # Initialize the sign of the maximum value to 0
max_index = -1  # Initialize the index of the maximum value to -1

# Find the element with the maximum absolute value
for i, a0 in enumerate(a):
    if abs(a0) > max_val:
        max_val = abs(a0)
        max_sign = my_sign(a0)
        max_index = i

# If the maximum value is zero, print 0
if max_sign == 0:
    print(0)
# If the maximum value is positive, print the sequence of operations
elif max_sign == 1:
    print(2 * N - 1)
    for i in range(N):
        print(max_index + 1, i + 1)  # Print the swap operations
    for i in range(N - 1):
        print(i + 1, i + 2)  # Print the increment operations
# If the maximum value is negative, print the sequence of operations in reverse
else:
    print(2 * N - 1)
    for i in range(N):
        print(max_index + 1, i + 1)  # Print the swap operations
    for i in range(N - 1)[::-1]:
        print(i + 2, i + 1)  # Print the decrement operations in reverse
