// Importing necessary headers
#include <iostream>
#include <vector>

// Function to read next integer from the standard input
int nextInt(std::vector<int> &a) {
	// Read the next token from the standard input
	int t;
	std::cin >> t;
	// Add the token to the vector 'a'
	a.push_back(t);
	// Return the token
	return t;
}

// Function to reverse the subarray of array 'a' from index 'b' to 'e' (both inclusive)
void reva(std::vector<int> &a, int b, int e) {
	// Reverse the subarray using a simple method of swapping elements
	for (int i = 0; i < (e - b + 1) / 2; i++) {
		a[b + i] ^= a[e - i];
		a[e - i] ^= a[b + i];
		a[b + i] ^= a[e - i];
	}
}

// Main function
int main() {
	// Initialize a vector to store the input
	std::vector<int> a;

	// Read the number of elements in the array 'a'
	int n = nextInt(a);
	// Allocate memory for the array 'a' of size 'n'
	a.resize(n);

	// Read 'n' integers from the standard input and store them in the array 'a'
	for (int i = 0; i < n; i++) {
		a[i] = nextInt(a);
	}

	// Read the number of queries 'q'
	int q = nextInt(a);

	// Process each query by reversing the subarray of 'a'
	for (int i = 0; i < q; i++) {
		// Read the starting and ending indices of the subarray to be reversed
		int b = nextInt(a);
		int e = nextInt(a);

		// Reverse the subarray 'a[b:e]'
		reva(a, b, e);
	}

	// Write the reversed array 'a' to the standard output
	for (int i = 0; i < n; i++) {
		// Write each element of the array 'a' to the standard output with a space in between (except for the first element)
		if (i > 0) {
			std::cout << " ";
		}
		std::cout << a[i];
	}

	// End of the code
	return 0;
}


