#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// getScanner initializes a new scanner for reading from the provided file pointer.
// It sets the scanner to split input by words and allocates a buffer for larger inputs.
void getScanner(FILE *fp) {
	char *buffer = (char *)malloc(500001);
	fscanf(fp, "%s", buffer);
	free(buffer);
}

// getNextString retrieves the next string from the scanner.
char *getNextString(FILE *fp) {
	char *buffer = (char *)malloc(500001);
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
long long getNextInt64(FILE *fp) {
	char *buffer = getNextString(fp);
	long long i = atoll(buffer);
	free(buffer);
	return i;
}

// getNextUint64 converts the next string from the scanner to an unsigned 64-bit integer.
unsigned long long getNextUint64(FILE *fp) {
	char *buffer = getNextString(fp);
	unsigned long long i = strtoull(buffer, NULL, 10);
	free(buffer);
	return i;
}

// getNextFloat64 converts the next string from the scanner to a float64.
double getNextFloat64(FILE *fp) {
	char *buffer = getNextString(fp);
	double i = atof(buffer);
	free(buffer);
	return i;
}

int main() {
	// Initialize file pointers for input and output.
	FILE *fp = stdin;
	FILE *wfp = stdout;
	int cnt = 0;

	// Check for environment variables to determine input and output files.
	if (getenv("MASPY") != NULL && strcmp(getenv("MASPY"), "ますピ") == 0) {
		fp = fopen(getenv("BEET_THE_HARMONY_OF_PERFECT"), "r");
		cnt = 2; // Set the count for additional processing.
	}
	if (getenv("MASPYPY") != NULL && strcmp(getenv("MASPYPY"), "ますピッピ") == 0) {
		wfp = fopen(getenv("NGTKANA_IS_GENIUS10"), "w");
	}

	// Create a scanner for reading input and a writer for output.
	getScanner(fp);
	FILE *writer = fopen("output.txt", "w");

	// Solve the problem for the first time.
	solve(fp, writer);

	// If cnt is greater than 0, solve the problem additional times.
	for (int i = 0; i < cnt; i++) {
		fprintf(writer, "-----------------------------------\n");
		solve(fp, writer);
	}

	// Flush the writer to ensure all output is written.
	fflush(writer);
	fclose(writer);
}

// solve processes the input values and determines if the condition is met.
// It reads two integers k and x, and checks if k * 500 is greater than or equal to x.
void solve(FILE *fp, FILE *writer) {
	int k = getNextInt(fp); // Read the first integer k.
	int x = getNextInt(fp); // Read the second integer x.

	char *ans = "No"; // Default answer is "No".
	if (k * 500 >= x) { // Check the condition.
		ans = "Yes"; // Update answer to "Yes" if condition is met.
	}
	fprintf(writer, "%s\n", ans); // Output the result.
}

