#include <iostream>

using namespace std;

int main() {
	// Declare three integer variables: a, b, and c
	int a, b, c;

	// Use the cin function to read three integers from the standard input and store them in variables a, b, and c
	cin >> a >> b >> c;

	// Check if the condition a < b and b < c is true. If it is, print "Yes" to the standard output using the cout function. Otherwise, print "No"
	if (a < b && b < c) {
		cout << "Yes" << endl; // If the condition is true, print "Yes"
	} else {
		cout << "No" << endl; // If the condition is false, print "No"
	}

	// Return 0 to indicate successful execution of the program
	return 0;
}

