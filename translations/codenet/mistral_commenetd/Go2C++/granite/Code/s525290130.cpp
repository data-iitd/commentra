
// Importing necessary packages
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to read next integer from the standard input
int nextInt() {
	int t;
	cin >> t;
	return t;
}

// Function to reverse the subarray of vector 'a' from index 'b' to 'e' (both inclusive)
void reva(vector<int>& a, int b, int e) {
	// Reverse the subarray using a simple method of swapping elements
	for (int i = b; i < (b + e) / 2; i++) {
		swap(a[i], a[e + b - 1 - i]);
	}
}

// Main function
int main() {
	// Read the number of elements in the vector 'a'
	int n = nextInt();
	// Allocate memory for the vector 'a' of size 'n'
	vector<int> a(n);

	// Read 'n' integers from the standard input and store them in the vector 'a'
	for (int i = 0; i < n; i++) {
		a[i] = nextInt();
	}

	// Read the number of queries 'q'
	int q = nextInt();

	// Process each query by reversing the subarray of 'a'
	for (int i = 0; i < q; i++) {
		// Read the starting and ending indices of the subarray to be reversed
		int b = nextInt();
		int e = nextInt();

		// Reverse the subarray 'a[b:e]'
		reva(a, b, e);
	}

	// Write the reversed vector 'a' to the standard output
	for (int i = 0; i < n; i++) {
		// Write each element of the vector 'a' to the standard output with a space in between (except for the first element)
		if (i > 0) {
			cout << " ";
		}
		cout << a[i];
	}

	// End of the code
	return 0;
}

