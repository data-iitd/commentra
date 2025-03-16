
import sys

# Read input values for A, B, C, and K
A, B, C, K = map(int, sys.stdin.read().split())

# Check if the sum of A and B is greater than or equal to K
if A + B >= K:
    # If true, output the minimum of A and K
    print(min(A, K))
else:
    # If false, calculate and output the remaining value after subtracting (K - (A + B)) from A
    print(A - (K - (A + B)))

