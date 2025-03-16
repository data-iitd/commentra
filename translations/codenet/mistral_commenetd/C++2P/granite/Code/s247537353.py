
import sys

# Read input values from the standard input
A, B, C, K = map(int, sys.stdin.read().split())

# Check if the sum of A and B is greater than or equal to K
if A + B >= K:
    # If true, print the minimum value between A and K
    print(min(A, K))
else:
    # If false, calculate the difference between K and the sum of A and B,
    # and subtract it from A to get the required value
    print(A - (K - (A + B)))

