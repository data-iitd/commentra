# Include the standard input/output library
import sys

# Read two integer values from the standard input and store them in a and b
a, b = map(int, sys.stdin.readline().split())

# Calculate the product of a and b, and store it in c
c = a * b

# Calculate the perimeter of a rectangle with sides a and b, and store it in d
d = 2 * a + 2 * b

# Print the values of c and d to the standard output
print(c, d)

# Return 0 to indicate successful execution
sys.exit(0)

