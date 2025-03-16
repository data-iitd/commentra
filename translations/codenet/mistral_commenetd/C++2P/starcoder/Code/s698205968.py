# Include the iostream library for input/output operations

# Use the standard namespace for easier access to iostream functions

# Beginning of the main function
def main():
	# Declare variables m, f, and r to store user input
	m = 0
	f = 0
	r = 0

	# Start of the while loop
	while True:
		# The loop continues as long as the user inputs valid integers (m, f, and r)
		# and at least one of them is not -1

		# Check if m or f is -1
		if m == -1 or f == -1:
			# If so, print "F" and move on to the next input
			print("F")
			continue

		# Check if the sum of m and f is greater than or equal to 80
		if m + f >= 80:
			# If so, print "A" and move on to the next input
			print("A")
			continue

		# Check if the sum of m and f is greater than or equal to 65
		if m + f >= 65:
			# If so, print "B" and move on to the next input
			print("B")
			continue

		# Check if the sum of m and f is greater than or equal to 50 or if r is greater than or equal to 50
		if m + f >= 50 or r >= 50:
			# If so, print "C" and move on to the next input
			print("C")
			continue

		# Check if the sum of m and f is greater than or equal to 30
		if m + f >= 30:
			# If so, print "D" and move on to the next input
			print("D")
			continue

		# If none of the above conditions are met, print "F" and move on to the next input
		print("F")
		# Print a newline character to start the next input on a new line

# End of the main function, return 0 to indicate successful execution
if __name__ == "__main__":
	main()

