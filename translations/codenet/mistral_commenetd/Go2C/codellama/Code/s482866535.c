
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to get a new scanner from a file pointer
void getScanner(FILE *fp) {
	char *buffer = (char *)malloc(500001 * sizeof(char));
	char *token = (char *)malloc(500001 * sizeof(char));
	int i = 0;
	while (fscanf(fp, "%s", token) != EOF) {
		buffer[i] = token;
		i++;
	}
	buffer[i] = '\0';
	printf("%s\n", buffer);
}

// Function to read the next string from the scanner
char *getNextString(char *buffer, int *i) {
	char *token = (char *)malloc(500001 * sizeof(char));
	int j = 0;
	while (buffer[*i] != ' ' && buffer[*i] != '\0') {
		token[j] = buffer[*i];
		j++;
		(*i)++;
	}
	token[j] = '\0';
	return token;
}

// Function to read the next integer from the scanner
int getNextInt(char *buffer, int *i) {
	char *token = getNextString(buffer, i);
	int j = atoi(token);
	return j;
}

// Main function to read input and process it
int main() {
	// Open the standard input stream if no file is provided as an argument
	FILE *fp = stdin;
	if (argc > 1) {
		// Open the file provided as an argument and use it as the input stream
		fp = fopen(argv[1], "r");
	}

	// Initialize a new scanner from the input stream
	char *buffer = (char *)malloc(500001 * sizeof(char));
	fgets(buffer, 500001, fp);
	int i = 0;

	// Read the number of test cases from the input
	int n = getNextInt(buffer, &i);

	// Initialize a slice to store the prefix sum of squares of elements
	int *mm = (int *)malloc((n + 1) * sizeof(int));

	// Initialize a 2D slice to store the dynamic programming table
	int **dp = (int **)malloc((n + 1) * sizeof(int *));
	for (int i = 0; i <= n; i++) {
		dp[i] = (int *)malloc((n + 1) * sizeof(int));
	}

	// Read the elements and their prefix sum of squares from the input
	for (int i = 0; i < n; i++) {
		// Read the next integer as the current element
		mm[i + 1] = getNextInt(buffer, &i);
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
	return 0;
}

