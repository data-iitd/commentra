
#include <iostream>

using namespace std;

int main() {
	// Declare three integer variables to hold the input values
	int a, b, c;
	
	// Read three integers from the standard input and assign them to a, b, and c
	cin >> a >> b >> c;
	
	// Check if c is between a and b (inclusive)
	if (c >= a && c <= b) {
		// If true, print "Yes"
		cout << "Yes" << endl;
	} else {
		// If false, print "No"
		cout << "No" << endl;
	}
	
	return 0;
}

