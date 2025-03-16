#include <bits/stdc++.h>

using namespace std;

// Initialize a new scanner to read input from standard input
std::cin.tie(0);
std::ios_base::sync_with_stdio(false);
std::istream::sync_with_stdio(false);
std::istream cin("input.txt");

// Declare a variable for the modulus value
int mod;

int main() {
	// Set the modulus value to 1000000007
	mod = 1000000007;
	
	// Read the number of elements
	int n = 0;
	cin >> n;
	
	// Initialize a vector to hold the integers
	vector<int> as(n);
	
	// Read n integers from input
	for (int i = 0; i < n; i++) {
		cin >> as[i];
	}
	
	// Initialize a vector to hold the unique sorted integers
	vector<int> xs = {as[0]};
	
	// Iterate through the input integers starting from the second element
	for (int j = 1; j < n; j++) {
		// Use binary search to find the position to insert the current integer
		int idx = lower_bound(xs.begin(), xs.end(), as[j]) - xs.begin();
		
		// If the index is equal to the length of xs, append the integer
		if (idx == xs.size()) {
			xs.push_back(as[j]);
		} else {
			// Otherwise, replace the existing integer at the found index
			xs[idx] = as[j];
		}
	}
	
	// Print the number of unique integers found
	cout << xs.size() << endl;
}

