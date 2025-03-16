#include <stdio.h>
#include <stdlib.h>

// get_scanner initializes a new scanner for reading from a file.
FILE *get_scanner(FILE *fp) {
	FILE *scanner = malloc(sizeof(FILE));
	*scanner = *fp;
	return scanner;
}

// get_next_string reads the next word from the scanner.
char *get_next_string(FILE *scanner) {
	char *word = malloc(sizeof(char) * 500001);
	fscanf(scanner, "%s", word);
	return word;
}

// get_next_int converts the next word from the scanner to an integer.
int get_next_int(FILE *scanner) {
	int i;
	fscanf(scanner, "%d", &i);
	return i;
}

// main function to compute the minimum number of matrix multiplications.
int main() {
	FILE *fp = stdin;
	if (argc > 1) {
		fp = fopen(argv[1], "r");
	}

	// Initialize scanner and writer for standard input and output.
	FILE *scanner = get_scanner(fp);
	FILE *writer = stdout;

	// Read the number of matrices.
	int n = get_next_int(scanner);

	// Initialize arrays for matrix dimensions and dynamic programming.
	int *mm = malloc(sizeof(int) * (n + 1));
	int **dp = malloc(sizeof(int *) * (n + 1));
	for (int i = 0; i <= n; i++) {
		dp[i] = malloc(sizeof(int) * (n + 1));
	}

	// Read matrix dimensions into the mm array.
	for (int i = 0; i < n; i++) {
		mm[i] = get_next_int(scanner);
		mm[i + 1] = get_next_int(scanner);
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
}

