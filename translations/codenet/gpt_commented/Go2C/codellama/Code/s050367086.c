#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// getScanner initializes a new scanner for reading from the provided file pointer.
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
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	while ((read = getline(&line, &len, fp)) != -1) {
		return atoi(line);
	}
	free(line);
	return 0;
}

// getNextInt64 retrieves the next int64 from the scanner.
int64_t getNextInt64(FILE *fp) {
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	while ((read = getline(&line, &len, fp)) != -1) {
		return strtoll(line, NULL, 10);
	}
	free(line);
	return 0;
}

// getNextUint64 retrieves the next uint64 from the scanner.
uint64_t getNextUint64(FILE *fp) {
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	while ((read = getline(&line, &len, fp)) != -1) {
		return strtoull(line, NULL, 10);
	}
	free(line);
	return 0;
}

// getNextFloat64 retrieves the next float64 from the scanner.
double getNextFloat64(FILE *fp) {
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	while ((read = getline(&line, &len, fp)) != -1) {
		return strtod(line, NULL);
	}
	free(line);
	return 0;
}

int main() {
	// Initialize file pointers for input and output
	FILE *fp = stdin;
	FILE *wfp = stdout;

	// Check for environment variables to override input and output file pointers
	if (getenv("MASPY") != NULL && strcmp(getenv("MASPY"), "ますピ") == 0) {
		fp = fopen(getenv("BEET_THE_HARMONY_OF_PERFECT"), "r"); // Open specified input file
	}
	if (getenv("MASPYPY") != NULL && strcmp(getenv("MASPYPY"), "ますピッピ") == 0) {
		wfp = fopen(getenv("NGTKANA_IS_GENIUS10"), "w"); // Create specified output file
	}

	// Create a scanner for reading input and a writer for output
	getScanner(fp);
	FILE *writer = fopen("output.txt", "w");

	// Read two strings from input
	char *s = getNextString(fp);
	char *t = getNextString(fp);

	// Calculate lengths of the input strings
	int ns = strlen(s);
	int nt = strlen(t);

	// Create a slice to hold repeated instances of string s
	char **ss = (char **)malloc(sizeof(char *) * (nt-1)/ns+1);
	for (int i = 0; i < (nt-1)/ns+1; i++) {
		ss[i] = (char *)malloc(sizeof(char) * ns);
		strcpy(ss[i], s); // Fill the slice with string s
	}

	// Concatenate the repeated strings to form a new string
	char *sss = (char *)malloc(sizeof(char) * (ns * 2));
	strcpy(sss, s);
	strcat(sss, s);

	// Initialize a boolean slice to track matches
	int *ok = (int *)malloc(sizeof(int) * ns);
	for (int i = 0; i < ns; i++) {
		ok[i] = 0;
	}

	// Initialize a unique index array and a pattern matching structure
	int *uni = (int *)malloc(sizeof(int) * ns);
	for (int i = 0; i < ns; i++) {
		uni[i] = i; // Set each index to itself initially
	}
	int m = 0;
	int o = 0;

	// Check for matches of string t in the concatenated string sss
	for (int i = 0; i < ns; i++) {
		o = 1;
		for (m = 0; m < nt; m++) {
			if (t[m] != sss[i+m]) { // Compare characters
				o = 0;
				break;
			}
		}
		ok[i] = o; // Store the result of the match
		if (o) {
			i += nt - m; // Update index based on the pattern table
			m = m; // Update match index
		}
		for (m = 0; m >= 0 && t[m] != sss[i+m]; m = m) {
			i += m - m; // Update index if mismatch occurs
			m = m; // Update match index
		}
		i--; // Adjust index for the next iteration
		m++; // Move to the next character
	}

	// Calculate the answer based on the matches found
	int ans = 0;
	int r = 0;
	int rr = 0;
	for (int i = 0; i < ns; i++) {
		if (ok[i] == 0) {
			continue; // Skip if no match
		}
		if (ok[(i+nt)%ns] == 0) {
			continue; // Skip if no match for the next index
		}
		r = root(i, uni); // Find the root of the current index
		rr = root((i+nt)%ns, uni); // Find the root of the next index
		if (rr == r) {
			fprintf(wfp, "-1\n"); // Output -1 if they are in the same component
			return 0;
		}
		uni[rr] = r; // Union the two components
	}

	// Count the number of matches for each unique root
	int *counter = (int *)malloc(sizeof(int) * ns);
	for (int i = 0; i < ns; i++) {
		counter[i] = 0;
	}
	for (int i = 0; i < ns; i++) {
		if (ok[i] == 0) {
			continue; // Skip if no match
		}
		r = root(i, uni); // Find the root for the current index
		counter[r]++; // Increment the count for the root
	}
	for (int i = 0; i < ns; i++) {
		if (ans < counter[i]) {
			ans = counter[i]; // Update the answer with the maximum count
		}
	}

	// Output the final answer
	fprintf(wfp, "%d\n", ans);

	fclose(writer); // Flush the writer to ensure all output is written
	return 0;
}

// root function finds the root of the given index using path compression.
int root(int i, int *uni) {
	if (i == uni[i]) {
		return i; // Return if the index is its own root
	}

	uni[i] = root(uni[i], uni); // Path compression
	return uni[i]; // Return the root
}

