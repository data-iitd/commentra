
#include <iostream>

int main() {
	// Declare two integer variables K and X
	int K, X;
	
	// Read two integers from the standard input and assign them to K and X
	std::cin >> K >> X;
	
	// Check if the product of 500 and K is greater than or equal to X
	if (500*K >= X) {
		// If true, print "Yes"
		std::cout << "Yes" << std::endl;
	} else {
		// If false, print "No"
		std::cout << "No" << std::endl;
	}
	
	return 0;
}
