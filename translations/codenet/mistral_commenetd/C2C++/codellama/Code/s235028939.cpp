#include <iostream> // Include the standard input/output library

int main() // The entry point of the program
{
	// Declare two integer variables n and m
	int n, m;

	// Use the cin function to read two integers from the standard input and store them in n and m variables
	cin >> n >> m;

	// Calculate the product of (n - 1) and (m - 1) and store the result in the variable result
	int result = (n - 1) * (m - 1);

	// Use the cout function to print the result to the standard output
	cout << result << endl;

	// Flush the output buffer to ensure that all the data is written to the standard output before the program terminates
	cout.flush();

	// Indicate that the program has run successfully and terminate it
	return 0;
}

