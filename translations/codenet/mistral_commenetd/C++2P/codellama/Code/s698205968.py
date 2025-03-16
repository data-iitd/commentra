#include <iostream> // Include the iostream library for input/output operations

using namespace std; // Use the standard namespace for easier access to iostream functions

int main() { // Beginning of the main function
	int m, f, r; // Declare variables m, f, and r to store user input

	while (cin >> m >> f >> r) { // Start of the while loop
		# This loop continues as long as the user inputs valid integers (m, f, and r)
		# and at least one of them is not -1

		if (m == -1 or f == -1): # Check if m or f is -1
			print("F") # If so, print "F" and move on to the next input
			continue

		if (m + f >= 80): # Check if the sum of m and f is greater than or equal to 80
			print("A") # If so, print "A" and move on to the next input
			continue

		if (m + f >= 65): # Check if the sum of m and f is greater than or equal to 65
			print("B") # If so, print "B" and move on to the next input
			continue

		if (m + f >= 50 or r >= 50): # Check if the sum of m and f is greater than or equal to 50
									 # or if r is greater than or equal to 50
			print("C") # If so, print "C" and move on to the next input
			continue

		if (m + f >= 30): # Check if the sum of m and f is greater than or equal to 30
			print("D") # If so, print "D" and move on to the next input
			continue

		print("F") # If none of the above conditions are met, print "F" and move on to the next input
		print() # Print a newline character to start the next input on a new line
	}

	return 0; # End of the main function, return 0 to indicate successful execution
}

