#include <stdio.h>  # Include the standard input/output library

def main():  # Define the main function, the entry point of the program
	a, b, c = input("Enter three integers: ").split()  # Read three integers from the user and store them in variables a, b, and c
	
	if a < b and b < c:  # Check if a is less than b and b is less than c
		print("Yes")  # Print "Yes" if true
	else:
		print("No")  # Print "No" if the condition is not met
	
	return 0  # Return 0 to indicate successful execution

