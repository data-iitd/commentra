import math

def main():
	# Read an integer input from the user
	n = int(input())
	
	# Calculate the integer square root of n
	rt = int(math.sqrt(n))
	
	# Initialize a variable to keep track of the minimum number of digits found
	minf = 100
	
	# Loop through all integers from 1 to the square root of n
	for i in range(1, rt+1):
		# Check if i is a divisor of n
		if n%i == 0:
			# Calculate the corresponding divisor b
			b = n / i
			
			# Initialize a counter for the number of digits in b
			ndigit = 0
			
			# Count the number of digits in b
			while b > 0:
				b /= 10
				ndigit += 1
			
			# Update minf with the minimum number of digits found
			minf = min(minf, ndigit)
		# End if
	# End for
	
	# Print the minimum number of digits found among the divisors
	print(minf)
# End main

# Function to return the minimum of two integers
def min(i, j):
	if i > j:
		return j
	return i
# End min

# Define a constant for the buffer size
size = 1000000

# Create a buffered reader with the specified size
reader = sys.stdin

# Function to read a full line of input
def nextLine():
	buffer = ""
	while True:
		c = reader.read(1)
		if c == '\n' or c == '':
			break
		buffer += c
	return buffer
# End nextLine

# Function to read a line of input and split it into a string array
def nextStringArray():
	return nextLine().split(" ")
# End nextStringArray

# Function to read an integer from input
def nextInt():
	return int(nextLine())
# End nextInt

# Function to read a line of input and convert it into an array of integers
def nextIntArray():
	return [int(x) for x in nextLine().split(" ")]
# End nextIntArray

# 