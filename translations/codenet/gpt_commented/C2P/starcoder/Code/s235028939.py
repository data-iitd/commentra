# <START-OF-CODE>

# Declare two integer variables n and m
n = 0
m = 0

# Read two integers from standard input
# n represents the number of rows, and m represents the number of columns
n, m = map(int, input().split())

# Calculate the product of (n - 1) and (m - 1)
# This represents the number of internal edges in a grid of n by m cells
print((n - 1) * (m - 1))

# 