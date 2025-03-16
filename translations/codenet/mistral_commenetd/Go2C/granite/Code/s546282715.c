
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to read the next word from the scanner
char* getNextWord(char** scanner) {
	char* word = malloc(100 * sizeof(char));
	sscanf(*scanner, "%s", word);
	*scanner += strlen(word) + 1;
	return word;
}

// Function to read the next integer from the scanner
int getNextInt(char** scanner) {
	int i;
	sscanf(*scanner, "%d", &i);
	*scanner += strlen(itoa(i)) + 1;
	return i;
}

// Main function
int main(int argc, char** argv) {
	// Open the standard input file if the command line argument is provided
	FILE* fp = stdin;
	if (argc > 1) {
		fp = fopen(argv[1], "r");
	}

	// Initialize the scanner and writer
	char input[1000000];
	fgets(input, 1000000, fp);
	char* scanner = input;
	FILE* writer = stdout;

	// Read the first two integers from the input
	int n = getNextInt(&scanner);
	int m = getNextInt(&scanner);

	// Initialize an associative array to store the elements
	int* aa = (int*)malloc(m * sizeof(int));
	// Read m elements and store them in the associative array
	for (int i = 0; i < m; i++) {
		aa[i] = getNextInt(&scanner);
	}

	// Initialize a slice of length n+1 for dynamic programming
	int* dp = (int*)malloc((n + 1) * sizeof(int));
	// Initialize the first element of the slice
	dp[0] = 1;

	// Iterate through the array from index 0 to n-1
	for (int i = 0; i < n; i++) {
		// Iterate through the prefix sum from i to i+2
		for (int ii = 1; ii <= 2 && i + ii <= n; ii++) {
			// Skip if the current index and its sum are already present in the associative array
			int found = 0;
			for (int j = 0; j < m; j++) {
				if (i + ii == aa[j]) {
					found = 1;
					break;
				}
			}
			if (found) {
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

	// Close the input and output files if necessary
	if (argc > 1) {
		fclose(fp);
	}
	fclose(writer);

	return 0;
}

