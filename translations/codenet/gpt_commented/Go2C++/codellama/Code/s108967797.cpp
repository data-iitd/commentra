
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Function to read an integer from input
int ri() {
	int n;
	cin >> n;
	return n;
}

// Function to calculate the average of a vector of float numbers
float ave(vector<float> s) {
	float sum = 0;
	for (int i = 0; i < s.size(); i++) {
		sum += s[i];
	}
	return sum / s.size();
}

// Function to calculate the absolute difference between two float numbers
float diff(float a, float b) {
	if (a > b) {
		return a - b;
	}
	return b - a;
}

int main() {
	int n = ri();
	vector<float> a(n);
	for (int i = 0; i < n; i++) {
		a[i] = ri();
	}
	// Calculate the average of the numbers
	float ave = ave(a);

	// Initialize variables to track the minimum difference and the corresponding index
	float minDiff = 999999.9;
	int ansIndex = -1;
	for (int i = 0; i < n; i++) {
		float diff = diff(a[i], ave);
		if (diff < minDiff) {
			minDiff = diff;
			ansIndex = i;
		}
	}
	// Print the index of the value closest to the average
	cout << ansIndex << endl;
	return 0;
}

