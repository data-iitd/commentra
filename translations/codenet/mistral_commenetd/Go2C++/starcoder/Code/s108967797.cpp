
#include <bits/stdc++.h>

using namespace std;

// Initialize a new scanner for reading input from stdin
std::unique_ptr<std::stringstream> sc = std::make_unique<std::stringstream>();

// Function to read an integer from standard input
int ri() {
	sc->clear(); // Clear the input buffer
	std::getline(*sc, std::string()); // Read a line from input
	return stoi(sc->str()); // Convert the string to an integer and return it
	// Return the read integer
}

// Function to calculate the average of a slice of float64 numbers
float64 ave(vector<float64> s) {
	float64 sum = 0; // Initialize a variable to store the sum of numbers in the slice
	for (float64 v : s) { // Iterate through each number in the slice
		sum += v; // Add the current number to the sum
	}
	return sum / float64(s.size()); // Calculate and return the average
}

// Function to calculate the difference between two float64 numbers
float64 diff(float64 a, float64 b) {
	if (a > b) { // Check if the first number is greater than the second number
		return a - b; // If so, return the difference
	}
	return b - a; // If not, return the negative difference
}

// Main function
int main() {
	// Initialize the scanner to read words instead of lines
	sc->str(std::string());
	sc->clear();
	sc->seekg(0);
	sc->sync_with_stdio(false);

	// Read the number of elements in the array from standard input
	int n = ri();

	// Allocate memory for an array of float64 numbers with the given size
	vector<float64> a(n);

	// Read each element of the array from standard input and store it in the corresponding index
	for (int i = 0; i < n; i++) {
		a[i] = float64(ri()); // Read an integer from standard input and convert it to a float64 number
	}
	// Print the array for debugging purposes (uncomment this line if needed)
	// std::cout << a << std::endl;

	// Calculate the average of the array elements
	float64 ave = ave(a);

	// Initialize variables to store the minimum difference and the index of the element with the minimum difference
	float64 minDiff = 999999.9;
	int ansIndex = -1;

	// Iterate through each element of the array and find the one with the minimum difference from the average
	for (int i = 0; i < n; i++) {
		float64 diff = diff(a[i], ave); // Calculate the difference between the current element and the average
		if (diff < minDiff) { // Check if the difference is smaller than the current minimum difference
			minDiff = diff; // If so, update the minimum difference
			ansIndex = i; // and the index of the answer
		}
	}

	// Print the index of the element with the minimum difference from the average
	std::cout << ansIndex << std::endl;

// End of the code

