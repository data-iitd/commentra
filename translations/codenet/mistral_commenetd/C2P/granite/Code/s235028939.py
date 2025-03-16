
import sys # Import the standard input/output library

def main(): # The entry point of the program
	# Declare two integer variables n and m
	n, m = map(int, sys.stdin.readline().split())

	# Calculate the product of (n - 1) and (m - 1) and store the result in the variable result
	result = (n - 1) * (m - 1)

	# Use the print function to print the result to the standard output
	print(result)

	# Flush the output buffer to ensure that all the data is written to the standard output before the program terminates
	sys.stdout.flush()

	# Indicate that the program has run successfully and terminate it
	return 0

if __name__ == "__main__":
	main()
