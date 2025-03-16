# Include the standard input/output library
import sys

# Define the main function with no arguments
def main():
	# Declare four integer variables
	a = 0
	b = 0
	c = 0
	d = 0

	# Read four integers from the standard input and store them in the variables a, b, c, and d
	a, b, c, d = map(int, sys.stdin.readline().split())

	# Check if the sum of a and b is greater than the sum of c and d
	if (a + b > c + d):
		# If true, print "Left" to the standard output
		print("Left")
	elif (a + b < c + d):
		# If true, print "Right" to the standard output
		print("Right")
	else:
		# If neither of the above conditions is true
		print("Balanced")

# Indicate that the program has run successfully
if __name__ == "__main__":
	main()

