import math
import sys

# Read a long integer N from user input
N = int(input())

# Initialize a variable to hold the minimum value
min_value = 0

# Loop to read five long integers and find the minimum
for i in range(5):
    if i == 0:
        min_value = int(input())
    else:
        # For subsequent iterations, update min_value if a smaller value is found
        min_value = min(min_value, int(input()))

# Calculate the result by dividing N by min_value, rounding up, and adding 4
result = math.ceil(N / min_value) + 4

# Print the result
print(result)
