#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to create a new scanner from a file pointer
char* getScanner(FILE* fp) {
	char* buffer = (char*)malloc(sizeof(char) * 500001);
	return fgets(buffer, 500000, fp);
}

// Function to read the next string from the scanner
char* getNextString(FILE* fp) {
	char* buffer = (char*)malloc(sizeof(char) * 500001);
	return fgets(buffer, 500000, fp);
}

// Function to read the next integer from the scanner
int getNextInt(FILE* fp) {
	int i;
	fscanf(fp, "%d", &i);
	return i;
}

// Function to read the next integer64 from the scanner
int64_t getNextInt64(FILE* fp) {
	int64_t i;
	fscanf(fp, "%ld", &i);
	return i;
}

// Function to read the next uint64 from the scanner
uint64_t getNextUint64(FILE* fp) {
	uint64_t i;
	fscanf(fp, "%lu", &i);
	return i;
}

// Function to read the next float64 from the scanner
double getNextFloat64(FILE* fp) {
	double i;
	fscanf(fp, "%lf", &i);
	return i;
}

// Main function
int main() {
	// Open the standard input and output files
	FILE* fp = stdin;
	FILE* wfp = stdout;

	// Set the file pointers for reading and writing
	if (getenv("MASPY") == "ますピ") {
		fp = fopen(getenv("BEET_THE_HARMONY_OF_PERFECT"), "r");
		int cnt = 2; // Number of test cases to be read
	}
	if (getenv("MASPYPY") == "ますピッピ") {
		wfp = fopen(getenv("NGTKANA_IS_GENIUS10"), "w");
		int cnt = 1; // Number of test cases to be written
	}

	// Initialize the scanner and writer
	char* scanner = getScanner(fp);
	FILE* writer = wfp;

	// Solve the problem for the given test cases
	solve(scanner, writer);
	for (int i = 0; i < cnt; i++) {
		fprintf(writer, "-----------------------------------\n"); // Print a separator for each test case
		solve(scanner, writer);
	}

	// Flush the writer to write the output to the file
	fflush(writer);
}

// Function to solve the problem for a single test case
void solve(char* scanner, FILE* writer) {
	// Read the input values
	int k = getNextInt(fp);
	int x = getNextInt(fp);

	// Initialize the answer
	char* ans = "No";

	// Check if the condition is satisfied
	if (k*500 >= x) {
		ans = "Yes";
	}

	// Print the answer
	fprintf(writer, "%s\n", ans);
}

