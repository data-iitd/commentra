# Python 3 program to count the number of complete
# x-blocks in a given range

# Function to count the number of complete x-blocks
# in a given range
def countCompleteXBlocks(a, b, x):

	# Calculate the difference between the number of complete x-blocks in b and a
	s = (b//x - a//x)

	# If a is a multiple of x, then the last x-block in a is complete, so add 1 to the result
	if(a%x == 0):
		s += 1

	# Return the result
	return s

# Driver Code
if __name__ == '__main__':

	# Declare variables
	a, b, x = 0, 0, 0

	# Read input values from standard input
	a, b, x = map(int, input().split())

	# Calculate the number of complete x-blocks in the given range
	s = countCompleteXBlocks(a, b, x)

	# Print the result to standard output
	print(s)

