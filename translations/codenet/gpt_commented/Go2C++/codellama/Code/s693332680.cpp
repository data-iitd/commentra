#include <iostream>
using namespace std;

int main() {
	// Declare variables to hold input values
	int x, a, b;
	
	// Read three integer values from standard input
	cin >> x >> a >> b;
	
	// Evaluate the difference between b and a to determine the output
	switch (b-a) {
		// Case when the difference is less than or equal to 0
		case 0:
			cout << "delicious" << endl; // Output "delicious" if b is less than or equal to a
			break;
		// Case when the difference is less than or equal to x
		case 1:
			cout << "safe" << endl; // Output "safe" if the difference is within the limit x
			break;
		// Default case when the difference is greater than x
		default:
			cout << "dangerous" << endl; // Output "dangerous" if the difference exceeds x
			break;
	}
	
	return 0;
}
