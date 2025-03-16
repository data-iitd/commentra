#include <bits/stdc++.h>

using namespace std;

// mod is a global variable for storing a modulus value
int mod;

// main function initializes the modulus value, sets up the bufio.Scanner, and reads the number of elements
int main() {
	mod = 1000000007;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	vector<int> as(n);
	for (int i = 0; i < n; i++) {
		cin >> as[i];
	}
	
	// Initialize xs with the first element of as
	vector<int> xs = {as[0]};
	for (int j = 1; j < n; j++) {
		// Use sort.Search to find the position to insert the current element
		int idx = lower_bound(xs.begin(), xs.end(), as[j]) - xs.begin();
		if (idx == xs.size()) {
			// If the element is larger than all elements in xs, append it
			xs.push_back(as[j]);
		} else {
			// Otherwise, replace the existing element at the found position
			xs[idx] = as[j];
		}
	}
	
	// Print the length of the longest increasing subsequence found
	cout << xs.size() << endl;
}

