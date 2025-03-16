
import math
import sys

# Function to read a line from standard input
def nextLine():
	# Read a line from standard input and return it as a string
	return sys.stdin.readline()

# Function to read an integer from standard input
def nextInt():
	# Read a line from standard input and convert it to an integer
	return int(nextLine())

# Function to find the minimum of two integers
def min(i, j):
	# Return the smaller of the two integers
	if i > j:
		return j
	return i

# Function to find the minimum number of digits in a divisor of n
def checkDivisibility():
	rt = int(math.sqrt(float(n)))
	for i in range(1, rt+1):
		if n%i == 0:
			# Calculate the number of digits in the divisor
			b = n / i
			ndigit = 0
			while b > 0:
				b /= 10
				ndigit += 1
			# Update minimum factor if a divisor with fewer digits is found
			minf = min(minf, ndigit)

# Initialize variables and call the checkDivisibility function
def main():
	# Read an integer from standard input and initialize n variable
	n = nextInt()

	# Initialize minimum factor with a large value
	minf = 100

	# Call the checkDivisibility function to find the minimum number of digits in a divisor of n
	checkDivisibility()

	# Print the result
	print(minf)

# Check if this program was run directly
if __name__ == "__main__":
	# Run the main function
	main()

# 