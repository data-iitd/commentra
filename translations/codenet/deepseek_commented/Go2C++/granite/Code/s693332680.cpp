
#include <iostream>

using namespace std;

int main() {
	// Declare three integer variables x, a, and b to store input values.
	int x, a, b;
	
	// Read three integers from the standard input and assign them to x, a, and b.
	cin >> x >> a >> b;
	
	// Use a switch statement to evaluate the condition b-a and execute the corresponding block of code.
	switch (true) {
		// If b-a is less than or equal to 0, print "delicious".
		case b-a <= 0:
			cout << "delicious" << endl;
			break;
		// If b-a is greater than 0 but less than or equal to x, print "safe".
		case b-a <= x:
			cout << "safe" << endl;
			break;
		// If b-a is greater than x, print "dangerous".
		default:
			cout << "dangerous" << endl;
			break;
	}
	
	return 0;
}
