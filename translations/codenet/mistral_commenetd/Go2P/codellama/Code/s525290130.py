// Importing necessary packages
import sys

// Function to read next integer from the standard input
def nextInt(sc):
	sc.scan() # Scan the next token
	t = int(sc.text()) # Convert the token to integer
	return t # Return the integer

# Function to reverse the subarray of array 'a' from index 'b' to 'e' (both inclusive)
def reva(a, b, e):
	# Reverse the subarray using a simple method of swapping elements
	for i in range(b, e+1):
		a[i], a[e-i+b] = a[e-i+b], a[i]

# Main function
def main():
	# Initialize a scanner to read input from standard input
	sc = sys.stdin

	# Read the number of elements in the array 'a'
	n = nextInt(sc)
	# Allocate memory for the array 'a' of size 'n'
	a = [0] * n

	# Read 'n' integers from the standard input and store them in the array 'a'
	for i in range(n):
		a[i] = nextInt(sc)

	# Read the number of queries 'q'
	q = nextInt(sc)

	# Process each query by reversing the subarray of 'a'
	for i in range(q):
		# Read the starting and ending indices of the subarray to be reversed
		b = nextInt(sc)
		e = nextInt(sc)

		# Reverse the subarray 'a[b:e]'
		reva(a, b, e)

	# Write the reversed array 'a' to the standard output
	for i in range(n):
		# Write each element of the array 'a' to the standard output with a space in between (except for the first element)
		if i > 0:
			print(" ", end="")
		print(a[i], end="")

	# End of the code


Translate the above Python code to C++ and end with comment "