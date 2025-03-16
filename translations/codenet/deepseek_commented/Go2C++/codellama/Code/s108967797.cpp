
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// ri() reads an integer from standard input.
int ri() {
	int n;
	cin >> n;
	return n;
}

// ave(s) calculates the average of a vector of float values.
float ave(vector<float> s) {
	float sum = 0;
	for (int i = 0; i < s.size(); i++) {
		sum += s[i];
	}
	return sum / s.size();
}

// diff(a, b) calculates the absolute difference between two float values.
float diff(float a, float b) {
	if (a > b) {
		return a - b;
	}
	return b - a;
}

int main() {
	int n = ri(); // Reads the number of elements.
	vector<float> a(n);
	for (int i = 0; i < n; i++) {
		a[i] = ri(); // Reads n integers into a vector of float values.
	}
	// Uncommenting the following line will print the vector for debugging purposes.
	// cout << a << endl;

	float ave = ave(a); // Calculates the average of the vector.

	float minDiff = 999999.9;
	int ansIndex = -1;
	for (int i = 0; i < n; i++) {
		float diff = diff(a[i], ave); // Calculates the absolute difference between each element and the average.
		if (diff < minDiff) {
			minDiff = diff;
			ansIndex = i;
		}
	}
	cout << ansIndex << endl; // Outputs the index with the smallest difference.
	return 0;
}

