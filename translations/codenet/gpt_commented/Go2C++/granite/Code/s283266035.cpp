
#include <iostream>

int main() {
	// Declare a variable to hold the input number
	int n;
	
	// Read an integer input from the user
	std::cin >> n;
	
	// Initialize a variable to store the result
	int ans = 0;
	
	// Loop through possible divisors from 1 to the square root of n
	for (int i = 1; i*i < n; i++) {
		// Check if i is a divisor of n and if the corresponding divisor (n/i) satisfies the condition
		if (n%i == 0 && n%(n/i-1) == i) {
			// If the condition is met, add (n/i - 1) to the answer
			ans += n/i - 1;
		}
	}
	
	// Print the final result
	std::cout << ans << std::endl;
	
	// End of code
	return 0;
}
