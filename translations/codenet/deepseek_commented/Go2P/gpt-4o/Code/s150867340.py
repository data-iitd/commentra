# Importing the sys module for reading input
import sys

# Reading two integers from the standard input
a, b = map(int, sys.stdin.read().split())

# Calculating the product and checking if it's even
if (product := a * b) % 2 == 0:
    print("Even")  # Printing "Even" if the product is even
else:
    print("Odd")   # Printing "Odd" if the product is odd

# <END-OF-CODE>
