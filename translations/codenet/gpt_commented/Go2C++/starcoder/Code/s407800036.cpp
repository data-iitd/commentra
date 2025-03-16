#include <iostream>

using namespace std;

int main() {
	// Declare variables A, B, and C to hold integer values
	int A, B, C;
	
	// Read three integers from standard input
	cin >> A >> B >> C;

	// Check if C is within the range defined by A and B (inclusive)
	if (C >= A && C <= B) {
		// If C is within the range, print "Yes"
		cout << "Yes" << endl;
	} else {
		// If C is outside the range, print "No"
		cout << "No" << endl;
	}
}

