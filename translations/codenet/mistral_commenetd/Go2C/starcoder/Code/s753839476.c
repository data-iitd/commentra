
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Initialize IO object and handle resources
int main() {
	IO *io = NewIO();
	defer io->flash();

	// Read input values
	int n = io->ScanInt();
	double t = io->ScanFloat64();
	double a = io->ScanFloat64();

	// Initialize variables for heights and minimum difference
	double *heights = io->ScanFloat64s(n);
	double minDiff = AbsDiffFloat64(t-heights[0]*0.006, a);
	int minIdx = 0;

	// Iterate through the remaining heights and find the minimum difference
	for (int i = 1; i < n; i++) {
		// Calculate the difference between the target and the height
		double diff = AbsDiffFloat64(t-heights[i]*0.006, a);

		// Update minimum difference and index if the current difference is smaller
		if (diff < minDiff) {
			minDiff = diff;
			minIdx = i;
		}
	}

	// Print the result
	printf("%d\n", minIdx + 1);
}

// Calculate absolute difference between two float64 numbers
double AbsDiffFloat64(double n1, double n2) {
	return fabs(n1 - n2);
}

// Initialize IO object with scanner and writer
typedef struct IO {
	FILE *reader;
	FILE *writer;
} IO;

// Create new IO object
IO *NewIO() {
	IO *io = (IO *)malloc(sizeof(IO));
	io->reader = fopen("CON", "r");
	io->writer = fopen("CON", "w");
	return io;
}

// Read a single byte from the scanner
char *ScanBytes(IO *io) {
	char *str = (char *)malloc(10000000);
	fgets(str, 10000000, io->reader);
	return str;
}

// Read a single string from the scanner
char *ScanString(IO *io) {
	char *str = (char *)malloc(10000000);
	fgets(str, 10000000, io->reader);
	return str;
}

// Read multiple strings from the scanner
char **ScanStrings(IO *io, int n) {
	char **strs = (char **)malloc(n * sizeof(char *));
	for (int i = 0; i < n; i++) {
		strs[i] = ScanString(io);
	}
	return strs;
}

// Read a 2D array of strings from the scanner
char ***Scan2DStrings(IO *io, int y, int x) {
	char ***strs = (char ***)malloc(y * sizeof(char **));
	for (int i = 0; i < y; i++) {
		strs[i] = ScanStrings(io, x);
	}
	return strs;
}

// Read a 2D array of graphs from the scanner
char ****Scan2DGraph(IO *io, int y) {
	char ****strs = (char ****)malloc(y * sizeof(char ***));
	for (int i = 0; i < y; i++) {
		strs[i] = (char ***)malloc(x * sizeof(char **));
		for (int j = 0; j < x; j++) {
			strs[i][j] = (char **)malloc(y * sizeof(char *));
			for (int k = 0; k < y; k++) {
				strs[i][j][k] = (char *)malloc(x * sizeof(char));
				strs[i][j][k] = (char *)strncpy(strs[i][j][k], strs[i][j][k], x);
			}
		}
	}
	return strs;
}

// Read a single integer from the scanner
int ScanInt(IO *io) {
	int i;
	fscanf(io->reader, "%d", &i);
	return i;
}

// Read two integers from the scanner
int *ScanInt2(IO *io) {
	int *i = (int *)malloc(2 * sizeof(int));
	fscanf(io->reader, "%d %d", &i[0], &i[1]);
	return i;
}

// Read three integers from the scanner
int *ScanInt3(IO *io) {
	int *i = (int *)malloc(3 * sizeof(int));
	fscanf(io->reader, "%d %d %d", &i[0], &i[1], &i[2]);
	return i;
}

// Read four integers from the scanner
int *ScanInt4(IO *io) {
	int *i = (int *)malloc(4 * sizeof(int));
	fscanf(io->reader, "%d %d %d %d", &i[0], &i[1], &i[2], &i[3]);
	return i;
}

// Read a slice of integers from the scanner
int *ScanInts(IO *io, int n) {
	int *ints = (int *)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++) {
		fscanf(io->reader, "%d", &ints[i]);
	}
	return ints;
}

// Read a 2D slice of integers from the scanner
int **Scan2DInts(IO *io, int y, int x) {
	int **ints = (int **)malloc(y * sizeof(int *));
	for (int i = 0; i < y; i++) {
		ints[i] = ScanInts(io, x);
	}
	return ints;
}

// Read a single int64 from the scanner
int64_t ScanInt64(IO *io) {
	int64_t i;
	fscanf(io->reader, "%lld", &i);
	return i;
}

// Read a single float64 from the scanner
double ScanFloat64(IO *io) {
	double i;
	fscanf(io->reader, "%lf", &i);
	return i;
}

// Read a slice of float64 from the scanner
double *ScanFloat64s(IO *io, int n) {
	double *floats = (double *)malloc(n * sizeof(double));
	for (int i = 0; i < n; i++) {
		fscanf(io->reader, "%lf", &floats[i]);
	}
	return floats;
}

// Write a single line to the writer
void Println(IO *io,...) {
	va_list args;
	va_start(args, io);
	vfprintf(io->writer, args);
	va_end(args);
}

// Flush the writer buffer
void writer.Flush(IO *io) {}

// Function to handle resource deallocation
void flash(IO *io) {
	fclose(io->reader);
	fclose(io->writer);
	free(io);
}

// Function to calculate the absolute difference between two float64 numbers
double AbsDiffFloat64(double n1, double n2) {
	return fabs(n1 - n2);
}

