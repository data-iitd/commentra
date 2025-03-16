from sys import stdin
from collections import Counter
import numpy as np

# Read the values of N and M from the standard input
N, M = [int(x) for x in stdin.readline().split()]

# Read the array A from the standard input
A = np.array([int(a) for a in stdin.readline().split()], dtype=np.int64)

# Calculate the cumulative remainders of the array A modulo M
# Include a 0 at the beginning to handle the case when the cumulative sum starts from 0
cum_remainders = (np.hstack([0, A]) % M).cumsum() % M

# Count the occurrences of each remainder
remainder_counts = Counter(cum_remainders)

# Initialize the number of combinations
combinations = 0

# Calculate the number of combinations where the difference between two remainders is a multiple of M
for count in remainder_counts.values():
    combinations += count * (count - 1) // 2

# Print the number of combinations
print(combinations)
