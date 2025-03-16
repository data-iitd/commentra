
#include <iostream>

int main() {
	// Declare three integer variables to hold the input values
	int a, b, c;
	
	// Read three integers from standard input
	std::cin >> a >> b >> c;
	
	// Check if the integers are in strictly increasing order
	if (a < b && b < c) {
		// If they are in increasing order, print "Yes"
		std::cout << "Yes" << std::endl;
	} else {
		// If they are not in increasing order, print "No"
		std::cout << "No" << std::endl;
	}
	
	// End of the main function
	return 0;
}
