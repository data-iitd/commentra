#include <iostream>

int main() {
	// Declare a variable to hold the input value
	int x;
	
	// Read an integer value from standard input
	std::cin >> x;

	// Initialize the answer variable to store the result
	int ans = 0;
	
	// Determine the value of 'ans' based on the range in which 'x' falls
	if (x >= 400 && x <= 599) {
		ans = 8; // Set ans to 8 if x is between 400 and 599
	}
	if (x >= 600 && x <= 799) {
		ans = 7; // Set ans to 7 if x is between 600 and 799
	}
	if (x >= 800 && x <= 999) {
		ans = 6; // Set ans to 6 if x is between 800 and 999
	}
	if (x >= 1000 && x <= 1199) {
		ans = 5; // Set ans to 5 if x is between 1000 and 1199
	}
	if (x >= 1200 && x <= 1399) {
		ans = 4; // Set ans to 4 if x is between 1200 and 1399
	}
	if (x >= 1400 && x <= 1599) {
		ans = 3; // Set ans to 3 if x is between 1400 and 1599
	}
	if (x >= 1600 && x <= 1799) {
		ans = 2; // Set ans to 2 if x is between 1600 and 1799
	}
	if (x >= 1800 && x <= 9999) {
		ans = 1; // Set ans to 1 if x is between 1800 and 9999
	}

	// Print the final result
	std::cout << ans << std::endl;

	return 0;
}

