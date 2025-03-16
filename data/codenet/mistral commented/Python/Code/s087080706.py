# Define variables
n, m, x = (int(i) for i in input().split())

# Read input for list 'a'
a = [int(i) for i in input().split()]

# Initialize answer variable
ans = 0

# Import bisect module for binary search
from bisect import bisect

# Perform binary search to find index 'i'
i = bisect(a, x)

# Calculate answer
ans = min(len(a[:i]), len(a[i:]))

# Print the answer
print(ans)