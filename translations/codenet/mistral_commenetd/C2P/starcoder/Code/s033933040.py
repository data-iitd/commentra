# Include the standard input/output library
import sys

# Declare variables
a = 0
b = 0
mawari = 0
menseki = 0

# Read input values for variables a and b from the user
a, b = map(int, sys.stdin.readline().split())
# Assign the variable mawari the sum of the squares of a and b
mawari = a * a + b * b
# Assign the variable menseki the product of a and b
menseki = a * b
# Print the values of menseki and mawari to the console
print(menseki, mawari)
# Return 0 to indicate successful program execution
sys.exit(0)

