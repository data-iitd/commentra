
import sys

# Read the number of pairs (n) and the minimum score (s)
n, s = map(int, input().split())

# Initialize a variable to keep track of the maximum sum of pairs
max_sum = 0

# Loop through each pair of integers
for _ in range(n):
    # Read the two integers f and t
    f, t = map(int, input().split())
    # Update max_sum if the sum of f and t is greater than the current max_sum
    if f + t > max_sum:
        max_sum = f + t

# Print the maximum value between max_sum and s
print(max(max_sum, s))

# End of code
