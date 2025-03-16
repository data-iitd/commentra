#include <iostream>

// Declare variables
int n;
unsigned long long int m;

int main() {
	// Initialize variables
	std::cin >> n;
	// Assign the value of n to m for later use
	m = n;
	// Decrement n by 1
	n--;

	// Loop through n-1 times to calculate the factorial
	for(; n > 1; n--) {
		// Multiply m with current value of n
		m *= n;
	}

	// Print the result
	std::cout << m << std::endl;
	// Return 0 to indicate successful execution
	return 0;
}

