# Importing the sys module for standard input
import sys

# Read two integers from standard input
a, b = map(int, sys.stdin.readline().split())

# Calculate and print the product of a and b,
# and also print the perimeter of a rectangle with sides a and b
print(a * b, (a + b) * 2)

# <END-OF-CODE>
