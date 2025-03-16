#include <iostream>
using namespace std;

// Function to solve the problem based on the given parameters a, b, and c
int solve(int a, int b, int c) {
	int temp_;
	
	// Check if c is equal to the sum of a and b
	if (c == a + b) {
		// If true, calculate the result as b + c
		temp_ = b + c;
	} else if (c - 1 > a + b) {
		// If c-1 is greater than the sum of a and b, calculate the difference
		int temp = (c - 1) - (a + b);
		// Adjust the result based on the calculated difference
		temp_ = b + c - temp;
	} else {
		// If neither condition is met, simply return b + c
		temp_ = b + c;
	}
	 
	// Return the calculated result
	return temp_;
}

int main() {
	int a, b, c;
	
	// Read three integers from standard input
	cin >> a >> b >> c;

	// Call the solve function with the input values and store the result
	int ans = solve(a, b, c);
	
	// Print the result to standard output
	cout << ans << endl;
}

