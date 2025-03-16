
# Include necessary libraries for input/output operations, mathematical calculations, and data structures.
import math

n, d = map(int, input().split())

# Read the values of n and d from the standard input.
a = d * 2 + 1
# Calculate the value of 'a' which is used in the subsequent calculations.
print(math.ceil(n / a))
# Output the ceiling of the division of n by 'a' to the standard output.

