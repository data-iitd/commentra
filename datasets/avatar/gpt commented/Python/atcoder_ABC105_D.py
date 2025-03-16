from sys import stdin
from collections import Counter
import numpy as np

# Read the values of N and M from standard input
N, M = [int(x) for x in stdin.readline().split()]

# Read the array A from standard input and convert it to a NumPy array of int64 type
A = np.array([int(a) for a in stdin.readline().split()], dtype=np.int64)

# Calculate cumulative remainders of the array A when divided by M
# Start with a 0 to handle the case of subarrays starting from index 0
cum_remainders = (np.hstack([0, A]) % M).cumsum() % M

# Count the occurrences of each remainder using Counter
remainder_counts = Counter(cum_remainders)

# Initialize a variable to count the number of valid combinations
combinations = 0

# Calculate the number of combinations of indices that have the same remainder
for count in remainder_counts.values():
    combinations += count * (count - 1) // 2  # Combinations of 2 from count

# Output the total number of combinations found
print(combinations)
