
# Fast I/O setup
import sys
input = sys.stdin.readline

# Declare variables to store input values
A,B,C,K = map(int, input().split())

# Check if the sum of A and B is greater than or equal to K
if A + B >= K:
    # Output the minimum of A and K
    print(min(A, K))
else:
    # Calculate the result by subtracting the excess amount from A
    print(A - (K - (A + B)))

