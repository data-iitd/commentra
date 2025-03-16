#include <iostream>

using namespace std;

int main() {
	// Declare two integer variables K and X
	int K, X;
	
	// Read two integers from the standard input and assign them to K and X
	cin >> K >> X;
	
	// Check if the product of 500 and K is greater than or equal to X
	if (500*K >= X) {
		// If true, print "Yes"
		cout << "Yes" << endl;
	} else {
		// If false, print "No"
		cout << "No" << endl;
	}
	
	// End of code
	return 0;
}


