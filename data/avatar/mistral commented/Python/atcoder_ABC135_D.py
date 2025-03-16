########
# Code #
########

# Import necessary libraries
import sys
import math
from collections import defaultdict
sys.setrecursionlimit(10 ** 7)

# Function to take input from standard input
def input():
    return sys.stdin.readline().rstrip()[:-1]

# Define the modulus value
mod = 10 ** 9 + 7

# Function to read an integer
def I():
    return int(input())

# Function to read a list of integers
def III():
    return list(map(int, input().split()))

# Function to read a list of lists (2D array)
def Line(N):
    read_all = [tuple(map(int, input().split())) for _ in range(N)]
    return list(map(list, zip(*read_all)))

# Input the string S and its length n
S = str(input())
n = len(S)

# Base case: if the length of the string is 1
if n == 1:
    # Check if the string is '5' or '?' and print 1 if true, else print 0
    if S == '5' or S == '?':
        print(1)
    else:
        print(0)
        exit()

# Initialize a 2D array dp of size (n, 13) with all elements initialized to 0
dp = [[0] * 13 for i in range(n)]

# Iterate through each index i from 0 to n-1
for i in range(n):
    # If i is the first index, process it differently
    if i == 0:
        # If the character at index i is not '?', update the dp array accordingly
        if S[i] != '?':
            dp[i][int(S[i])] += 1
        # If the character at index i is '?', update all elements in the dp array accordingly
        else:
            for j in range(10):
                dp[i][j] += 1
    # If i is not the first index, process it differently
    else:
        # If the character at index i is not '?', update the dp array accordingly
        if S[i] != '?':
            for k in range(13):
                dp[i][(k * 10 + int(S[i])) % 13] += dp[i - 1][k]
        # If the character at index i is '?', update all elements in the dp array accordingly
        else:
            for j in range(10):
                for k in range(13):
                    dp[i][(k * 10 + j) % 13] += dp[i - 1][k]
            # Update all elements in the dp array with the current value modulo mod
            for k in range(13):
                dp[i][k] %= mod

# Print the final answer, which is dp[n-1][5]
print(dp[n - 1][5])
