
#include <stdio.h>
#include <stdlib.h>

// getNextWord reads the next word from the scanner.
char* getNextWord(char** scanner) {
	char* word = malloc(256 * sizeof(char));
	sscanf(*scanner, "%s", word);
	*scanner += strlen(word) + 1;
	return word;
}

// getNextInt reads the next word from the scanner and converts it to an integer.
int getNextInt(char** scanner) {
	int i;
	sscanf(*scanner, "%d", &i);
	*scanner += strlen(itoa(i)) + 1;
	return i;
}

// main function starts here
int main(int argc, char** argv) {
	// Determine the input source based on command-line arguments
	FILE* fp = stdin;
	if (argc > 1) {
		fp = fopen(argv[1], "r");
	}

	// Create a scanner to read from the determined input source
	char input[1000000];
	fgets(input, 1000000, fp);
	char* scanner = input;

	// Create a writer to output the result
	FILE* writer = stdout;

	// Read the number of elements (n) and the number of restricted positions (m)
	int n = getNextInt(&scanner);
	int m = getNextInt(&scanner);

	// Create a map to store the restricted positions
	int* aa = (int*)malloc(m * sizeof(int));
	for (int i = 0; i < m; i++) {
		aa[i] = getNextInt(&scanner);
	}

	// Initialize the dynamic programming array
	int* dp = (int*)malloc((n + 1) * sizeof(int));
	dp[0] = 1;

	// Fill the dynamic programming array based on restricted positions
	for (int i = 0; i < n; i++) {
		for (int ii = 1; ii <= 2 && i + ii <= n; ii++) {
			int ok = 0;
			for (int j = 0; j < m; j++) {
				if (i + ii == aa[j]) {
					ok = 1;
					break;
				}
			}
			if (ok) {
				continue;
			}
			dp[i + ii] += dp[i];
			dp[i + ii] %= 1000000007;
		}
	}

	// Print the result
	fprintf(writer, "%d\n", dp[n]);

	// Flush the writer to ensure all data is written to the output
	fflush(writer);

	// Free memory
	free(dp);
	free(aa);

	return 0;
}

