
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// nextInt reads the next integer from the scanner and returns it.
int nextInt(Scanner &sc) {
	string token;
	sc >> token;
	return stoi(token);
}

// reva reverses a vector of integers in place.
void reva(vector<int> &b) {
	for (int i = 0; i < b.size() / 2; i++) {
		// Swap the elements at positions i and b.size()-1-i
		swap(b[i], b[b.size()-1-i]);
	}
}

int main() {
	Scanner sc(cin);
	// Read the number of elements in the array
	int n = nextInt(sc);
	vector<int> a(n); // Initialize a vector of integers with length n

	// Populate the vector with integers from input
	for (int i = 0; i < n; i++) {
		a[i] = nextInt(sc); // Read each integer and store it in the vector
	}

	// Read the number of queries
	int q = nextInt(sc);
	// Process each query
	for (int i = 0; i < q; i++) {
		int b = nextInt(sc); // Read the starting index for the reversal
		int e = nextInt(sc); // Read the ending index for the reversal
		reva(vector<int>(a.begin()+b, a.begin()+e)); // Reverse the vector from index b to e
	}

	// Write the modified vector to output
	for (int i = 0; i < n; i++) {
		if (i > 0) {
			cout << " "; // Print a space before each element except the first
		}
		cout << a[i]; // Print the current element
	}
	cout << endl; // Print a newline after the output

	return 0;
}

