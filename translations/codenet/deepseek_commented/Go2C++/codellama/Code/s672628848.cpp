#include <iostream>
#include <vector>

int main() {
	// Declare five integer variables to hold input values
	int a, b, c, d, e;

	// Read five integers from the standard input and assign them to the variables
	std::cin >> a >> b >> c >> d >> e;

	// Create a vector containing the five integers
	std::vector<int> al = {a, b, c, d, e};

	// Iterate over the vector using a for loop with the range keyword
	for (int n = 0; n < al.size(); n++) {
		// Check if the current element is equal to 0
		if (al[n] == 0) {
			// Print the position of the element (1-based index) and break out of the loop
			std::cout << n + 1 << std::endl;
			break;
		}
	}

	// End of code
	return 0;
}