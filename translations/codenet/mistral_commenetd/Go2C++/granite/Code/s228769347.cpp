
// C++ code to solve the problem
#include <bits/stdc++.h>
using namespace std;

// Function to read the next word as a string
string getNextString(FILE *fp) {
	char word[1000];
	fgets(word, 1000, fp);
	return string(word);
}

// Function to read the next integer from the input
int getNextInt(FILE *fp) {
	char word[1000];
	fgets(word, 1000, fp);
	return atoi(word);
}

// Function to read the next integer64 from the input
long long getNextInt64(FILE *fp) {
	char word[1000];
	fgets(word, 1000, fp);
	return atoll(word);
}

// Function to read the next uint64 from the input
unsigned long long getNextUint64(FILE *fp) {
	char word[1000];
	fgets(word, 1000, fp);
	return strtoull(word, NULL, 10);
}

// Function to read the next float64 from the input
double getNextFloat64(FILE *fp) {
	char word[1000];
	fgets(word, 1000, fp);
	return atof(word);
}

// Main function to solve the problem
int main() {
	// Initializing standard input and output file pointers
	FILE *fp = stdin;
	FILE *wfp = stdout;

	// If input file and output file are provided as command line arguments
	if (argc > 1) {
		// Open the input file
		fp = fopen(argv[1], "r");

		// If output file is provided, create it
		if (argc > 2) {
			wfp = fopen(argv[2], "w");
		}
	}

	// Read the number of elements in the array
	int n = getNextInt(fp);

	// Initialize a vector to store the elements
	vector<int> ll(n);

	// Read the elements of the array
	for (int i = 0; i < n; i++) {
		ll[i] = getNextInt(fp);
	}

	// Sort the vector in ascending order
	sort(ll.begin(), ll.end());

	// Initialize the answer variable to 0
	int ans = 0;

	// Iterate through all possible pairs of elements
	for (int i = 0; i < n - 2; i++) {
		// Iterate through all possible right pointers
		for (int j = i + 1; j < n - 1; j++) {
			// Initialize the left and right pointers for binary search
			int l = j + 1, r = n;

			// Binary search to find the index of the element greater than the sum of the current pair
			while (l < r) {
				int m = (l + r) / 2;
				if (ll[m] < ll[i] + ll[j]) {
					l = m + 1;
				} else {
					r = m;
				}
			}

			// Update the answer variable
			ans += l - (j + 1);
		}
	}

	// Write the answer to the output file
	fprintf(wfp, "%d\n", ans);

	// Close the input and output file pointers
	fclose(fp);
	fclose(wfp);

	return 0;
}

// "