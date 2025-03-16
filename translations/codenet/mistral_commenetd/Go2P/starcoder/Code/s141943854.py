
# Function to check for errors and exit with error message if any
def check(e):
	if e!= None:
		log.fatal("error: %v", e)

# Main function
def main():
	# Initialize a scanner to read from standard input
	stdin = bufio.NewScanner(os.Stdin)

	# Read the first line from standard input
	stdin.Scan()

	# Store the first line in a variable named'sage'
	sage = stdin.Text()

	# Use a switch statement to determine the action based on the first line read
	if sage == "1":
		# Print "Hello World" if the first line is "1"
		print("Hello World")
	elif sage == "2":
		# Initialize a variable named'sum' to store the sum of two numbers
		sum = 0

		# Use a for loop to read and sum two numbers
		for i in range(2):
			# Read the next line from standard input
			stdin.Scan()

			# Convert the next line to an integer and store it in a variable named 'num'
			num = int(stdin.Text())

			# Add the current number to the sum
			sum += num

		# Print the sum of the two numbers
		print(sum)

# End of code

