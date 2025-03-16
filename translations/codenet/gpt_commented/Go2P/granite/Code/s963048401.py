
import sys
from bisect import bisect_left

# Initialize a variable for the modulus value
mod = 1000000007

# Read the number of elements
n = int(input())

# Initialize a list to hold the integers
as = []

# Read n integers from input
for _ in range(n):
    as.append(int(input()))

# Initialize a list to hold the unique sorted integers
xs = [as[0]]

# Iterate through the input integers starting from the second element
for j in range(1, n):
    # Use binary search to find the position to insert the current integer
    idx = bisect_left(xs, as[j])
    
    # If the index is equal to the length of xs, append the integer
    if idx == len(xs):
        xs.append(as[j])
    else:
        # Otherwise, replace the existing integer at the found index
        xs[idx] = as[j]

# Print the number of unique integers found
print(len(xs))

