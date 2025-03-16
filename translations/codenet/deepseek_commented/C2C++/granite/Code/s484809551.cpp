
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

// Define constants for maximum sizes and array size for dynamic programming
const int N_MAX = 100;
const int P_MAX = 100;
const int DP_ARRAY_SIZE = (N_MAX * P_MAX / 32) + 1;

// Function to find the last occurrence of a substring within a string
static string strrstr(const string &string, const string &pattern) {
	size_t offset = 0;
	string lastP = "";

	string searchResult = "";
	// Loop to find the last occurrence of the pattern
	while ((searchResult = string(string).substr(offset)).find(pattern)!= string::npos && string[offset]!= '\0') {
		lastP = searchResult; // Update last found position
		offset++; // Move offset to search for further occurrences
	}

	return lastP; // Return the last found position
}

// Comparison function for qsort, comparing two size_t values
int compare_f(const void *a, const void *b) {
	return *((size_t *)a) < *((size_t *)b)? -1 : 1; // Return comparison result
}

// Function to calculate combinations C(n, r)
static size_t comb(const size_t n, const size_t r) {
	size_t result = 1;

	// Calculate the combination using the formula
	for (size_t i = 0; i < r; i++) {
		result *= n - i; // Multiply by decreasing values of n
		result /= i + 1; // Divide by increasing values of r
	}

	return result; // Return the result
}

// Function to compute the greatest common divisor (GCD) of two numbers
static uint64_t gcd(uint64_t m, uint64_t n) {
	uint64_t temp;

	// Euclidean algorithm to find GCD
	while (m % n!= 0) {
		temp = n;
		n = m % n; // Update n to the remainder
		m = temp; // Update m to the previous n
	}

	return n; // Return the GCD
}

// Main function to execute the program
int main() {
	string patternBase = "keyence"; // Define the pattern to search for
	string top = "", bottom = ""; // Buffers to hold split parts of the pattern
	string S = ""; // Buffer to hold the input string

	// Read the input string
	cin >> S;

	const size_t len = S.length(); // Get the length of the input string
	bool found = false; // Flag to indicate if the pattern is found

	// Loop through each possible split point in the pattern
	for (size_t offset = 0; offset < patternBase.length(); offset++) {
		// Split the pattern into top and bottom parts
		top = patternBase.substr(0, offset);
		bottom = patternBase.substr(offset);

		// Search for the top part in the input string
		size_t topPos = S.find(top);
		if (topPos!= string::npos) {
			// Search for the bottom part after the found top part
			size_t bottomPos = strrstr(S.substr(topPos + offset), bottom).find(bottom);
			if (bottomPos!= string::npos) {
				size_t sepCount = 0; // Counter for separators

				// Count the number of separators between top and bottom parts
				if (topPos!= 0) {
					sepCount++; // Increment if there's text before the top part
				}
				if (&(S[topPos + offset])!= &(S[topPos + offset + bottom.length()])) {
					sepCount++; // Increment if there's text between top and bottom parts
				}
				if (S[topPos + offset + bottom.length()]!= '\0') {
					sepCount++; // Increment if there's text after the bottom part
				}

				// Check if the number of separators is less than or equal to 1
				if (sepCount <= 1) {
					found = true; // Set found flag to true
					break; // Exit the loop as the pattern is found
				}
			}
		}
	}

	// Output the result based on whether the pattern was found
	cout << (found? "YES" : "NO") << endl; // Output the result

	return 0; // Return success
}

