# Include the standard input/output library for input and output operations.
import sys

# Define the main function, the entry point of the program.
def main():
	n = int(input()) # Read an integer value for n from the standard input.
	k = int(input()) # Read an integer value for k from the standard input.
	x = n//k # Calculate the integer division of n by k and store the result in x.
	y = n%k # Calculate the remainder of the integer division of n by k and store the result in y.
	if y!= 0: # Check if the remainder y is not equal to 0.
		z = x+1-x # If y is not equal to 0, calculate z as x+1-x.
	else: # If y is equal to 0.
		z = x-x # Calculate z as x-x.
	print(z) # Print the value of z to the standard output.

# The entry point of the program.
if __name__ == "__main__":
	main() # Execute the main function.

