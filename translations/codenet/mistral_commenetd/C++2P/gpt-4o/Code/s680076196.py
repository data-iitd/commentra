# Import the sys module for input
import sys

# Read values of variables a, b, c, and d from standard input
a, b, c, d = map(int, sys.stdin.readline().split())

# Calculate the difference between a and c, and the difference between b and d
difference_ab = a - c
difference_cd = b - d

# Multiply the differences and print the result to standard output
print(difference_ab * difference_cd)

# <END-OF-CODE>
