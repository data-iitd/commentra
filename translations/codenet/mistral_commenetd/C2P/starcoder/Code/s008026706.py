
# Include the standard input/output library

# Start of the main function
def main():
	a, b, x, y = 0, 0, 0, 0 # Declare four integer variables: a, b, x, and y

	a, b = map(int, input().split()) # Read two integers from the standard input and store them in variables a and b
	# The map() function is used to convert a list of items into a list of integers

	x = 2*a + 2*b # Multiply variables a and b by 2, and then add the results together and store the result in variable x

	y = a*b # Multiply variables a and b and store the result in variable y

	print(y, x, sep=" ") # Print the values of variables y and x to the standard output, separated by a space

	return 0 # Indicate that the main function has run successfully and terminate the program

# 