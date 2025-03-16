#include <iostream>

using namespace std;

int main() {
	// Declare variables to hold input values
	int x, a, b;
	
	// Read three integer values from standard input
	cin >> x >> a >> b;
	
	// Evaluate the difference between b and a to determine the output
	switch {
		// Case when the difference is less than or equal to 0
		case b-a <= 0:
			cout << "delicious" << endl; // Output "delicious" if b is less than or equal to a
			break;
		// Case when the difference is less than or equal to x
		case b-a <= x:
			cout << "safe" << endl; // Output "safe" if the difference is within the limit x
			break;
		// Default case when the difference is greater than x
		default:
			cout << "dangerous" << endl; // Output "dangerous" if the difference exceeds x
			break;
	}
}

