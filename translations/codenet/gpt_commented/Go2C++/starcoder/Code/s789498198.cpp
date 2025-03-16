#include <bits/stdc++.h>

using namespace std;

int main() {
	// Read two integers from input
	int A, B;
	cin >> A >> B;

	// Check if the sum of A and B is even
	if ((A + B) % 2 == 0) {
		// If even, print the average
		cout << (A + B) / 2 << endl;
		return;
	}
	// If odd, print "IMPOSSIBLE"
	cout << "IMPOSSIBLE" << endl;
}

