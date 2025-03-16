
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Initialize input/output handling
struct IO {
	FILE *scanner;
	FILE *writer;
};

// NewIO initializes a new IO instance with a scanner and writer
struct IO newIO() {
	struct IO io;
	io.scanner = fopen("input.txt", "r");
	io.writer = fopen("output.txt", "w");
	return io;
}

// ScanBytes scans and returns a byte slice from input
char *scanBytes(struct IO io) {
	char *str = malloc(10000000);
	fscanf(io.scanner, "%s", str);
	return str;
}

// ScanString scans and returns a string from input
char *scanString(struct IO io) {
	char *str = malloc(10000000);
	fscanf(io.scanner, "%s", str);
	return str;
}

// ScanStrings scans and returns a slice of strings from input
char **scanStrings(struct IO io, int n) {
	char **strs = malloc(n * sizeof(char *));
	for (int i = 0; i < n; i++) {
		strs[i] = scanString(io);
	}
	return strs;
}

// Scan2DStrings scans and returns a 2D slice of strings from input
char ***scan2DStrings(struct IO io, int y, int x) {
	char ***strings = malloc(y * sizeof(char **));
	for (int i = 0; i < y; i++) {
		strings[i] = scanStrings(io, x);
	}
	return strings;
}

// Scan2DGraph scans and returns a 2D slice of strings representing a graph
char ***scan2DGraph(struct IO io, int y) {
	char ***strs = malloc(y * sizeof(char **));
	for (int i = 0; i < y; i++) {
		strs[i] = malloc(10000000 * sizeof(char *));
		fscanf(io.scanner, "%s", strs[i]);
	}
	return strs;
}

// ScanInt scans and returns an integer from input
int scanInt(struct IO io) {
	int i;
	fscanf(io.scanner, "%d", &i);
	return i;
}

// ScanInt2 scans and returns two integers from input
int *scanInt2(struct IO io) {
	int *ints = malloc(2 * sizeof(int));
	fscanf(io.scanner, "%d %d", &ints[0], &ints[1]);
	return ints;
}

// ScanInt3 scans and returns three integers from input
int *scanInt3(struct IO io) {
	int *ints = malloc(3 * sizeof(int));
	fscanf(io.scanner, "%d %d %d", &ints[0], &ints[1], &ints[2]);
	return ints;
}

// ScanInt4 scans and returns four integers from input
int *scanInt4(struct IO io) {
	int *ints = malloc(4 * sizeof(int));
	fscanf(io.scanner, "%d %d %d %d", &ints[0], &ints[1], &ints[2], &ints[3]);
	return ints;
}

// ScanInts scans and returns a slice of integers from input
int *scanInts(struct IO io, int n) {
	int *ints = malloc(n * sizeof(int));
	for (int i = 0; i < n; i++) {
		ints[i] = scanInt(io);
	}
	return ints;
}

// Scan2DInts scans and returns a 2D slice of integers from input
int **scan2DInts(struct IO io, int y, int x) {
	int **ints = malloc(y * sizeof(int *));
	for (int i = 0; i < y; i++) {
		ints[i] = scanInts(io, x);
	}
	return ints;
}

// ScanInt64 scans and returns an int64 from input
long long scanInt64(struct IO io) {
	long long i;
	fscanf(io.scanner, "%lld", &i);
	return i;
}

// ScanFloat64 scans and returns a float64 from input
double scanFloat64(struct IO io) {
	double i;
	fscanf(io.scanner, "%lf", &i);
	return i;
}

// ScanFloat64s scans and returns a slice of float64 from input
double *scanFloat64s(struct IO io, int n) {
	double *floats = malloc(n * sizeof(double));
	for (int i = 0; i < n; i++) {
		floats[i] = scanFloat64(io);
	}
	return floats;
}

// Println writes a line to the output
void println(struct IO io, char *a) {
	fprintf(io.writer, "%s\n", a);
}

// AbsDiffFloat64 calculates the absolute difference between two float64 numbers
double absDiffFloat64(double n1, double n2) {
	return fabs(n1 - n2);
}

// Main function
int main() {
	// Initialize input/output handling
	struct IO io = newIO();
	defer(io.writer); // Ensure the writer is flushed before exiting

	// Read the number of heights, target temperature, and actual temperature
	int n = scanInt(io);
	double t = scanFloat64(io);
	double a = scanFloat64(io);
	// Read the heights as a slice of float64
	double *heights = scanFloat64s(io, n);

	// Initialize minimum difference and index for tracking the closest height
	double minDiff = absDiffFloat64(t - heights[0] * 0.006, a);
	int minIdx = 0;

	// Iterate through the heights to find the one with the minimum temperature difference
	for (int i = 0; i < n; i++) {
		double h = heights[i];
		double diff = absDiffFloat64(t - h * 0.006, a);
		if (diff < minDiff) {
			minDiff = diff;
			minIdx = i + 1; // Update the index of the closest height
		}
	}

	// Output the 1-based index of the closest height
	printf("%d\n", minIdx + 1);

	return 0;
}

