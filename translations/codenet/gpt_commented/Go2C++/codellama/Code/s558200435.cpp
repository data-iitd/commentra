#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	// Read the number of elements from standard input
	int n;
	cin >> n;

	// Initialize a vector to hold the input integers
	vector<int> a(n);
	// Read n integers from standard input into the vector a
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	// Initialize a vector b to hold the longest increasing subsequence
	vector<int> b;
	// Iterate over each value in the input vector a
	for (int v : a) {
		// Use binary search to find the index where v can be placed in b
		int x = lower_bound(b.begin(), b.end(), v) - b.begin();
		// If v is greater than all elements in b, append it to b
		if (x == b.size()) {
			b.push_back(v);
		} else {
			// Otherwise, replace the existing value at index x with v
			b[x] = v;
		}
	}

	// Output the length of the longest increasing subsequence
	cout << b.size() << endl;

	return 0;
}

