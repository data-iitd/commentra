#include<iostream>

using namespace std; // This line includes the standard input-output library and makes the "std" namespace accessible without having to write "std::" before each standard library function or variable.

int main() { // The main function is the entry point of the program. It initializes the program and calls the function main().
	int a, b, c; // Declare three integer variables named a, b, and c.
	cin >> a >> b >> c; // Read three integers from the standard input and assign them to the variables a, b, and c.
	// The following if statement checks if any of the following conditions are true:
	// (a + b) == c // If the sum of a and b is equal to c
	// (b + c) == a // If the sum of b and c is equal to a
	// (a + c) == b // If the sum of a and c is equal to b
	if ((a + b == c) || (b + c == a) || (a + c == b)): // If any of the above conditions are true, the following code is executed.
		print("Yes"); // Output the string "Yes" to the standard output.
		print("\n"); // Output a newline character to move the cursor to the next line.
	else: // If none of the above conditions are true, the following code is executed.
		print("No"); // Output the string "No" to the standard output.
		print("\n"); // Output a newline character to move the cursor to the next line.
}

