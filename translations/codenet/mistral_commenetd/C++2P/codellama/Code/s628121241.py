
#include<iostream>
#include<algorithm>
#include<stdlib.h>
using namespace std;

// Function to find the greatest common divisor (GCD) of two numbers
int gcd(int a, int b) {
	// Base case: if 'a' is 0, return 'b' as the GCD
	if (a == 0) {
		return b;
	}
	// Recursive case: call the function with the remainder of 'a' and 'b' as arguments
	return gcd(b % a, a);
}

int main() {
	// Declare and read the value of 'R' from the standard input
	int R;
	cin >> R;

	// Check the value of 'R' and print the corresponding output
	if (R < 1200) {
		cout << "ABC" << endl; // Output: "ABC" if 'R' is less than 1200
	}
	else if (R >= 2800) {
		cout << "AGC" << endl; // Output: "AGC" if 'R' is greater than or equal to 2800
	}
	else {
		cout << "ARC" << endl; // Output: "ARC" if 'R' is between 1200 and 2800 (inclusive)
	}

	return 0;
}

