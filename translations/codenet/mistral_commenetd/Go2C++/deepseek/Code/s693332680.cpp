// Importing necessary packages
#include <iostream>
using namespace std;

// Declaring variables
int main() {
	int x, a, b;

	// Reading input values from standard input
	cin >> x >> a >> b;

	// Logic block to check if b is less than or equal to a
	if (b - a <= 0) {
		cout << "delicious" << endl;
	}
	// Next case: If b is greater than a but less than or equal to x
	else if (b - a <= x) {
		cout << "safe" << endl;
	}
	// Default case: If none of the above conditions are met
	else {
		cout << "dangerous" << endl;
	}

	return 0;
}

