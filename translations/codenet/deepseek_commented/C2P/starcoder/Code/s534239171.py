# Include the standard input/output library
import sys

# Declare integer variables
a, b, n = 0, 0, 0

# Read input values
a, b = map(int, sys.stdin.readline().split())

# Calculate the average
n = (a + b) / 2

# Print the result
print(n)

# Return from main function
return 0

