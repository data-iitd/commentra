
#include <bits/stdc++.h>

using namespace std;

// Initialize scanner
std::cin.tie(0);
std::ios_base::sync_with_stdio(false);
std::istream_iterator<string> input_iterator;
std::istream_iterator<string> end_iterator;

// Function to read an integer from standard input
int scanInt() {
	int val;
	cin >> val;
	return val;
}

// Main function
int main() {
	// Read the number of arms, n
	int n = scanInt();

	// Initialize a vector of arm structures, as
	struct arm {
		int l, r;
	};
	vector<arm> as(n);

	// Read and initialize each arm structure in the vector
	for (int i = 0; i < n; i++) {
		// Read the position and length of the arm
		int x = scanInt();
		int l = scanInt();

		// Initialize the left and right fields of the arm structure
		as[i].l = x - l;
		as[i].r = x + l;
	}

	// Sort the vector based on the right field of the arm structures
	sort(as.begin(), as.end(), [](arm a, arm b) {
		return a.r < b.r;
	});

	// Initialize answer variable, ans, and right variable, r
	int ans = 1;
	int r = as[0].r;

	// Iterate through the vector and update the answer and right variable accordingly
	for (int i = 1; i < n; i++) {
		if (as[i].l >= r) { // Check if the left end of the current arm is greater than or equal to the right end of the previous arm
			ans++; // Increment the answer if it is
			r = as[i].r; // Update the right variable with the right end of the current arm
		}
	}

	// Print the answer
	cout << ans << endl;

	// End of code


Translate the above C++ code to Python and end with comment "