#include <bits/stdc++.h>

using namespace std;

// Function to print output to the console
void out(const vector<int>& x) {
	for (int i = 0; i < x.size(); i++) {
		cout << x[i] << " ";
	}
	cout << endl;
}

// Function to read an integer from input
int getInt() {
	int x;
	cin >> x;
	return x;
}

// Function to read a string from input
string getString() {
	string x;
	cin >> x;
	return x;
}

// Basic utility functions for mathematical operations
int max(int a, int b) {
	if (a > b) {
		return a;
	}
	return b;
}

int min(int a, int b) {
	if (a < b) {
		return a;
	}
	return b;
}

int asub(int a, int b) {
	if (a > b) {
		return a - b;
	}
	return b - a;
}

int abs(int a) {
	if (a >= 0) {
		return a;
	}
	return -a;
}

int main() {
	// Set the scanner to split input by words
	cin.sync_with_stdio(false);
	cin.tie(0);

	// Read the number of elements (N), maximum count (C), and time limit (K)
	int N, C, K;
	cin >> N >> C >> K;

	vector<int> t(N); // Create a vector to hold the time values

	// Read N time values from input
	for (int i = 0; i < N; i++) {
		cin >> t[i];
	}

	sort(t.begin(), t.end()); // Sort the time values in ascending order

	// Initialize variables for counting groups and tracking the end time
	int ans = 1; // Start with one group
	int cnt = 1; // Count of elements in the current group
	int end = t[0] + K; // Calculate the end time for the first group

	// Iterate through the sorted time values
	for (int i = 1; i < N; i++) {
		// Check if we can add the current time to the current group
		if (cnt < C && t[i] <= end) {
			cnt++; // Increment the count of the current group
		} else {
			// Start a new group since the current time exceeds the end time
			cnt = 1; // Reset the count for the new group
			end = t[i] + K; // Update the end time for the new group
			ans++; // Increment the group count
		}
	}
	out(t); // Output the total number of groups formed
}

