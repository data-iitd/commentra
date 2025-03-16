
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	// Initialize the variable 'n' to read the number of elements in the array 'a'
	int n;
	cin >> n;

	// Create a vector 'a' of length 'n' to store the input elements
	vector<int> a(n);

	// Read 'n' elements from the standard input and store them in vector 'a'
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	// Initialize an empty vector 'b' to store the unique elements
	vector<int> b;

	// Iterate through each element 'v' in vector 'a'
	for (int v : a) {
		// Use 'lower_bound' function to find the index 'x' where 'v' should be inserted in vector 'b'
		int x = lower_bound(b.begin(), b.end(), v) - b.begin();

		// If 'x' is equal to the length of vector 'b', it means 'v' is not present in the vector, so push it
		if (x == b.size()) {
			b.push_back(v);
		} else {
			// Otherwise, replace the element at index 'x' in vector 'b' with 'v'
			b[x] = v;
		}
	}

	// Print the length of vector 'b' as the output
	cout << b.size() << endl;

	// End of the code
}

