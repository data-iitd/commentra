import math

# Read the values of n and d from the standard input.
n, d = map(int, input().split())

# Calculate the value of 'a' which is used in the subsequent calculations.
a = d * 2 + 1

# Output the ceiling of the division of n by 'a' to the standard output.
print(math.ceil(n / a))
