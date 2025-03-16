#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to get a new scanner from a file pointer
char* getScanner(FILE* fp) {
	char* buffer = (char*)malloc(sizeof(char) * 500001);
	return fgets(buffer, 500000, fp);
}

// Function to read the next string from the scanner
char* getNextString(FILE* fp) {
	char* buffer = (char*)malloc(sizeof(char) * 500001);
	return fgets(buffer, 500000, fp);
}

// Function to read the next integer from the scanner
int getNextInt(FILE* fp) {
	char* buffer = (char*)malloc(sizeof(char) * 500001);
	return atoi(fgets(buffer, 500000, fp));
}

// Main function to read input and process it
int main() {
	// Open the standard input stream if no file is provided as an argument
	FILE* fp = stdin;
	if (argc > 1) {
		// Open the file provided as an argument and use it as the input stream
		fp = fopen(argv[1], "r");
	}

	// Initialize a new scanner from the input stream
	char* buffer = (char*)malloc(sizeof(char) * 500001);
	char* scanner = getScanner(fp);

	// Read the number of test cases from the input
	int n = getNextInt(fp);

	// Initialize a slice to store the prefix sum of squares of elements
	int* mm = (int*)malloc(sizeof(int) * (n + 1));

	// Initialize a 2D slice to store the dynamic programming table
	int** dp = (int**)malloc(sizeof(int*) * (n + 1));
	for (int i = 0; i <= n; i++) {
		dp[i] = (int*)malloc(sizeof(int) * (n + 1));
	}

	// Read the elements and their prefix sum of squares from the input
	for (int i = 0; i < n; i++) {
		// Read the next integer as the current element
		mm[i + 1] = getNextInt(fp);
		// Read the next integer as the next element's prefix sum of square
		mm[i + 1] += mm[i] * mm[i];
	}

	// Process the dynamic programming table for all subarrays of given size
	for (int l = 2; l <= n; l++) {
		for (int i = 1; i <= n - l + 1; i++) {
			int j = i + l - 1;
			// Iterate through all subarrays of the current subarray
			for (int k = i; k <= j - 1; k++) {
				// Calculate the sum of squares of elements in the current subarray
				int d = dp[i][k] + dp[k + 1][j] + mm[i - 1] * mm[k] * mm[j];
				// Update the dynamic programming table if a larger sum is found
				if (dp[i][j] == 0 || dp[i][j] > d) {
					dp[i][j] = d;
				}
			}
		}
	}

	// Print the result for the given input
	printf("%d\n", dp[1][n]);

	// End of the code


