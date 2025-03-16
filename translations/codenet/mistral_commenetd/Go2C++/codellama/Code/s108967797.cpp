
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Function to read an integer from standard input
int ri() {
	int n; // Initialize a variable to store the read integer
	cin >> n; // Read an integer from standard input
	return n; // Return the read integer
}

// Function to calculate the average of a vector of float numbers
float ave(vector<float> s) {
	float sum = 0; // Initialize a variable to store the sum of numbers in the vector
	for (int i = 0; i < s.size(); i++) { // Iterate through each number in the vector
		sum += s[i]; // Add the current number to the sum
	}
	return sum / s.size(); // Calculate and return the average
}

// Function to calculate the difference between two float numbers
float diff(float a, float b) {
	if (a > b) { // Check if the first number is greater than the second number
		return a - b; // If so, return the difference
	}
	return b - a; // If not, return the negative difference
}

// Main function
int main() {
	// Read the number of elements in the array from standard input
	int n = ri();

	// Allocate memory for an array of float numbers with the given size
	vector<float> a(n);

	// Read each element of the array from standard input and store it in the corresponding index
	for (int i = 0; i < n; i++) {
		a[i] = ri(); // Read an integer from standard input and convert it to a float number
	}
	// Print the array for debugging purposes (uncomment this line if needed)
	// cout << a << endl;

	// Calculate the average of the array elements
	float ave = ave(a);

	// Initialize variables to store the minimum difference and the index of the element with the minimum difference
	float minDiff = 999999.9;
	int ansIndex = -1;

	// Iterate through each element of the array and find the one with the minimum difference from the average
	for (int i = 0; i < n; i++) {
		float diff = diff(a[i], ave); // Calculate the difference between the current element and the average
		if (diff < minDiff) { // Check if the difference is smaller than the current minimum difference
			minDiff = diff; // If so, update the minimum difference
			ansIndex = i; // and the index of the answer
		}
	}

	// Print the index of the element with the minimum difference from the average
	cout << ansIndex << endl;

	return 0;
}

