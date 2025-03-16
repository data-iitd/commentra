

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// getNextWord reads the next word from the scanner and returns it as a string.
char* getNextWord(char* line, int* index) {
	char* word = NULL;
	int i = *index;
	while (line[i]!= '\0' && line[i]!='') {
		i++;
	}
	if (line[i] == '\0') {
		word = malloc(sizeof(char) * (i - *index + 1));
		strncpy(word, line + *index, i - *index);
		word[i - *index] = '\0';
		*index = i + 1;
	} else {
		word = malloc(sizeof(char) * (i - *index + 2));
		strncpy(word, line + *index, i - *index);
		word[i - *index + 1] = '\0';
		*index = i + 2;
	}
	return word;
}

// getNextInt reads the next word from the scanner, converts it to an integer, and returns it.
int getNextInt(char* line, int* index) {
	char* word = getNextWord(line, index);
	int i = atoi(word);
	free(word);
	return i;
}

int main(int argc, char* argv[]) {
	// Set the input source to standard input; if a file is provided as an argument, open that file.
	FILE* fp = stdin;
	if (argc > 1) {
		fp = fopen(argv[1], "r");
	}

	// Read the first two integers, n and m, from the input.
	char line[10000];
	fgets(line, 10000, fp);
	int n = getNextInt(line, &n);
	int m = getNextInt(line, &m);

	// Initialize a map to store the positions that are blocked (not allowed).
	int* aa = malloc(sizeof(int) * m);
	for (int i = 0; i < m; i++) {
		// Read each blocked position and mark it in the map.
		aa[i] = getNextInt(line, &m);
	}

	// Create a dynamic programming array to store the number of ways to reach each position.
	int* dp = malloc(sizeof(int) * (n + 1));
	dp[0] = 1; // Base case: There is one way to be at the starting position (doing nothing).

	// Iterate through each position from 0 to n.
	for (int i = 0; i < n; i++) {
		// Check the next two positions (i+1 and i+2) to see if they can be reached.
		for (int ii = 1; ii <= 2 && i + ii <= n; ii++) {
			int j = i + ii;
			int ok = 0;
			for (int k = 0; k < m; k++) {
				if (aa[k] == j) {
					ok = 1;
					break;
				}
			}
			if (ok) {
				continue;
			}
			// Update the number of ways to reach position i+ii based on the current position i.
			dp[j] += dp[i];
			dp[j] %= 1000000007; // Ensure the result stays within the modulo limit.
		}
	}

	// Output the total number of ways to reach position n.
	printf("%d\n", dp[n]);

	// Close the input file.
	if (fp!= stdin) {
		fclose(fp);
	}

	// Free the dynamically allocated memory.
	free(aa);
	free(dp);
}

