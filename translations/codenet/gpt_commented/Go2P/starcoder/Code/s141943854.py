# Import the 'bufio' module to read input from stdin.
import bufio

# Import the 'fmt' module to print output to stdout.
import fmt

# Import the 'log' module to log any errors encountered.
import log

# Import the 'os' module to access environment variables.
import os

# Import the'strconv' module to convert strings to integers.
import strconv

# Define a function to check for errors.
def check(e):
	if e!= None:
		log.fatal("error: %v", e)

# Define a function to handle different cases based on the input value.
def main():
	# Create a new scanner to read input from stdin.
	stdin = bufio.newscanner(os.stdin)
	
	# Read the first line of input.
	stdin.scan()
	sage = stdin.text() # Store the input in the variable'sage'.

	# Use a switch statement to handle different cases based on the input value.
	if sage == "1":
		# If the input is "1", print "Hello World".
		fmt.println("Hello World")
	elif sage == "2":
		# If the input is "2", initialize a variable to hold the sum of two numbers.
		sum = 0
		# Loop to read two numbers from input.
		for i in range(0, 2):
			stdin.scan() # Read the next line of input.
			num, err = strconv.atoi(stdin.text()) # Convert the input string to an integer.
			check(err) # Check for any conversion errors.
			sum += num # Add the number to the sum.
		# Print the total sum of the two numbers.
		fmt.println(sum)

# Call the main function.
main()

# 