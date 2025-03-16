#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>

// Define constants for maximum sizes and array size for dynamic programming
const size_t N_MAX = 100;
const size_t P_MAX = 100;
const size_t DP_ARRAY_SIZE = N_MAX * P_MAX / 32 + 1;

// Define macros for common operations
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define ABS(a) ((a) < 0 ? -(a) : (a))
#define ABSS(a, b) ((a) > (b) ? (a) - (b) : (b) - (a))

// Function to find the last occurrence of a substring within a string
std::string strrstr(const std::string &string, const std::string &pattern) {
	size_t offset = 0;
	std::string lastP;

	while (true) {
		size_t pos = string.find(pattern, offset);
		if (pos == std::string::npos) {
			break;
		}
		lastP = string.substr(pos);
		offset = pos + 1;
	}

	return lastP;
}

// Comparison function for sort, comparing two size_t values
bool compare_f(const size_t &a, const size_t &b) {
	return a < b ? true : false;
}

// Function to calculate combinations C(n, r)
size_t comb(const size_t n, const size_t r) {
	size_t result = 1;

	// Calculate the combination using the formula
	for (size_t i = 0; i < r; i++) {
		result *= n - i; // Multiply by decreasing values of n
		result /= i + 1; // Divide by increasing values of r
	}

	return result; // Return the result
}

// Function to compute the greatest common divisor (GCD) of two numbers
uint64_t gcd(uint64_t m, uint64_t n) {
	uint64_t temp;

	// Euclidean algorithm to find GCD
	while (m % n != 0) {
		temp = n;
		n = m % n; // Update n to the remainder
		m = temp; // Update m to the previous n
	}

	return n; // Return the GCD
}

// Main function to execute the program
int main() {
	const std::string patternBase = "keyence"; // Define the pattern to search for
	std::string top, bottom; // Buffers to hold split parts of the pattern
	std::string S; // Buffer to hold the input string

	// Read the input string
	std::cin >> S;

	const size_t len = S.length(); // Get the length of the input string
	bool found = false; // Flag to indicate if the pattern is found

	// Loop through each possible split point in the pattern
	for (size_t offset = 0; offset < patternBase.length(); offset++) {
		// Split the pattern into top and bottom parts
		top = patternBase.substr(0, offset);
		bottom = patternBase.substr(offset);

		// Search for the top part in the input string
		size_t topPos = S.find(top);
		if (topPos != std::string::npos) {
			// Search for the bottom part after the found top part
			size_t bottomPos = strrstr(S.substr(topPos + offset), bottom).length();
			if (bottomPos != std::string::npos) {
				size_t sepCount = 0; // Counter for separators

				// Count the number of separators between top and bottom parts
				if (topPos != 0) {
					sepCount++; // Increment if there's text before the top part
				}
				if (topPos + offset + bottomPos != len) {
					sepCount++; // Increment if there's text between top and bottom parts
				}
				if (topPos + offset + bottomPos != len) {
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
	std::cout << (found ? "YES" : "NO") << std::endl;

	return 0; // Return success
}
