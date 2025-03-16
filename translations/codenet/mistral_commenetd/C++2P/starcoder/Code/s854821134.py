
# Include the iostream library for input/output operations
# Include the algorithm library for standard algorithms
# Include the queue library for queue data structure
# Include the string library for string manipulation
# Include the vector library for dynamic arrays
from sys import stdin, stdout # Import the standard input/output library for C++

# Define a constant integer INF for use later
INF = 200000005

# Begin the main function
def main():
	# Declare two integer variables a and b
	a, b = map(int, stdin.readline().split())

	# Check if both a and b are less than or equal to 8
	if a <= 8 and b <= 8:
		# If the condition is true, print "Yay!" to the standard output using cout
		stdout.write("Yay!\n")
	else:
		# If the condition is false, print ":(" to the standard output using cout
		stdout.write(":(\n")

# Call the main function
if __name__ == "__main__":
	main()

# End with comment "