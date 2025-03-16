#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to read the next word from the scanner
char* getNextWord(char* line) {
	char* word = malloc(sizeof(char) * 100);
	int i = 0;
	while (line[i]!='' && line[i]!= '\n') {
		word[i] = line[i];
		i++;
	}
	word[i] = '\0';
	return word;
}

// Function to read the next integer from the scanner
int getNextInt(char* line) {
	char* word = getNextWord(line);
	int i = atoi(word);
	free(word);
	return i;
}

// Main function
int main() {
	// Open the standard input file if the command line argument is provided
	FILE* fp = fopen(argv[1], "r");
	if (fp == NULL) {
		fp = stdin;
	}

	// Initialize the scanner and writer
	char* line = malloc(sizeof(char) * 100);
	fgets(line, 100, fp);
	char* word = getNextWord(line);
	int n = atoi(word);
	free(word);
	fgets(line, 100, fp);
	word = getNextWord(line);
	int m = atoi(word);
	free(word);
	fgets(line, 100, fp);

	// Initialize an associative array to store the elements
	int* aa = malloc(sizeof(int) * m);
	// Read m elements and store them in the associative array
	for (int i = 0; i < m; i++) {
		word = getNextWord(line);
		aa[i] = atoi(word);
		free(word);
		fgets(line, 100, fp);
	}

	// Initialize a slice of length n+1 for dynamic programming
	int* dp = malloc(sizeof(int) * (n+1));
	// Initialize the first element of the slice
	dp[0] = 1;

	// Iterate through the array from index 0 to n-1
	for (int i = 0; i < n; i++) {
		// Iterate through the prefix sum from i to i+2
		for (int ii = 1; ii <= 2 && i+ii <= n; ii++) {
			// Skip if the current index and its sum are already present in the associative array
			int j = i + ii;
			int found = 0;
			for (int k = 0; k < m; k++) {
				if (aa[k] == j) {
					found = 1;
					break;
				}
			}
			if (found) {
				continue;
			}
			// Calculate the dynamic programming value for the current index
			dp[j] += dp[i];
			// Perform modulo operation to keep the value within the range of 10^9+7
			dp[j] %= 1000000007;
		}
	}

	// Print the final answer
	printf("%d\n", dp[n]);

	// Close the input file
	if (fp!= stdin) {
		fclose(fp);
	}

	// Free the memory
	free(line);
	free(aa);
	free(dp);

	return 0;
}

