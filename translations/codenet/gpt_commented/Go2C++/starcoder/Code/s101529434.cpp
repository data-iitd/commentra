#include <iostream>

using namespace std;

int main() {
	// Declare variables K and X to hold input values
	int K, X;
	
	// Read two integers from standard input
	cin >> K >> X;
	
	// Check if 500 times K is greater than or equal to X
	if (500*K >= X) {
		// If the condition is true, print "Yes"
		cout << "Yes" << endl;
	} else {
		// If the condition is false, print "No"
		cout << "No" << endl;
	}
}

