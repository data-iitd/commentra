import sys

# Function to check and update the minimum value of a variable
def chmin(a, b):
    if a > b:
        a = b
        return True
    return False

# Function to check and update the maximum value of a variable
def chmax(a, b):
    if a < b:
        a = b
        return True
    return False

# Define constants for maximum values
INF = (1 << 30) - 1
INFLL = (1LL << 61) - 1
MOD = 1000000007

# Read input values
A, B, C, K = map(int, sys.stdin.readline().split())

# Check if the sum of A and B is greater than or equal to K
if A + B >= K:
    # Output the minimum of A and K
    print(min(A, K))
else:
    # Calculate the result by subtracting the excess amount from A
    print(A - (K - (A + B)))

# End-of-code
