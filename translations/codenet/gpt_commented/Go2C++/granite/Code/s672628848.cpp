
#include <iostream>
#include <vector>

int main() {
	// Declare five integer variables to hold input values
	int a, b, c, d, e;

	// Read five integers from standard input
	std::cin >> a >> b >> c >> d >> e;

	// Create a vector containing the input integers
	std::vector<int> al = {a, b, c, d, e};

	// Iterate over the vector to find the first occurrence of zero
	for (size_t n = 0; n < al.size(); n++) {
		// Check if the current element is zero
		if (al[n] == 0) {
			// Print the index (0-based) of the first zero found and exit the loop
			std::cout << n << std::endl;
			break;
		}
	}
}

