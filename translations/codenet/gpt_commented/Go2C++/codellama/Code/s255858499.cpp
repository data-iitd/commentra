
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {
	// Set the scanner to split input by whitespace
	string line;
	getline(cin, line);
	stringstream ss(line);
	int a;
	ss >> a;
	getline(cin, line);
	stringstream ss2(line);
	int b;
	ss2 >> b;

	// Check if the product of a and b is odd
	if (a*b % 2 != 0) {
		// If the product is odd, print "Odd"
		cout << "Odd" << endl;
	} else {
		// If the product is even, print "Even"
		cout << "Even" << endl;
	}

	return 0;
}

