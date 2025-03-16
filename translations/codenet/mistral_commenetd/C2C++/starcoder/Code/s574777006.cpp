
#include <iostream>

using namespace std;

// Declare variables
int n, i, j, q, x[10000], y[500], sum = 0;

int main() {
	// Read the number of elements in the array x
	cin >> n;

	// Allocate memory for array x
	for( i = 0; i < n; i++) {
		// Read each element of array x
		cin >> x[i];
	}

	// Read the number of queries
	cin >> q;

	// Allocate memory for array y
	for( i = 0; i < q; i++) {
		// Read each element of array y
		cin >> y[i];
	}

	// Initialize sum to zero
	sum = 0;

	// Check if each element of array y is present in array x and increment sum if found
	for( i = 0; i < q; i++) {
		for( j = 0; j < n; j++) {
			// Check if current element of y is equal to current element of x
			if( y[i]==x[j]) {
				// Increment sum if found
				sum = sum + 1;
				// Break out of inner loop as soon as a match is found
				break ;
			}
		}
	}

	// Print the value of sum
	cout << sum << endl;

	// Return 0 to indicate successful execution
	return 0;
}

