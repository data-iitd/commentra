#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// getNextWord reads the next word from the scanner.
char* getNextWord(FILE* fp) {
	static char word[100];
	fscanf(fp, "%s", word);
	return word;
}

// getNextInt reads the next word from the scanner and converts it to an integer.
int getNextInt(FILE* fp) {
	int i;
	fscanf(fp, "%d", &i);
	return i;
}

// main function starts here
int main(int argc, char* argv[]) {
	// Determine the input source based on command-line arguments
	FILE* fp = stdin;
	if (argc > 1) {
		fp = fopen(argv[1], "r");
	}

	// Create a new scanner to read from the determined input source
	// scanner := bufio.NewScanner(fp)
	// scanner.Split(bufio.ScanWords)

	// Create a writer to output the result
	// writer := bufio.NewWriter(os.Stdout)

	// Read the number of elements (n) and the number of restricted positions (m)
	int n = getNextInt(fp);
	int m = getNextInt(fp);

	// Create a map to store the restricted positions
	int aa[100000];
	memset(aa, 0, sizeof(aa));
	for (int i = 0; i < m; i++) {
		aa[getNextInt(fp)] = 1;
	}

	// Initialize the dynamic programming array
	int dp[100001];
	dp[0] = 1;

	// Fill the dynamic programming array based on restricted positions
	for (int i = 0; i < n; i++) {
		for (int ii = 1; ii <= 2 && i+ii <= n; ii++) {
			if (aa[i+ii]) {
				continue;
			}
			dp[i+ii] += dp[i];
			dp[i+ii] %= 1000000007;
		}
	}

	// Print the result
	printf("%d\n", dp[n]);

	// Flush the writer to ensure all data is written to the output
	// writer.Flush()

	// Close the input file
	if (argc > 1) {
		fclose(fp);
	}

	return 0;
}
