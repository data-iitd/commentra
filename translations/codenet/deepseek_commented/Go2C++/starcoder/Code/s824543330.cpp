#include <iostream>

using namespace std;

int main() {
	// Declare two integer variables a and b
	int a, b;
	
	// Read two integers from the standard input and store them in a and b
	cin >> a >> b;
	
	// Check if the product of a and b is even or odd
	if (a*b)%2 == 0 {
		// If the product is even, print "Even"
		cout << "Even" << endl;
	} else {
		// If the product is odd, print "Odd"
		cout << "Odd" << endl;
	}
}

