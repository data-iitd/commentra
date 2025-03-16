
#include <iostream>

using namespace std;

int main() {
	int A, B, C;
	cin >> A >> B >> C;

	// Read three integers from standard input
	// A, B, and C will store these values

	if (A+B >= C) {
		// Check if the sum of A and B is greater than or equal to C
		cout << "Yes" << endl;
	} else {
		// If the sum is less than C, print "No"
		cout << "No" << endl;
	}
}

