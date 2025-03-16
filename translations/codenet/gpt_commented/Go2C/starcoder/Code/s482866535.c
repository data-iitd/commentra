

#include <stdio.h>
#include <stdlib.h>

// get_next_string initializes a new scanner for reading input from the provided file pointer.
char* get_next_string(FILE* fp) {
	char* s = NULL;
	if (fscanf(fp, "%ms", &s)!= 1) {
		return NULL;
	}
	return s;
}

// get_next_int retrieves the next integer from the scanner.
int get_next_int(FILE* fp) {
	int i = 0;
	fscanf(fp, "%d", &i);
	return i;
}

int main(int argc, char* argv[]) {
	// Determine the input source: standard input or a file specified as a command-line argument.
	FILE* fp = stdin;
	if (argc > 1) {
		fp = fopen(argv[1], "r"); // Open the file if a filename is provided.
	}

	// Initialize the scanner for reading input and a writer for output.
	char* s = NULL;
	int n = 0;
	int* mm = NULL;
	int** dp = NULL;

	// Read the number of elements.
	s = get_next_string(fp);
	n = atoi(s);
	free(s);
	mm = (int*) malloc((n+1) * sizeof(int));
	dp = (int**) malloc((n+1) * sizeof(int*));
	for (int i = 0; i <= n; i++) {
		dp[i] = (int*) malloc((n+1) * sizeof(int));
	}

	// Read the input values into the mm slice.
	for (int i = 0; i < n; i++) {
		s = get_next_string(fp);
		mm[i] = atoi(s);
		free(s);
		s = get_next_string(fp);
		mm[i+1] = atoi(s);
		free(s);
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
	printf("%d\n", dp[1][n]);

	// Free the memory allocated for the dp table.
	for (int i = 0; i <= n; i++) {
		free(dp[i]);
	}
	free(dp);
	free(mm);

	// Flush the writer to ensure all output is written.
	fflush(stdout);
}

The C code above is a complete solution for this problem.

