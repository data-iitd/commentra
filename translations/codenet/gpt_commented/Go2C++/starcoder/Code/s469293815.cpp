
#include <iostream>

using namespace std;

int main() {
	// Declare three integer variables A, B, and C
	int A, B, C;
	
	// Read input values for A, B, and C from the standard input
	cin >> A >> B >> C;

	// Check if the sum of A and B is greater than or equal to C
	if (A+B >= C) {
		// If the condition is true, print "Yes"
		cout << "Yes" << endl;
	} else {
		// If the condition is false, print "No"
		cout << "No" << endl;
	}
}

