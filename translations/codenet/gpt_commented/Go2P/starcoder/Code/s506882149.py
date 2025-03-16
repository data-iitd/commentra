# Import the sys module for reading input from the command line
import sys

# Define the comp function
def comp(x, a):
	# Check if x is less than a
	if x < a:
		return 0 # Return 0 if the condition is true
	return 10 # Return 10 if x is not less than a

# Read input values for x and a from the command line
x = int(sys.argv[1])
a = int(sys.argv[2])

# Call the comp function with x and a, and print the result
print(comp(x, a))

