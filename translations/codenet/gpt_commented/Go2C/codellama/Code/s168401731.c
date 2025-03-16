#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// getScanner initializes a new scanner for the provided file pointer.
// It sets the scanner to split input by words and allocates a buffer size.
void getScanner(FILE *fp) {
	char *buffer = (char *)malloc(500001 * sizeof(char));
	fscanf(fp, "%s", buffer);
	free(buffer);
}

// getNextString retrieves the next string from the scanner.
char *getNextString(FILE *fp) {
	char *buffer = (char *)malloc(500001 * sizeof(char));
	fscanf(fp, "%s", buffer);
	return buffer;
}

// getNextInt converts the next string from the scanner to an integer.
int getNextInt(FILE *fp) {
	char *buffer = getNextString(fp);
	int i = atoi(buffer);
	free(buffer);
	return i;
}

// getNextInt64 converts the next string from the scanner to a 64-bit integer.
int64_t getNextInt64(FILE *fp) {
	char *buffer = getNextString(fp);
	int64_t i = strtoll(buffer, NULL, 10);
	free(buffer);
	return i;
}

// getNextUint64 converts the next string from the scanner to an unsigned 64-bit integer.
uint64_t getNextUint64(FILE *fp) {
	char *buffer = getNextString(fp);
	uint64_t i = strtoull(buffer, NULL, 10);
	free(buffer);
	return i;
}

// getNextFloat64 converts the next string from the scanner to a float64.
double getNextFloat64(FILE *fp) {
	char *buffer = getNextString(fp);
	double i = strtod(buffer, NULL);
	free(buffer);
	return i;
}

int main() {
	// Initialize file pointers for input and output.
	FILE *fp = stdin;
	FILE *wfp = stdout;

	// Check for command line arguments to open input and output files.
	if (argc > 1) {
		fp = fopen(argv[1], "r"); // Open input file if provided.
		if (argc > 2) {
			wfp = fopen(argv[2], "w"); // Create output file if provided.
		}
	}

	// Create a scanner for reading input and a writer for output.
	getScanner(fp);
	FILE *writer = fopen("output.txt", "w");

	// Read the number of integers to process.
	int n = getNextInt(fp);

	// Initialize the answer as "second" and check for odd integers.
	char *ans = "second";
	for (int i = 0; i < n; i++) {
		int a = getNextInt(fp); // Read the next integer.
		if (a % 2 == 1) { // Check if the integer is odd.
			ans = "first"; // If odd, set answer to "first".
			break; // Exit the loop early if an odd integer is found.
		}
	}

	// Write the result to the output.
	fprintf(writer, "%s\n", ans);
	fclose(writer); // Ensure all buffered data is written to the output.
}

