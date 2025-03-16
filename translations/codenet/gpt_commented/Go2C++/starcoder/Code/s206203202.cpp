#include <iostream>
#include <map>
#include <vector>

using namespace std;

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
	cin >> N >> K;

	// The following block is commented out; it appears to be an alternative approach
	// to find a minimum value based on some conditions involving N and K.
	/*
	map<int, bool> hm; // Create a map to track seen values of N.
	while (true) {
		if (hm.find(N) == hm.end()) { // If N has not been seen before,
			hm[N] = true; // mark it as seen.
			N = Abs(N - K); // Update N to the absolute difference of N and K.
		} else {
			break; // If N has been seen, exit the loop.
		}
	}
	int mini = 999999999; // Initialize mini to a large value.
	for (auto k : hm) { // Iterate over the keys in the map.
		mini = min(mini, k); // Update mini to the minimum value found.
	}
	cout << mini << endl; // Print the minimum value found.
	*/

	int x;
	// Calculate the remainder of N divided by K.
	x = N % K;
	// Determine the minimum between the absolute difference of (x - K) and x.
	x = min(Abs(x-K), x);
	// Print the final result.
	cout << x << endl;
}

