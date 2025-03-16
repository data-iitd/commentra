
#include <iostream>
#include <cmath>

// Abs function returns the absolute value of an integer x.
int Abs(int x) {
	if (x < 0) {
		return -x; // If x is negative, return its negation.
	}
	return x; // If x is non-negative, return x itself.
}

// min function returns the smaller of two integers a and b.
int min(int a, int b) {
	if (a > b) {
		return b; // If a is greater than b, return b.
	}
	return a; // Otherwise, return a.
}

int main() {
	int N, K;
	// Read two integers N and K from standard input.
	std::cin >> N >> K;

	// The following block is commented out; it appears to be an alternative approach
	// to find a minimum value based on some conditions involving N and K.
	/*
	std::map<int, bool> hm; // Create a map to track seen values of N.
	for (;;) {
		if (!hm[N]) { // If N has not been seen before,
			hm[N] = true; // mark it as seen.
			N = Abs(N - K); // Update N to the absolute difference of N and K.
		} else {
			break; // If N has been seen, exit the loop.
		}
	}
	int mini = 999999999; // Initialize mini to a large value.
	for (auto k : hm) { // Iterate over the keys in the map.
		mini = std::min(mini, k.first); // Update mini to the minimum value found.
	}
	std::cout << mini << std::endl; // Print the minimum value found.
	*/

	int x;
	// Calculate the remainder of N divided by K.
	x = N % K;
	// Determine the minimum between the absolute difference of (x - K) and x.
	x = std::min(Abs(x - K), x);
	// Print the final result.
	std::cout << x << std::endl;

	return 0;
}
