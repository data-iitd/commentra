# Include the input-output stream library
# Include the algorithm library (not used in this code)
# Include the cmath library (not used in this code)

# Define 'll' as an alias for 'long long' for convenience

# Read four integer values from standard input
a, b, c, d = map(int, input().split())

# Calculate the product of the differences between the first two and the last two integers
# This represents the area of a rectangle defined by the points (a, b) and (c, d)
print((a - c) * (b - d))

# 