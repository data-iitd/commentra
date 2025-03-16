#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>

using namespace std;

// Define constants
#define N_MAX (100)
#define P_MAX (100)
#define DP_ARRAY_SIZE (N_MAX * P_MAX / 32 + 1)

// Define helper functions
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define ABS(a) ((a) < 0 ? -(a) : (a))
#define ABSS(a, b) ((a) > (b) ? (a) - (b) : (b) - (a))

// Function to find the last occurrence of a substring in a string
string strrstr(const string &string, const string &pattern) {
	size_t offset = 0;
	string lastP = "";

	string searchResult;
	while ((searchResult = string.substr(offset).find(pattern)) != string::npos && string[offset] != '\0') {
		lastP = searchResult;
		offset++;
	}

	return lastP;
}

// Function to compare two pointers for qsort
int compare_f(const void *a, const void *b) {
	return *((size_t *)a) < *((size_t *)b) ? -1 : 1;
}

// Function to calculate the number of combinations of n items taken r at a time
size_t comb(const size_t n, const size_t r) {
	size_t result = 1;

	for (size_t i = 0; i < r; i++) {
		result *= n - i;
		result /= i + 1;
	}

	return result;
}

// Function to find the greatest common divisor of two numbers
uint64_t gcd(uint64_t m, uint64_t n)
{
	uint64_t temp;

	while (m%n != 0) {
		temp = n;
		n = m % n;
		m = temp;
	}

	return n;
}

int main(void) {
	// Define pattern base string
	const string patternBase = "keyence";
	string top, bottom;
	string S;

	// Read input string from standard input
	cin >> S;

	// Calculate length of input string
	const size_t len = S.length();
	bool found = false;

	// Loop through each character in pattern base string
	for (size_t offset = 0; offset < patternBase.length(); offset++) {
		// Copy substring up to current character to top variable
		top = patternBase.substr(0, offset);

		// Copy substring from current character to end of pattern base string to bottom variable
		bottom = patternBase.substr(offset);

		// Search for top substring in input string
		size_t topPos = S.find(top);

		// If top substring is found
		if (topPos != string::npos) {
			// Search for bottom substring after top substring in input string
			size_t bottomPos = S.substr(topPos + top.length()).find(bottom);

			// If bottom substring is found
			if (bottomPos != string::npos) {
				// Calculate number of separators between top and bottom substrings
				size_t sepCount = 0;

				// If topPos is not the first position in S
				if (topPos != 0) {
					sepCount++;
				}

				// If topPos + top.length() is not the same as bottomPos
				if (topPos + top.length() != bottomPos) {
					sepCount++;
				}

				// If bottomPos + bottom.length() is not the end of S
				if (bottomPos + bottom.length() != S.length()) {
					sepCount++;
				}

				// If number of separators is less than or equal to 1
				if (sepCount <= 1) {
					found = true;
					break;
				}
			}
		}
	}

	// Print output based on whether pattern is found or not
	cout << (found ? "YES" : "NO") << endl;

	return 0;
}
