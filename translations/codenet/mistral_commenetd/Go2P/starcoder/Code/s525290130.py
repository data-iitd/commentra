# Importing necessary packages
import sys
import math

# Function to read next integer from the standard input
def nextInt(sc):
	sc.readline() # Scan the next token
	t = int(sc.readline()) # Convert the token to integer
	return t # Return the integer

# Function to reverse the subarray of array 'a' from index 'b' to 'e' (both inclusive)
def reva(b):
	# Reverse the subarray using a simple method of swapping elements
	for i in range(0, len(b)/2):
		b[i], b[len(b)-1-i] = b[len(b)-1-i], b[i]

# Main function
def main():
	# Initialize a scanner to read input from standard input
	sc = sys.stdin

	# Read the number of elements in the array 'a'
	n = nextInt(sc)
	# Allocate memory for the array 'a' of size 'n'
	a = [0] * n

	# Read 'n' integers from the standard input and store them in the array 'a'
	for i in range(0, n):
		a[i] = nextInt(sc)

	# Read the number of queries 'q'
	q = nextInt(sc)

	# Process each query by reversing the subarray of 'a'
	for i in range(0, q):
		# Read the starting and ending indices of the subarray to be reversed
		b = nextInt(sc)
		e = nextInt(sc)

		# Reverse the subarray 'a[b:e]'
		reva(a[b:e])

	# Write the reversed array 'a' to the standard output
	wtr = sys.stdout
	for i in range(0, n):
		# Write each element of the array 'a' to the standard output with a space in between (except for the first element)
		if i > 0:
			wtr.write(" ")
		wtr.write(str(a[i]))

	# Flush the buffer to write the output to the standard output
	wtr.write("\n")
	wtr.flush()

# End of the code

