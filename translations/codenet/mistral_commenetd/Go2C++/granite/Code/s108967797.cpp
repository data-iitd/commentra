

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Function to read an integer from standard input
int ri() {
	int n;
	cin >> n;
	return n;
}

// Function to calculate the average of a vector of float numbers
float ave(vector<float> &s) {
	float sum = 0;
	for (float v : s) {
		sum += v;
	}
	return sum / s.size();
}

// Function to calculate the difference between two float numbers
float diff(float a, float b) {
	if (a > b) {
		return a - b;
	}
	return b - a;
}

int main() {
	// Read the number of elements in the array from standard input
	int n = ri();

	// Allocate memory for a vector of float numbers with the given size
	vector<float> a(n);

	// Read each element of the array from standard input and store it in the corresponding index
	for (int i = 0; i < n; i++) {
		a[i] = ri();
	}

	// Print the array for debugging purposes (uncomment this line if needed)
	// for (float v : a) {
	// 	cout << v << " ";
	// }
	// cout << endl;

	// Calculate the average of the array elements
	float ave_ = ave(a);

	// Initialize variables to store the minimum difference and the index of the element with the minimum difference
	float minDiff = 999999.9;
	int ansIndex = -1;

	// Iterate through each element of the array and find the one with the minimum difference from the average
	for (int i = 0; i < n; i++) {
		float diff_ = diff(a[i], ave_);
		if (diff_ < minDiff) {
			minDiff = diff_;
			ansIndex = i;
		}
	}

	// Print the index of the element with the minimum difference from the average
	cout << ansIndex << endl;

// End of the code
}

