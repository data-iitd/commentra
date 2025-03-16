
#include<stdio.h>
# Include the standard input/output library

def swap(a , b):
	# Function to swap two integers passed by reference
	tmp = a
	# Declare a temporary variable to store the value of 'a'

	a = b
	# Assign the value of 'b' to 'a'

	b = tmp
	# Assign the value of the temporary variable 'tmp' back to 'b'

while(1):
	# Infinite loop to read two integers from the user

	a , b = input().split()
	# Read two integers from the user and store them in 'a' and 'b' respectively

	if (a == 0 and b == 0): break
	# If both 'a' and 'b' are zero, break out of the loop

	if (b < a): swap(a , b)
	# If 'b' is less than 'a', swap their values

	print(a , b)
	# Print the swapped values of 'a' and 'b'

# Return 0 to indicate successful execution of the program

return 0

