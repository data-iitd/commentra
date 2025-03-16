
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	// Create a vector to hold four integers
	vector<int> ns(4);

	// Read a line of input and parse it into the vector
	for (int i = 0; i < 4; i++) {
		cin >> ns[i];
	}

	// Sort the vector of integers in ascending order
	sort(ns.begin(), ns.end());

	// Check if the sorted integers match the specific sequence [1, 4, 7, 9]
	if (ns[0] == 1 && ns[1] == 4 && ns[2] == 7 && ns[3] == 9) {
		// If they match, print "YES"
		cout << "YES" << endl;
	} else {
		// If they do not match, print "NO"
		cout << "NO" << endl;
	}

	return 0;
}

