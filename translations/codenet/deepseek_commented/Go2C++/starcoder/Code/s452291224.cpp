
#include <iostream>

using namespace std;

int main() {
	// Declare three integer variables A, B, and C
	int A, B, C;
	
	// Read three integers from the standard input and assign them to A, B, and C
	cin >> A >> B >> C;
	
	// Check if the expression C-A+B is less than 0
	if (C-A+B < 0) {
		// If true, print "0"
		cout << "0" << endl;
	} else {
		// Otherwise, print the value of C-A+B
		cout << C-A+B << endl;
	}
}

