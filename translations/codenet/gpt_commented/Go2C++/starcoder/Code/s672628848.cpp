#include <iostream>

int main() {
	// Declare five integer variables to hold input values
	int a, b, c, d, e;

	// Read five integers from standard input
	std::cin >> a >> b >> c >> d >> e;

	// Create a slice containing the input integers
	std::vector<int> al = {a, b, c, d, e};

	// Iterate over the slice to find the first occurrence of zero
	for (int n = 0; n < al.size(); n++) {
		// Check if the current element is zero
		if (al[n] == 0) {
			// Print the index (1-based) of the first zero found and exit the loop
			std::cout << n + 1 << std::endl;
			break;
		}
	}
}

