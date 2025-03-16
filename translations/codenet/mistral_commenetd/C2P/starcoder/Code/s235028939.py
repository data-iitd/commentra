# Include the standard input/output library
import sys

# The entry point of the program
if __name__ == '__main__':
	# Read two integers from the standard input
	n, m = map(int, sys.stdin.readline().split())

	# Calculate the product of (n - 1) and (m - 1)
	result = (n - 1) * (m - 1)

	# Print the result to the standard output
	print(result)

# 