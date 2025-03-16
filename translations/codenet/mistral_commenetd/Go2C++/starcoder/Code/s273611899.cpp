
// C++ code by <NAME>

#include <bits/stdc++.h>
using namespace std;

int main() {
	// Declare two integer variables 'n' and 'x'
	int n, x;

	// Loop infinitely until user inputs 0 for both 'n' and 'x'
	while (true) {
		// Read user input for 'n' and 'x'
		cin >> n >> x;

		// Check if user has entered 0 for both 'n' and 'x' to break the loop
		if (n == 0 && x == 0) {
			break;
		}

		// Declare an integer variable 'c' to store the count of triples
		int c = 0;

		// Inner loop to find triples that sum up to 'x'
		for (int i = 1; i <= n-2; i++) {
			// Inner loop to compare 'j' with all the remaining numbers
			for (int j = i + 1; j <= n-1; j++) {
				// Inner loop to compare 'k' with all the remaining numbers
				for (int k = j + 1; k <= n; k++) {
					// Check if the sum of 'i', 'j', and 'k' equals 'x'
					if (i+j+k == x) {
						// Increment the count 'c' if the condition is true
						c++;
					}
				}
			}
		}

		// Print the count of triples that sum up to 'x'
		cout << c << endl;
	}

	// End of the code
}

