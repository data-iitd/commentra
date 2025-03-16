#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// getScanner initializes a new scanner for reading from a file.
FILE *getScanner(FILE *fp) {
	FILE *scanner = fp;
	return scanner;
}

// getNextString reads the next word from the scanner.
char *getNextString(FILE *scanner) {
	char *word = malloc(sizeof(char) * 100);
	fscanf(scanner, "%s", word);
	return word;
}

// getNextInt converts the next word from the scanner to an integer.
int getNextInt(FILE *scanner) {
	int i;
	fscanf(scanner, "%d", &i);
	return i;
}

// Main function to compute the minimum number of matrix multiplications.
int main() {
	FILE *fp = stdin;
	if (argc > 1) {
		fp = fopen(argv[1], "r");
	}

	// Initialize scanner and writer for standard input and output.
	FILE *scanner = getScanner(fp);
	FILE *writer = stdout;

	// Read the number of matrices.
	int n = getNextInt(scanner);

	// Initialize arrays for matrix dimensions and dynamic programming.
	int *mm = malloc(sizeof(int) * (n + 1));
	int **dp = malloc(sizeof(int *) * (n + 1));
	for (int i = 0; i <= n; i++) {
		dp[i] = malloc(sizeof(int) * (n + 1));
	}

	// Read matrix dimensions into the mm array.
	for (int i = 0; i < n; i++) {
		mm[i] = getNextInt(scanner);
		mm[i + 1] = getNextInt(scanner);
	}

	// Use dynamic programming to compute the minimum number of multiplications.
	for (int l = 2; l <= n; l++) {
		for (int i = 1; i <= n - l + 1; i++) {
			int j = i + l - 1;
			for (int k = i; k <= j - 1; k++) {
				int d = dp[i][k] + dp[k + 1][j] + mm[i - 1] * mm[k] * mm[j];
				if (dp[i][j] == 0 || dp[i][j] > d) {
					dp[i][j] = d;
				}
			}
		}
	}

	// Print the result to the standard output.
	fprintf(writer, "%d\n", dp[1][n]);

	// Flush the writer to ensure all data is written to the output.
	fflush(writer);

	// Free memory.
	free(mm);
	for (int i = 0; i <= n; i++) {
		free(dp[i]);
	}
	free(dp);

	return 0;
}

