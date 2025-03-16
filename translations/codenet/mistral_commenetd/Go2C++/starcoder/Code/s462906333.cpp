
// Importing necessary packages
#include <bits/stdc++.h>

using namespace std;

// Constants and variables declaration
const int inf = 1e14;

// Function to read input from standard input using buffered reader
class scanner {
public:
	// Creating a new scanner object
	scanner() {
		r = new istringstream(cin.rdbuf());
	}

	// Function to read next token from input
	string next() {
		while (isspace(*r)) {
			r++;
		}
		string s;
		while (!isspace(*r)) {
			s += *r;
			r++;
		}
		return s;
	}

	// Function to read a complete line from input
	string Line() {
		string s;
		getline(*r, s);
		return s;
	}

	// Function to read an integer from input
	int Int() {
		return atoi(next().c_str());
	}

	// Function to read an integer64 from input
	long long Int64() {
		return atoll(next().c_str());
	}

private:
	// Creating a new buffered reader object
	istringstream *r;
};

// Main function
int main() {
	// Setting up logging
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// Creating a new scanner object
	scanner s;

	// Reading input
	int n = s.Int();
	int x = s.Int();

	// Initializing arrays
	int a[n];
	int v[n];
	copy(a, v, n);

	// Initializing answer variable
	int ans = inf;

	// Iterating through all possible subarrays
	for (int k = 0; k < n; k++) {
		// Initializing variable to store sum of subarray elements
		int kans = 0;

		// Iterating through all elements of the subarray
		for (int i = 0; i < n; i++) {
			// Checking if current index is out of bounds for subarray
			if (i - k < 0) {
				// Updating current element in subarray with minimum of itself and corresponding element from the main array
				v[i] = min(v[i], a[n + i - k]);
			} else {
				// Updating current element in subarray with minimum of itself and previous element in subarray
				v[i] = min(v[i], a[i - k]);
			}

			// Adding current element to the sum of subarray
			kans += v[i];
		}

		// Updating answer with minimum of current answer and sum of subarray and multiplication of its size and x
		ans = min(ans, kans + k * x);
	}

	// Printing the answer
	cout << ans << endl;
}

// Helper functions
int min(int a, int b) {
	return a < b? a : b;
}

// -------------------------------
// Function to check if a given number is inside a given range
bool in(int c, int a, int z) {
	return c >= a && c < z;
}

// Function to convert boolean value to integer
int btoi(bool b) {
	if (b) {
		return 1;
	}
	return 0;
}

// Function to convert integer value to boolean
bool itob(int a) {
	if (a == 0) {
		return false;
	}
	return true;
}

