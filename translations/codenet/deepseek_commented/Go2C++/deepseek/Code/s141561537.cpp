#include <iostream>
using namespace std;

int main() {
	int a, b, c, x, sum = 0; // Declare variables to store input and result
	cin >> a >> b >> c >> x; // Read input values for a, b, c, and x

	// Nested loops to iterate through all combinations of coins
	for (int i = 0; i <= a; i++) {
		for (int j = 0; j <= b; j++) {
			for (int k = 0; k <= c; k++) {
				if (500 * i + 100 * j + 50 * k == x) { // Check if the total value equals the target value
					sum++; // Increment the sum if the condition is met
				}
			}
		}
	}

	cout << sum << endl; // Output the number of combinations that meet the condition
}

