
# Importing the required packages
import sys

# Reading the first integer input
a = int(sys.stdin.readline().strip())

# Reading the second integer input
b = int(sys.stdin.readline().strip())

# Checking if the product of a and b is odd or even and printing the result
if a*b % 2 != 0:
    print("Odd")
else:
    print("Even")

