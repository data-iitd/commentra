# Read input values for n (number of elements), m (not used), and x (the target value)
n, m, x = (int(i) for i in input().split())

# Read the list of integers and store them in the list 'a'
a = [int(i) for i in input().split()]

# Initialize the answer variable to zero
ans = 0

# Import the bisect module for binary search operations
from bisect import bisect

# Use bisect to find the index where 'x' would fit in the sorted list 'a'
i = bisect(a, x)

# Calculate and print the minimum of the lengths of the two partitions of 'a'
# The left partition contains elements less than 'x', and the right partition contains elements greater than or equal to 'x'
print(min(len(a[:i]), len(a[i:])))
