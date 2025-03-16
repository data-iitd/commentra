
#include <iostream>
using namespace std;

// gcd calculates the greatest common divisor of two integers using the Euclidean algorithm
int gcd(int a, int b) {
	if (b == 0) {
		return a;
	}
	return gcd(b, a%b);
}

int main() {
	int k, a, b, c, ans = 0;
	cin >> k; // Read the value of k from the input

	// Iterate over all possible values of a, b, and c from 1 to k
	for (a = 1; a <= k; a++) {
		for (b = 1; b <= k; b++) {
			for (c = 1; c <= k; c++) {
				// Calculate the greatest common divisor of a and the greatest common divisor of b and c, and add it to ans
				ans += gcd(a, gcd(b, c));
			}
		}
	}

	cout << ans << endl; // Print the final value of ans
	return 0;
}

