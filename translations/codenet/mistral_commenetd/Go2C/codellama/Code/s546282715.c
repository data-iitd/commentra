#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to read the next word from the scanner
char* getNextWord(FILE* fp) {
	char* word = (char*)malloc(sizeof(char) * 1000);
	fscanf(fp, "%s", word);
	return word;
}

// Function to read the next integer from the scanner
int getNextInt(FILE* fp) {
	int i;
	fscanf(fp, "%d", &i);
	return i;
}

// Main function
int main() {
	// Open the standard input file if the command line argument is provided
	FILE* fp = stdin;
	if (argc > 1) {
		fp = fopen(argv[1], "r");
	}

	// Initialize the scanner and writer
	FILE* scanner = fp;
	FILE* writer = stdout;

	// Read the first two integers from the input
	int n = getNextInt(scanner);
	int m = getNextInt(scanner);

	// Initialize an associative array to store the elements
	int* aa = (int*)malloc(sizeof(int) * 1000);
	// Read m elements and store them in the associative array
	for (int i = 0; i < m; i++) {
		aa[i] = getNextInt(scanner);
	}

	// Initialize a slice of length n+1 for dynamic programming
	int* dp = (int*)malloc(sizeof(int) * (n + 1));
	// Initialize the first element of the slice
	dp[0] = 1;

	// Iterate through the array from index 0 to n-1
	for (int i = 0; i < n; i++) {
		// Iterate through the prefix sum from i to i+2
		for (int ii = 1; ii <= 2 && i + ii <= n; ii++) {
			// Skip if the current index and its sum are already present in the associative array
			if (aa[i + ii] == 1) {
				continue;
			}
			// Calculate the dynamic programming value for the current index
			dp[i + ii] += dp[i];
			// Perform modulo operation to keep the value within the range of 10^9+7
			dp[i + ii] %= 1000000007;
		}
	}

	// Print the final answer
	fprintf(writer, "%d\n", dp[n]);

	// Flush the writer buffer
	fflush(writer);

	// Free the memory allocated for the associative array
	free(aa);
	// Free the memory allocated for the dynamic programming slice
	free(dp);

	// Close the file pointer
	fclose(fp);

	return 0;
}

