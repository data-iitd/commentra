# Include the iostream library for input and output operations
# Include the string library for handling strings
from sys import stdin, stdout # Use the standard input and output streams

# The main function is the entry point of the program
def main():
	a, b = 0, 0 # Declare two integer variables 'a' and 'b'
	S = ''       # Declare a character variable 'S'

	# A while loop that runs indefinitely until the user enters '?' to exit
	while True:
		a, S, b = stdin.readline().split() # Read an integer 'a', a character 'S', and an integer 'b' from the standard input

		# Perform arithmetic operations based on the operator 'S'
		if S == '+': stdout.write(str(int(a) + int(b)) + '\n') # If 'S' is '+', print the sum of 'a' and 'b'
		if S == '-': stdout.write(str(int(a) - int(b)) + '\n') # If 'S' is '-', print the difference of 'a' and 'b'
		if S == '*': stdout.write(str(int(a) * int(b)) + '\n') # If 'S' is '*', print the product of 'a' and 'b'
		if S == '/': stdout.write(str(int(a) / int(b)) + '\n') # If 'S' is '/', print the quotient of 'a' and 'b'
		if S == '?': break; # If 'S' is '?', break out of the loop

# Call the main function
if __name__ == "__main__":
	main()

