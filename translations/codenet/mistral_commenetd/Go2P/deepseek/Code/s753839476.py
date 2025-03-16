import sys
import math

# Read input values
n, t, a = map(int, sys.stdin.readline().split())
heights = list(map(float, sys.stdin.readline().split()))

# Initialize variables for minimum difference and index
min_diff = abs(t - heights[0] * 0.006)
min_idx = 0

# Iterate through the remaining heights and find the minimum difference
for i, h in enumerate(heights[1:]):
    diff = abs(t - h * 0.006)
    if diff < min_diff:
        min_diff = diff
        min_idx = i + 1

# Print the result
print(min_idx + 1)
