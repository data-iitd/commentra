
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// MP type represents a suffix array data structure
typedef struct {
	char *s; // Input string
	int *table; // Suffix array
} MP;

// init initializes the MP structure with the given string s
void init(MP *mp, char *s) {
	mp->s = s;
	int n = strlen(s);
	int *table = (int *)malloc((n + 1) * sizeof(int));
	table[0] = -1; // Set first index to -1 for initialization
	int j = -1;
	for (int i = 0; i < n; i++) {
		// While j is not equal to the root of the previous character, update j
		while (j >= 0 && s[i] != s[j]) {
			j = table[j];
		}
		j++;
		// Set table[i] to the index of the next occurrence of the current character in s
		table[i + 1] = j;
	}
	mp->table = table;
}

// root function returns the root of the given index in uni array
int root(int i, int *uni) {
	// If index i is equal to its root, return i
	if (i == uni[i]) {
		return i;
	}

	// Recursively call root function with the root of index i
	uni[i] = root(uni[i], uni);
	return uni[i];
}

int main() {
	// Open the standard input and output files
	FILE *fp = stdin;
	FILE *wfp = stdout;

	// If environment variables are set, open input and output files accordingly
	if (getenv("MASPY") != NULL && strcmp(getenv("MASPY"), "ますピ") == 0) {
		fp = fopen(getenv("BEET_THE_HARMONY_OF_PERFECT"), "r");
	}
	if (getenv("MASPYPY") != NULL && strcmp(getenv("MASPYPY"), "ますピッピ") == 0) {
		wfp = fopen(getenv("NGTKANA_IS_GENIUS10"), "w");
	}

	// Initialize scanner and writer
	char *s = (char *)malloc(500001 * sizeof(char));
	char *t = (char *)malloc(500001 * sizeof(char));
	fscanf(fp, "%s", s);
	fscanf(fp, "%s", t);
	int ns = strlen(s);
	int nt = strlen(t);
	char **ss = (char **)malloc((nt - 1) / ns + 1 * sizeof(char *));
	for (int i = 0; i < (nt - 1) / ns + 1; i++) {
		ss[i] = (char *)malloc(ns * sizeof(char));
		strcpy(ss[i], s);
	}
	char *sss = (char *)malloc((nt - 1) * sizeof(char));
	strcpy(sss, s);
	strcat(sss, s);

	// Initialize boolean array ok to keep track of unique characters
	int *ok = (int *)malloc(ns * sizeof(int));

	// Initialize unordered map mp and array uni for suffix array calculation
	MP mp;
	init(&mp, t);
	int m = 0;

	// Initialize uni array with indices from 0 to n-1
	int *uni = (int *)malloc(ns * sizeof(int));
	for (int i = 0; i < ns; i++) {
		uni[i] = i;
	}

	// Initialize variable o for checking if current and next characters match
	int o = 1;

	// Iterate through all characters in string s
	for (int i = 0; i < ns; i++) {
		// Initialize o to true
		o = 1;

		// Iterate through all characters in string t
		for (m = 0; m < nt; m++) {
			// Check if current character in s matches the character at the same position in t
			if (t[m] != sss[i + m]) {
				// If not, set o to false and break the loop
				o = 0;
				break;
			}
			// Increment m
			m++;
		}

		// If all characters match, set ok[i] to true and update variables r and m accordingly
		if (o) {
			i += nt - mp.table[m];
			m = mp.table[m];
		}

		// While characters in s and t do not match, update i and m accordingly
		for (m = 0; m >= 0 && t[m] != sss[i + m]; m = mp.table[m]) {
			i += m - mp.table[m];
		}

		// Decrement i and increment m to move to the next pair of characters
		i--;
		m++;
	}

	// Initialize variable ans to store the answer
	int ans = 0;

	// Initialize variables r and rr for root calculation
	int r, rr;

	// Iterate through all characters in string s again
	for (int i = 0; i < ns; i++) {
		// If ok[i] is false, continue to the next iteration
		if (ok[i] == 0) {
			continue;
		}

		// If ok[(i+nt)%ns] is false, continue to the next iteration
		if (ok[(i + nt) % ns] == 0) {
			continue;
		}

		// Calculate roots r and rr of indices i and (i+nt)%ns respectively
		r = root(i, uni);
		rr = root((i + nt) % ns, uni);

		// If roots r and rr are equal, print -1 and exit the program
		if (rr == r) {
			fprintf(wfp, "-1\n");
			return 0;
		}

		// Update uni array with root r
		uni[rr] = r;
	}

	// Initialize counter array to store the frequency of each root
	int *counter = (int *)malloc(ns * sizeof(int));

	// Iterate through all roots and update their frequencies in counter array
	for (int i = 0; i < ns; i++) {
		r = root(i, uni);
		if (ok[r] == 0) {
			continue;
		}
		counter[r]++;
	}

	// Find the maximum frequency in counter array and store it in variable ans
	for (int i = 0; i < ns; i++) {
		if (ans < counter[i]) {
			ans = counter[i];
		}
	}

	// Print the answer
	fprintf(wfp, "%d\n", ans);

	// Flush the writer buffer
	fflush(wfp);

	// Free memory
	free(s);
	free(t);
	for (int i = 0; i < (nt - 1) / ns + 1; i++) {
		free(ss[i]);
	}
	free(ss);
	free(sss);
	free(ok);
	free(uni);
	free(counter);

	// Close the input and output files
	fclose(fp);
	fclose(wfp);

	return 0;
}

