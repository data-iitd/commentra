# The main function is the entry point of the program.
def main():
	# Initialize a Scanner object named sc.
	sc = NewScanner()

	# Read two integers A and B from the standard input.
	A, B = sc.NextInt(), sc.NextInt()

	# Calculate the maximum value of A+B, A-B, and A*B using the max function.
	mx = max(A+B, A-B)
	mx = max(mx, A*B)

	# Print the maximum value.
	print(mx)

# 