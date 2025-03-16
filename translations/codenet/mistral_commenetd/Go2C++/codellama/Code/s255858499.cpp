
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int main() {
	// Set the scanner to split input on words
	string a, b;
	cin >> a >> b;
	
	// Check if the product of a and b is odd or even
	if (stoi(a) * stoi(b) % 2 != 0) {
		// If the product is odd, print "Odd" to stdout
		cout << "Odd" << endl;
	} else {
		// If the product is even, print "Even" to stdout
		cout << "Even" << endl;
	}
	
	return 0;
}

