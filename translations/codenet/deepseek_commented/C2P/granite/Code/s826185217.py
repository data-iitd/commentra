
#include <stdio.h> // Step 1: Include the standard input/output library to use printf and scanf functions.

int main(void){ // Step 2: Define the main function where the execution of the program begins.
	a, b, c, d = map(int, input().split()) # Step 3: Use input function to read four integers from the user and store them in variables a, b, c, and d.

	if a + b > c + d: # Step 4: Compare the sum of a and b with the sum of c and d.
		print("Left") # Step 5: If the sum of a and b is greater than the sum of c and d, print "Left".
	elif a + b < c + d: # Step 6: If the sum of a and b is less than the sum of c and d, print "Right".
		print("Right")
	else: # Step 7: If the sums are equal, print "Balanced".
		print("Balanced")

	return 0 # Step 8: Return 0 to indicate successful execution of the program.
}

