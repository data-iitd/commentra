#include <stdio.h>  # Include standard input/output library
#include <stdlib.h>  # Include standard library for memory allocation

def main():  # Beginning of the main function
	S = input()  # Read a string of six characters from the standard input and store it in the array 'S'
	for i in range(len(S)):  # Iterate through each character in the string 'S'
		if S[i] == 'A' and S[i + 1] == 'C':  # Check if the current character is 'A' and the next character is 'C'
			print("Yes")  # If so, print 'Yes' to the standard output
			return 0  # And exit the program
	print("No")  # If no pair of 'AC' is found, print 'No' to the standard output
	return 0  # End of the main function

# 