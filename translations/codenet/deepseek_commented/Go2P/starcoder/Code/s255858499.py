
# Importing the sys module for input operations
import sys

# Reading the first integer input
a = int(sys.stdin.readline())
# Reading the second integer input
b = int(sys.stdin.readline())

# Checking if the product of a and b is odd or even and printing the result
if a*b % 2!= 0:
	print("Odd")
else:
	print("Even")

