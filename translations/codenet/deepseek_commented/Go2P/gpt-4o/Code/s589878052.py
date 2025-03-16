# Importing the sys module for reading input
import sys

# Reading three integers from the standard input
a, b, h = map(int, sys.stdin.read().split())

# Calculating and printing the area of a trapezoid
print((a + b) * h // 2)  # Using integer division

# <END-OF-CODE>
