import sys
import math
from collections import defaultdict

# Set the recursion limit to a higher value to handle deep recursions
sys.setrecursionlimit(10 ** 7)

# Function to read input from standard input
def input():
    return sys.stdin.readline()[:-1]

# Define the modulo constant
mod = 10 ** 9 + 7

# Helper functions to read different types of input
def I(): return int(input())
def II(): return map(int, input().split())
def III(): return list(map(int, input().split()))

# Function to read N lines of input and return them as a list of tuples
def Line(N):
    read_all = [tuple(map(int, input().split())) for _ in range(N)]
    return map(list, zip(*read_all))

# Read the string input S
S = str(input())
n = len(S)

# Handle the case where the input string length is 1
if n == 1:
    if S == '5' or S == '?':
        print(1)  # Output 1 if the single character is '5' or '?'
    else:
        print(0)  # Output 0 for any other single character
    exit()

# Initialize a 2D list for dynamic programming
dp = [[0] * 13 for i in range(n)]

# Fill the dp table based on the characters in S
for i in range(n):
    if i == 0:
        # Handle the first character
        if S[i] != '?':
            dp[i][int(S[i])] += 1  # Increment the count for the specific digit
        else:
            # If the character is '?', increment counts for all digits (0-9)
            for j in range(10):
                dp[i][j] += 1
    else:
        # Process subsequent characters
        if S[i] != '?':
            # If the character is a specific digit
            for k in range(13):
                dp[i][(k * 10 + int(S[i])) % 13] += dp[i - 1][k]
        else:
            # If the character is '?', consider all digits (0-9)
            for j in range(10):
                for k in range(13):
                    dp[i][(k * 10 + j) % 13] += dp[i - 1][k]
        
        # Apply modulo to keep the values manageable
        for k in range(13):
            dp[i][k] %= mod

# Output the count of valid numbers that are divisible by 13 and end with digit 5
print(dp[n - 1][5])
