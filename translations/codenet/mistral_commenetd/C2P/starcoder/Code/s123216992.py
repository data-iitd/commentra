
# Include the standard input/output library

# Function to swap two integers passed by reference
def swap(a, b):
	# Declare a temporary variable to store the value of 'a'
	tmp = a
	# Assign the value of 'b' to 'a'
	a = b
	# Assign the value of 'a' to 'b'
	b = tmp
	# Assign the value of the temporary variable 'tmp' back to 'b'

# Infinite loop to read two integers from the user
while True:
	# Read two integers from the user and store them in 'a' and 'b' respectively
	a, b = map(int, input().split())
	# If both 'a' and 'b' are zero, break out of the loop
	if a == 0 and b == 0:
		break
	# If 'b' is less than 'a', swap their values
	if b < a:
		swap(a, b)
	# Print the swapped values of 'a' and 'b'
	print(a, b)

# Return 0 to indicate successful execution of the program
0

