
#include <iostream>

using namespace std;

int main() {
	// Declare two integer variables, K and X
	int K, X;

	// Read two integers from the standard input and assign them to the variables K and X respectively
	cin >> K >> X;

	// Check if the condition 500*K >= X is true
	if (500*K >= X) {
		// If the condition is true, print the string "Yes" to the standard output
		cout << "Yes" << endl;
	} else {
		// If the condition is false, print the string "No" to the standard output
		cout << "No" << endl;
	}

	return 0;
}

