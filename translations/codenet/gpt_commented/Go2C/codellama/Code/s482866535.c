#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// getScanner initializes a new scanner for reading input from the provided file pointer.
void getScanner(FILE *fp) {
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	while ((read = getline(&line, &len, fp)) != -1) {
		printf("%s", line);
	}
	free(line);
}

// getNextString retrieves the next string from the scanner.
char *getNextString(FILE *fp) {
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	while ((read = getline(&line, &len, fp)) != -1) {
		return line;
	}
	free(line);
	return NULL;
}

// getNextInt retrieves the next integer from the scanner.
int getNextInt(FILE *fp) {
	char *line = getNextString(fp);
	int i = atoi(line);
	free(line);
	return i;
}

int main() {
	// Determine the input source: standard input or a file specified as a command-line argument.
	FILE *fp = stdin;
	if (argc > 1) {
		fp = fopen(argv[1], "r"); // Open the file if a filename is provided.
	}

	// Initialize the scanner for reading input and a writer for output.
	getScanner(fp);
	FILE *writer = fopen("output.txt", "w");

	// Read the number of elements.
	int n = getNextInt(fp);
	int *mm = (int *)malloc((n+1)*sizeof(int)); // Create a slice to hold the input values.
	int **dp = (int **)malloc((n+1)*sizeof(int *)); // Create a 2D slice for dynamic programming.

	// Initialize the 2D slice for dynamic programming.
	for (int i = 0; i <= n; i++) {
		dp[i] = (int *)malloc((n+1)*sizeof(int)); // Each entry is initialized to zero by default.
	}

	// Read the input values into the mm slice.
	for (int i = 0; i < n; i++) {
		mm[i] = getNextInt(fp); // Read the first value.
		mm[i+1] = getNextInt(fp); // Read the second value.
	}

	// Perform dynamic programming to calculate the minimum cost.
	for (int l = 2; l <= n; l++) { // l is the length of the subproblem.
		for (int i = 1; i <= n-l+1; i++) { // i is the starting index of the subproblem.
			int j = i + l - 1; // j is the ending index of the subproblem.
			for (int k = i; k <= j-1; k++) { // k is the partition point.
				// Calculate the cost of multiplying the matrices.
				int d = dp[i][k] + dp[k+1][j] + mm[i-1]*mm[k]*mm[j];
				// Update the dp table with the minimum cost found.
				if (dp[i][j] == 0 || dp[i][j] > d) {
					dp[i][j] = d;
				}
			}
		}
	}

	// Output the minimum cost of multiplying the entire sequence of matrices.
	fprintf(writer, "%d\n", dp[1][n]);

	// Flush the writer to ensure all output is written.
	fflush(writer);

	// Close the writer.
	fclose(writer);

	// Close the file if it was opened.
	if (fp != stdin) {
		fclose(fp);
	}

	// Free the memory allocated for the slices.
	free(mm);
	for (int i = 0; i <= n; i++) {
		free(dp[i]);
	}
	free(dp);

	return 0;
}

