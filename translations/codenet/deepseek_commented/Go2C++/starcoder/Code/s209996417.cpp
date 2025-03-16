
#include <iostream>
#include <cmath>

using namespace std;

int main() {
	float n, k;
	cin >> n >> k;

	// Read two floating-point numbers, n and k, from standard input.
	// These represent the number to be converted and the base of the number system, respectively.

	// Calculate the number of digits in the base k representation of n.
	// The logic involves finding the smallest integer x such that k^x is less than or equal to n and n is less than k^(x+1).
	// Output x + 1 as the number of digits in the base k representation of n.

	float x = 0.0;
	while (true) {
		float under = pow(k, x);
		float upper = pow(k, x+1);

		if (under <= n && n < upper) {
			cout << x + 1 << endl;
			return 0;
		}
		x++;
	}
}

