
#include <bits/stdc++.h>

using namespace std;

int main() {
	// Read the number of elements in the array 'a'
	int n;
	cin >> n;

	// Create a vector 'a' of length 'n' to store the input elements
	vector<int> a(n);

	// Read 'n' elements from the standard input and store them in vector 'a'
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	// Create an empty vector 'b' to store the unique elements
	vector<int> b;

	// Iterate through each element 'v' in vector 'a'
	for (int v : a) {
		// Use 'lower_bound' function to find the index 'x' where 'v' should be inserted in vector 'b'
		auto x = lower_bound(b.begin(), b.end(), v);

		// If 'x' is equal to the end of vector 'b', it means 'v' is not present in the vector, so append it
		if (x == b.end()) {
			b.push_back(v);
		} else {
			// Otherwise, replace the element at index 'x' in vector 'b' with 'v'
			*x = v;
		}
	}

	// Print the length of vector 'b' as the output
	cout << b.size() << endl;

	// End of the code
}

