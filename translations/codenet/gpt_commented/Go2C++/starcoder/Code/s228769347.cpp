#include <bits/stdc++.h>

using namespace std;

// getScanner initializes a new scanner for reading from the provided file pointer.
auto getScanner(FILE* fp) {
	return make_shared<stringstream>(stringstream(ios_base::in));
}

// getNextString reads the next word from the scanner and returns it as a string.
auto getNextString(stringstream* scanner) {
	return getline(*scanner, *scanner->rdbuf()).str();
}

// getNextInt converts the next word from the scanner to an integer and returns it.
auto getNextInt(stringstream* scanner) {
	int i;
	(*scanner) >> i;
	return i;
}

// getNextInt64 converts the next word from the scanner to an int64 and returns it.
auto getNextInt64(stringstream* scanner) {
	int64_t i;
	(*scanner) >> i;
	return i;
}

// getNextUint64 converts the next word from the scanner to a uint64 and returns it.
auto getNextUint64(stringstream* scanner) {
	uint64_t i;
	(*scanner) >> i;
	return i;
}

// getNextFloat64 converts the next word from the scanner to a float64 and returns it.
auto getNextFloat64(stringstream* scanner) {
	double i;
	(*scanner) >> i;
	return i;
}

int main() {
	auto fp = fopen(getenv("INPUT_PATH"), "r"); // Open the input file if provided.
	auto wfp = fopen(getenv("OUTPUT_PATH"), "w"); // Create the output file if provided.
	auto scanner = getScanner(fp); // Initialize the scanner for input.
	auto writer = make_shared<ostream>(wfp); // Create a buffered writer for output.

	int n = getNextInt(scanner); // Read the number of integers.
	vector<int> ll(n); // Create a vector to hold the integers.

	// Read n integers from the input.
	for (int i = 0; i < n; i++) {
		ll[i] = getNextInt(scanner); // Populate the vector with integers.
	}

	sort(ll.begin(), ll.end()); // Sort the vector of integers.

	int ans = 0; // Initialize the answer counter.
	// Iterate through pairs of integers to find valid triplets.
	for (int i = 0; i < n - 2; i++) {
		for (int j = i + 1; j < n - 1; j++) {
			int l = j + 1; // Start searching for the third element after the second element.
			int r = n; // Set the right boundary for binary search.
			// Perform binary search to find the count of valid third elements.
			while (l < r) {
				int m = (l + r) >> 1; // Calculate the middle index.
				if (ll[m] < ll[i] + ll[j]) { // Check if the sum of the first two is greater than the middle element.
					l = m + 1; // Move the left boundary up.
					continue;
				}
				r = m; // Move the right boundary down.
			}
			// Count the number of valid third elements.
			ans += l - (j + 1); // Update the answer with the count of valid triplets.
		}
	}
	(*writer) << ans << endl; // Print the result to the output.

	fclose(fp); // Close the input file.
	fclose(wfp); // Close the output file.
}

