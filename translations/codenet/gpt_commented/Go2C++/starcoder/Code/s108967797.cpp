#include <bits/stdc++.h>

using namespace std;

// Function to read an integer from input
int ri() {
	int n;
	cin >> n;
	return n;
}

// Function to calculate the average of a slice of float64 numbers
float64 ave(vector<float64> s) {
	float64 sum = 0;
	for (float64 v : s) { // Iterate over each value in the slice
		sum += v; // Accumulate the sum of the values
	}
	return sum / float64(s.size()); // Return the average
}

// Function to calculate the absolute difference between two float64 numbers
float64 diff(float64 a, float64 b) {
	if (a > b) {
		return a - b; // Return the difference if a is greater than b
	}
	return b - a; // Return the difference if b is greater than or equal to a
}

int main() {
	int n = ri(); // Read the number of elements
	vector<float64> a(n); // Create a slice to hold the float64 numbers
	for (int i = 0; i < n; i++) {
		a[i] = float64(ri()); // Read each integer and convert it to float64
	}
	// cout << a << endl; // Uncomment to print the array of float64 numbers

	// Calculate the average of the numbers
	float64 ave = ave(a);

	// Initialize variables to track the minimum difference and the corresponding index
	float64 minDiff = 999999.9;
	int ansIndex = -1;
	for (int i = 0; i < n; i++) { // Iterate over the slice to find the closest value to the average
		float64 diff = diff(a[i], ave); // Calculate the difference between the current value and the average
		if (diff < minDiff) { // Check if the current difference is less than the minimum difference found so far
			minDiff = diff; // Update the minimum difference
			ansIndex = i; // Update the index of the closest value
		}
	}
	// Print the index of the value closest to the average
	cout << ansIndex << endl;
}

