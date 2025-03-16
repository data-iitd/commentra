// Package declaration
#include <iostream>
using namespace std;

// Function definition for the main function
int main() {
	// Declaring variables r, D, and x of type int
	int r, D, x;

	// Reading input values for r, D, and x from the standard input
	cin >> r >> D >> x;

	// Comment for the for loop
	// Loop runs 10 times
	for (int i = 1; i <= 10; i++) {
		// Print the result of the current iteration
		cout << r * x - D << endl;

		// Update the value of x for the next iteration
		x = r * x - D;
	}

	return 0;
}

// End of the code
