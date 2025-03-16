
// Import the "iostream" library for input and output
#include <iostream>

int main() {
	// Declare two integer variables, A and B, and read their values from the standard input
	int A, B;
	std::cin >> A >> B;

	// Declare an integer variable, ans, to store the result of our calculation
	int ans;

	// Use an if statement to check the value of A
	if (A >= 6 && A <= 12) {
		// If A is between 6 and 12 (inclusive), calculate the answer as the integer division of B by 2
		ans = B / 2;
	} else if (A > 12) {
		// If A is greater than 12, assign the value of B directly to the ans variable
		ans = B;
	}

	// Print the value of ans
	std::cout << ans << std::endl;

	// End of code
	return 0;
}

