
#include <bits/stdc++.h>

using namespace std;

// -----------------------------------------

const int inf = 1 << 60; // Constant inf is set to 2^60
// const int mod = 1000000007; // Constant mod is set to 1000000007

// -----------------------------------------

int main() {
	// Main function
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n; // Read the number of elements in the array
	cin >> n;
	int a[n]; // Read the array elements
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	// Initialize an array xs of size n
	int xs[n];
	// Iterate through the array as and assign the value xs[i]
	for (int i = 0; i < n; i++) {
		xs[i] = a[i] - i + 1; // Assign the value xs[i] = a[i] - i + 1
	}
	// Sort the array xs in ascending order
	sort(xs, xs + n);

	// Assign the middle element of the sorted array xs to variable b
	int b = xs[n / 2];
	// Initialize variable ans with 0
	int ans = 0;
	// Iterate through the array xs and calculate the absolute difference between each element and b
	for (int i = 0; i < n; i++) {
		ans += abs(xs[i] - b); // Calculate the absolute difference and add it to ans
	}
	// Print the answer
	cout << ans << "\n";
}

// -----------------------------------------

int abs(int n) {
	// Function to calculate the absolute difference of a number
	if (n < 0) {
		// If the number is negative, return the negative number with the minus sign removed
		return -n;
	}
	// If the number is non-negative, return the number itself
	return n;
}

// -----------------------------------------

