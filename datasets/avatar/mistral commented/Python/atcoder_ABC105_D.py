# Import necessary libraries
from sys import stdin
from collections import Counter
import numpy as np

# Read input number of rows and columns
N, M = [int(x) for x in stdin.readline().split()]

# Initialize numpy array 'A' with given dimensions and data type
A = np.array([int(a) for a in stdin.readline().split()], dtype=np.int64)

# Calculate cumulative remainders by performing modulo M operation on the sum of previous remainders and current element
cum_remainders = (np.hstack([np.zeros(1), A]) % M).cumsum() % M

# Count the occurrences of each cumulative remainder
remainder_counts = Counter(cum_remainders)

# Calculate the number of combinations of elements having the same remainder
combinations = 0
for count in remainder_counts.values():
    combinations += count * (count - 1) // 2

# Print the result
print(combinations)
