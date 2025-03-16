
#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
	// Initialize variables
	int n, m, a, b;
	// Read input from standard input
	cin >> n >> m;
	// Allocate memory for h array
	vector<int> h(n);
	// Read h array elements from standard input
	for (int i = 0; i < n; i++) {
		cin >> h[i];
		// Comment for the loop that reads h array elements
		// from standard input
		// and stores them in the h array
	}
	// Initialize counter map
	map<int, bool> counter;
	// Read m query pairs from standard input
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		// Check the condition for a and b
		if (h[a-1] < h[b-1]) {
			// Add a to the counter map if h[a-1] is smaller than h[b-1]
			counter[a] = true;
		} else if (h[a-1] > h[b-1]) {
			// Add b to the counter map if h[a-1] is greater than h[b-1]
			counter[b] = true;
		} else if (h[a-1] == h[b-1]) {
			// Add both a and b to the counter map if h[a-1] is equal to h[b-1]
			counter[a] = true;
			counter[b] = true;
		}
		// Comment for the loop that processes m query pairs
	}
	// Print the result
	cout << n - counter.size() << endl;
	// Comment for the final print statement
}

