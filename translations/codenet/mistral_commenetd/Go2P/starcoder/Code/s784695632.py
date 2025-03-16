
# Import the "sys" package for reading from the standard input.
import sys

# Import the "math" package for mathematical functions.
import math

# Define the function "main" as the entry point of our program.
def main():
	# Read the values of variables "x" and "y" from the standard input.
	x, y = map(int, sys.stdin.readline().split())

	# Print the result of the expression "x + y/2" to the standard output.
	print(x + y/2)

# End of code.

