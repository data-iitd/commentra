
import sys

# Read two integers A and B from the input
A, B = map(int, sys.stdin.readline().split())

# Initialize variables to hold the remainder and the result
amari = 0
result = 0

# Calculate the initial result based on the formula (B - 1) / (A - 1)
result = (B - 1) // (A - 1)

# Calculate the remainder when (B - 1) is divided by (A - 1)
amari = (B - 1) % (A - 1)

# If there is a remainder, increment the result by 1
if amari!= 0:
    result += 1

# Print the final result to the console
print(result)

# End of code