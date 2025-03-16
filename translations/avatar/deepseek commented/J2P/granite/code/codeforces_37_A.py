

import sys

# Read the number of integers
n = int(input())

# Create a dictionary to store the frequency of each integer
freq = {}

# Read n integers and update their counts in the dictionary
for _ in range(n):
    val = int(input())
    freq[val] = freq.get(val, 0) + 1

# Initialize max to the smallest possible integer value
max_count = float('-inf')

# Iterate through the dictionary to find the maximum count
for count in freq.values():
    max_count = max(max_count, count)

# Print the maximum count and the size of the dictionary
print(max_count, len(freq))

# End of code
