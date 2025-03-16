#include <bits/stdc++.h>

using namespace std;

// Function to read input from standard input
int scanInt() {
	int x;
	cin >> x;
	return x;
}

// Main function where the program execution begins
int main() {
	// Read the number of arms
	int n = scanInt();
	
	// Define a struct to represent an arm with left and right bounds
	struct arm { int l, r; };
	
	// Create a vector to hold the arms
	vector<arm> as(n);
	
	// Read the arm data from input
	for (int i = 0; i < n; i++) {
		int x, l = scanInt(); // Read the center and length of the arm
		as[i].l = x - l; // Calculate the left bound
		as[i].r = x + l; // Calculate the right bound
	}
	
	// Sort the arms based on their right bounds
	sort(as.begin(), as.end(), [](const arm &a, const arm &b) { return a.r < b.r; });
	
	// Initialize the count of non-overlapping arms and the rightmost bound
	int ans = 1; // Start with the first arm
	int r = as[0].r; // Set the rightmost bound to the right of the first arm
	
	// Iterate through the sorted arms to count non-overlapping arms
	for (int i = 1; i < n; i++) {
		// If the left bound of the current arm is greater than or equal to the rightmost bound
		if (as[i].l >= r) {
			ans++; // Increment the count of non-overlapping arms
			r = as[i].r; // Update the rightmost bound to the current arm's right bound
		}
	}
	
	// Print the total count of non-overlapping arms
	cout << ans << endl;
}

