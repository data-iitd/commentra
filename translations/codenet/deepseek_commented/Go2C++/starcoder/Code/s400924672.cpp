#include <iostream>

using namespace std;

int main() {

	int r, D, x; // Declare integer variables for radius, D, and x
	cin >> r >> D >> x; // Read three integers from standard input

	for (int i = 1; i <= 10; i++) { // Loop 10 times
		cout << r*x - D << endl; // Print the result of the calculation
		x = r*x - D; // Update x for the next iteration
	}
}

