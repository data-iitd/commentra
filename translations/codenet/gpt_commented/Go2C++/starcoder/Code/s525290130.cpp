#include <bits/stdc++.h>

using namespace std;

// reva reverses a slice of integers in place.
void reva(vector<int> &b) {
	for (int i = 0; i < b.size()/2; i++) { // Iterate only halfway through the slice
		// Swap the elements at positions i and b.size()-1-i
		int temp = b[i];
		b[i] = b[b.size()-1-i];
		b[b.size()-1-i] = temp;
	}
}

int main() {
	// Read the number of elements in the array
	int n;
	cin >> n;
	vector<int> a(n); // Initialize a vector of integers with length n

	// Populate the vector with integers from input
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	// Read the number of queries
	int q;
	cin >> q;
	// Process each query
	for (int i = 0; i < q; i++) {
		int b, e;
		cin >> b >> e;
		reva(a.begin()+b, a.begin()+e); // Reverse the vector from index b to e
	}

	// Write the modified array to output
	for (int i = 0; i < n; i++) {
		if (i > 0) {
			cout << " "; // Print a space before each element except the first
		}
		cout << a[i]; // Print the current element
	}
	cout << endl; // Print a newline after the output
}

