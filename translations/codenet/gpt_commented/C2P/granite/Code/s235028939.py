
import sys

# Read two integers from standard input
# n represents the number of rows, and m represents the number of columns
n, m = map(int, sys.stdin.readline().split())

# Calculate the product of (n - 1) and (m - 1)
# This represents the number of internal edges in a grid of n by m cells
result = (n - 1) * (m - 1)

# Print the result to standard output
print(result)

# Flush the output buffer to ensure all output is printed
sys.stdout.flush()

# End of code
