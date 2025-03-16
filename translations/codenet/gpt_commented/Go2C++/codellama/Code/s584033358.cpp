#include <iostream>

int main() {
	// Declare two integer variables n and k
	int n, k;
	
	// Read two integers from standard input
	// n represents the total number of items, and k represents a threshold value
	std::cin >> n >> k;

	// Check if k is less than or equal to half of n (rounded up)
	if (k <= (n+n%2)/2) {
		// If the condition is true, print "YES"
		std::cout << "YES" << std::endl;
	} else {
		// If the condition is false, print "NO"
		std::cout << "NO" << std::endl;
	}

	return 0;
}

