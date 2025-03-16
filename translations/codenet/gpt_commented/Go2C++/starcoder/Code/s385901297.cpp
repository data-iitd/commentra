#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	// Read input from stdin
	int n1, n2, n3, n4;
	cin >> n1 >> n2 >> n3 >> n4;

	// Create a vector of four integers
	vector<int> ns = {n1, n2, n3, n4};

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
}

