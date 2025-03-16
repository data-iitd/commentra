#include<iostream>  # Include the iostream library for input and output operations
#include<string>    # Include the string library for handling strings
using namespace std; # Use the standard namespace for simplifying the code

def main(): # The main function is the entry point of the program
	a, b = 0, 0 # Declare two integer variables 'a' and 'b'
	S = ''      # Declare a character variable 'S'

	# A while loop that runs indefinitely until the user enters '?' to exit
	while True:
		a, S, b = input().split() # Read an integer 'a', a character 'S', and an integer 'b' from the standard input

		# Perform arithmetic operations based on the operator 'S'
		if S == '+': print(int(a) + int(b)) # If 'S' is '+', print the sum of 'a' and 'b'
		if S == '-': print(int(a) - int(b)) # If 'S' is '-', print the difference of 'a' and 'b'
		if S == '*': print(int(a) * int(b)) # If 'S' is '*', print the product of 'a' and 'b'
		if S == '/': print(int(a) / int(b)) # If 'S' is '/', print the quotient of 'a' and 'b'
		if S == '?': break # If 'S' is '?', break out of the loop

# 