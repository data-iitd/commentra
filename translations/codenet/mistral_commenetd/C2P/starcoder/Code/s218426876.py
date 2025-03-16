
# Include string header file for string manipulation functions
# Include standard input/output library for input/output operations

# Function definition for main function
def main():
	i = 0 # Initialize integer variable 'i'
	sum = 0 # Initialize integer variable'sum' to zero
	flag = 0 # Initialize integer variable 'flag' to zero
	x = [0]*1002 # Initialize character array 'x' of size 1002

	# Read a string from standard input and store it in 'x' array
	print("Enter a string of digits separated by spaces or newline: ")
	x = input()

	while(x[0]!= '0'): # Continue the loop until the first character of the input string is '0'

		# Initialize sum to zero before processing each string
		sum = 0

		# Process each character in the string 'x'
		for i in range(0,1002):
			# Check if current character is end-of-string marker
			if(x[i] == 0):
				# If so, print the sum of digits in the previous string and exit the loop
				print("Sum of digits in previous string: ",sum)
				break
			else:
				# Otherwise, add the ASCII value of the character to the sum (subtracting 0x30 to convert ASCII to integer)
				sum += x[i] - 0x30

		# Initialize sum to zero for next iteration of the loop
		sum = 0

		# Read next string from standard input
		print("Enter a string of digits separated by spaces or newline: ")
		x = input()

	return 0 # Function returns 0 upon successful execution

# Call main function
if __name__ == "__main__":
	main()

