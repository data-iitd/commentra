
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// getScanner initializes a new Scanner to read from a file pointer.
// It sets the split function to ScanWords and buffers to 500001 bytes.
void getScanner(FILE *fp) {
	char *buffer = (char *)malloc(500001);
	fscanf(fp, "%s", buffer);
	free(buffer);
}

// getNextString reads the next token from the Scanner and returns it as a string.
char *getNextString(FILE *fp) {
	char *buffer = (char *)malloc(500001);
	fscanf(fp, "%s", buffer);
	return buffer;
}

// getNextInt reads the next token as a string, converts it to an integer, and returns it.
int getNextInt(FILE *fp) {
	char *buffer = (char *)malloc(500001);
	fscanf(fp, "%s", buffer);
	int i = atoi(buffer);
	free(buffer);
	return i;
}

// getNextInt64 reads the next token as a string, converts it to an int64, and returns it.
int64_t getNextInt64(FILE *fp) {
	char *buffer = (char *)malloc(500001);
	fscanf(fp, "%s", buffer);
	int64_t i = atoll(buffer);
	free(buffer);
	return i;
}

// getNextUint64 reads the next token as a string, converts it to a uint64, and returns it.
uint64_t getNextUint64(FILE *fp) {
	char *buffer = (char *)malloc(500001);
	fscanf(fp, "%s", buffer);
	uint64_t i = atoll(buffer);
	free(buffer);
	return i;
}

// getNextFloat64 reads the next token as a string, converts it to a float64, and returns it.
float64_t getNextFloat64(FILE *fp) {
	char *buffer = (char *)malloc(500001);
	fscanf(fp, "%s", buffer);
	float64_t i = atof(buffer);
	free(buffer);
	return i;
}

// main function handles file input/output based on command-line arguments.
// It reads integers from the specified file or standard input, sorts them,
// and calculates the number of valid triplets (i, j, m) where i < j < m and ll[m] < ll[i] + ll[j].
int main(int argc, char *argv[]) {
	FILE *fp = stdin;
	FILE *wfp = stdout;

	// Check if file paths are provided as command-line arguments.
	if (argc > 1) {
		fp = fopen(argv[1], "r");
		if (argc > 2) {
			wfp = fopen(argv[2], "w");
		}
	}

	getScanner(fp);

	// Read the number of elements.
	int n = getNextInt(fp);
	int *ll = (int *)malloc(n * sizeof(int));

	// Read n integers into the slice ll.
	for (int i = 0; i < n; i++) {
		ll[i] = getNextInt(fp);
	}

	// Sort the slice ll.
	qsort(ll, n, sizeof(int), compare);

	// Initialize the answer variable.
	int ans = 0;

	// Iterate through possible triplets (i, j, m) where i < j < m.
	for (int i = 0; i < n-2; i++) {
		for (int j = i + 1; j < n-1; j++) {
			int l = j + 1;
			int r = n;
			while (l < r) {
				int m = (l + r) >> 1;
				if (ll[m] < ll[i]+ll[j]) {
					l = m + 1;
					continue;
				}
				r = m;
			}

			// Add the number of valid m's to the answer.
			ans += l - (j + 1);
		}
	}

	// Print the final answer to the standard output.
	fprintf(wfp, "%d\n", ans);

	// Flush the writer to ensure all data is written to the file or standard output.
	fflush(wfp);

	// Free the memory allocated for the slice ll.
	free(ll);

	// Close the file pointers.
	fclose(fp);
	fclose(wfp);

	return 0;
}

int compare(const void *a, const void *b) {
	return *(int *)a - *(int *)b;
}

