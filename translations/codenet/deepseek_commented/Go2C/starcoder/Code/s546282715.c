#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// getNextWord reads the next word from the scanner.
char *getNextWord(char *s, int *i) {
	while (s[*i] =='') {
		(*i)++;
	}
	char *start = s + *i;
	while (s[*i]!='' && s[*i]!= '\n') {
		(*i)++;
	}
	s[*i] = '\0';
	(*i)++;
	return start;
}

// getNextInt reads the next word from the scanner and converts it to an integer.
int getNextInt(char *s, int *i) {
	char *start = getNextWord(s, i);
	return atoi(start);
}

// main function starts here
int main(int argc, char *argv[]) {
	// Determine the input source based on command-line arguments
	FILE *fp = stdin;
	if (argc > 1) {
		fp = fopen(argv[1], "r");
	}

	// Create a new scanner to read from the determined input source
	char s[100000];
	int i = 0;
	char *start = getNextWord(s, &i);

	// Create a writer to output the result
	FILE *writer = stdout;

	// Read the number of elements (n) and the number of restricted positions (m)
	int n = atoi(start);
	int m = getNextInt(s, &i);

	// Create a map to store the restricted positions
	int *aa = (int *) malloc(sizeof(int) * m);
	for (int ii = 0; ii < m; ii++) {
		aa[ii] = getNextInt(s, &i);
	}

	// Initialize the dynamic programming array
	int *dp = (int *) malloc(sizeof(int) * (n + 1));
	dp[0] = 1;

	// Fill the dynamic programming array based on restricted positions
	for (int i = 0; i < n; i++) {
		for (int ii = 1; ii <= 2 && i + ii <= n; ii++) {
			int ok = 0;
			for (int iii = 0; iii < m; iii++) {
				if (i + ii == aa[iii]) {
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

	// Close the input and output files
	if (fp!= stdin) {
		fclose(fp);
	}
	if (writer!= stdout) {
		fclose(writer);
	}

	// Free the allocated memory
	free(aa);
	free(dp);
}

