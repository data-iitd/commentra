

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include <inttypes.h>

// getScanner initializes a new scanner for reading from the provided file pointer.
FILE* getScanner(FILE* fp) {
	return fp;
}

// getNextString retrieves the next string from the scanner.
char* getNextString(FILE* fp) {
	char* str = NULL;
	if (fscanf(fp, "%ms", &str)!= 1) {
		return NULL;
	}
	return str;
}

// getNextInt retrieves the next integer from the scanner.
int64_t getNextInt(FILE* fp) {
	int64_t i = 0;
	fscanf(fp, "%" PRId64, &i);
	return i;
}

// getNextInt64 retrieves the next int64 from the scanner.
int64_t getNextInt64(FILE* fp) {
	int64_t i = 0;
	fscanf(fp, "%" PRId64, &i);
	return i;
}

// getNextUint64 retrieves the next uint64 from the scanner.
uint64_t getNextUint64(FILE* fp) {
	uint64_t i = 0;
	fscanf(fp, "%" PRIu64, &i);
	return i;
}

// getNextFloat64 retrieves the next float64 from the scanner.
double getNextFloat64(FILE* fp) {
	double i = 0;
	fscanf(fp, "%lf", &i);
	return i;
}

// Segment structure to hold the segment data and operations
typedef struct Segment {
	int n, h, i, chunk;
	int* unit;
	int** bucket;
} Segment;

// init initializes the segment structure with the given size n.
void init(Segment* seg, int n) {
	seg->n = n;
	seg->unit = malloc(sizeof(int)); // Initialize unit array
	seg->unit[0] = 1;
	seg->bucket = malloc(sizeof(int*)); // Initialize bucket array
	seg->bucket[0] = malloc(sizeof(int) * n);

	int chunk = 8; // Define the chunk size
	for (int i = 0; n > 1; i++) {
		n = (n-1)/chunk + 1; // Reduce n based on the chunk size
		seg->bucket = realloc(seg->bucket, sizeof(int*) * (i+2)); // Append a new bucket
		seg->unit = realloc(seg->unit, sizeof(int) * (i+2)); // Update unit array
		seg->bucket[i+1] = malloc(sizeof(int) * n);
		seg->unit[i+1] = seg->unit[i] * chunk;
	}
	seg->h = i+2; // Set the height of the segment
	seg->chunk = chunk; // Set the chunk size
}

// maximize updates the segment at a given index with a new value.
void maximize(Segment* seg, int index, int value) {
	seg->bucket[0][index] = value; // Set the value in the first bucket
	for (seg->i = 0; seg->i < seg->h-1; seg->i++) {
		int s = index - index%seg->chunk; // Calculate the start of the current chunk
		int t = s + seg->chunk; // Calculate the end of the current chunk
		if (t > seg->n) {
			t = seg->n; // Adjust end if it exceeds the bucket length
		}
		int parent = index / seg->chunk; // Determine the parent index
		int max = 0; // Initialize max value
		for (int i = s; i < t; i++) {
			if (max < seg->bucket[seg->i][i]) {
				max = seg->bucket[seg->i][i]; // Find the maximum value in the current chunk
			}
		}
		seg->bucket[seg->i+1][parent] = max; // Update the parent bucket with the maximum value
		index /= seg->chunk; // Move to the parent index for the next iteration
	}
}

// top retrieves the index of the top value in the segment.
int top(Segment* seg) {
	int index = 0; // Start from the root index
	for (seg->i = seg->h - 2; seg->i >= 0; seg->i--) {
		int s = index * seg->chunk; // Calculate the start of the current chunk
		int t = s + seg->chunk; // Calculate the end of the current chunk
		if (t > seg->n) {
			t = seg->n; // Adjust end if it exceeds the bucket length
		}
		for (int i = s; i < t; i++) {
			if (seg->bucket[seg->i][i] == seg->bucket[seg->i+1][index]) {
				index = i; // Update index if the value matches the top value
				break;
			}
		}
	}

	return index; // Return the index of the top value
}

// main function
int main(int argc, char* argv[]) {
	// Determine the input source: either standard input or a file specified as a command-line argument
	FILE* fp = stdin;
	if (argc > 1) {
		fp = fopen(argv[1], "r"); // Open the file if an argument is provided
	}
	FILE* scanner = getScanner(fp); // Initialize the scanner for the input source
	FILE* writer = stdout; // Create a buffered writer for output

	// Read the number of elements and operations
	int n = getNextInt(scanner);
	int m = getNextInt(scanner);

	// Initialize the Segment structure
	Segment seg;
	init(&seg, n); // Initialize the segment with size n

	// Populate the segment with initial values
	for (int i = 0; i < n; i++) {
		maximize(&seg, i, getNextInt(scanner)); // Maximize the segment with the input values
	}

	// Perform m operations to maximize the segment
	for (int i = 0; i < m; i++) {
		maximize(&seg, top(&seg), seg.bucket[seg.h-1][0]>>1); // Maximize using the top value and half of the last bucket's first element
	}

	// Calculate the final answer by summing up the values in the first bucket
	int64_t ans = 0;
	for (int i = 0; i < n; i++) {
		ans += seg.bucket[0][i]; // Accumulate the values
	}

	// Output the final result
	fprintf(writer, "%" PRId64 "\n", ans);
	fflush(writer); // Flush the buffered writer to ensure all output is written
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include <inttypes.h>

// getScanner initializes a new scanner for reading from the provided file pointer.
FILE* getScanner(FILE* fp) {
	return fp;
}

// getNextString retrieves the next string from the scanner.
char* getNextString(FILE* fp) {
	char* str = NULL;
	if (fscanf(fp, "%ms", &str)!= 1) {
		return NULL;
	}
	return str;
}

// getNextInt retrieves the next integer from the scanner.
int64_t getNextInt(FILE* fp) {
	int64_t i = 0;
	fscanf(fp, "%" PRId64, &i);
	return i;
}

// getNextInt64 retrieves the next int64 from the scanner.
int64_t getNextInt64(FILE* fp) {
	int64_t i = 0;
	fscanf(fp, "%" PRId64, &i);
	return i;
}

// getNextUint64 retrieves the next uint64 from the scanner.
uint64_t getNextUint64(FILE* fp) {
	uint64_t i = 0;
	fscanf(fp, "%" PRIu64, &i);
	return i;
}

// getNextFloat64 retrieves the next float64 from the scanner.
double getNextFloat64(FILE* fp) {
	double i = 0;
	fscanf(fp, "%lf", &i);
	return i;
}

// Segment structure to hold the segment data and operations
typedef struct Segment {
	int n, h, i, chunk;
	int* unit;
	int** bucket;
} Segment;

// init initializes the segment structure with the given size n.
void init(Segment* seg, int n) {
	seg->n = n;
	seg->unit = malloc(sizeof(int)); // Initialize unit array
	seg->unit[0] = 1;
	seg->bucket = malloc(sizeof(int*)); // Initialize bucket array
	seg->bucket[0] = malloc(sizeof(int) * n);

	int chunk = 8; // Define the chunk size
	for (int i = 0; n > 1; i++) {
		n = (n-1)/chunk + 1; // Reduce n based on the chunk size
		seg->bucket = realloc(seg->bucket, sizeof(int*) * (i+2)); // Append a new bucket
		seg->unit = realloc(seg->unit, sizeof(int) * (i+2)); // Update unit array
		seg->bucket[i+1] = malloc(sizeof(int) * n);
		seg->unit[i+1] = seg->unit[i] * chunk;
	}
	seg->h = i+2; // Set the height of the segment
	seg->chunk = chunk; // Set the chunk size
}

// maximize updates the segment at a given index with a new value.
void maximize(Segment* seg, int index, int value) {
	seg->bucket[0][index] = value; // Set the value in the first bucket
	for (seg->i = 0; seg->i < seg->h-1; seg->i++) {
		int s = index - index%seg->chunk; // Calculate the start of the current chunk
		int t = s + seg->chunk; // Calculate the end of the current chunk
		if (t > seg->n) {
			t = seg->n; // Adjust end if it exceeds the bucket length
		}
		int parent = index / seg->chunk; // Determine the parent index
		int max = 0; // Initialize max value
		for (int i = s; i < t; i++) {
			if (max < seg->bucket[seg->i][i]) {
				max = seg->bucket[seg->i][i]; // Find the maximum value in the current chunk
			}
		}
		seg->bucket[seg->i+1][parent] = max; // Update the parent bucket with the maximum value
		index /= seg->chunk; // Move to the parent index for the next iteration
	}
}

// top retrieves the index of the top value in the segment.
int top(Segment* seg) {
	int index = 0; // Start from the root index
	for (seg->i = seg->h - 2; seg->i >= 0; seg->i--) {
		int s = index * seg->chunk; // Calculate the start of the current chunk
		int t = s + seg->chunk; // Calculate the end of the current chunk
		if (t > seg->n) {
			t = seg->n; // Adjust end if it exceeds the bucket length
		}
		for (int i = s; i < t; i++) {
			if (seg->bucket[seg->i][i] == seg->bucket[seg->i+1][index]) {
				index = i; // Update index if the value matches the top value
				break;
			}
		}
	}

	return index; // Return the index of the top value
}

// main function
int main(int argc, char* argv[]) {
	// Determine the input source: either standard input or a file specified as a command-line argument
	FILE* fp = stdin;
	if (argc > 1) {
		fp = fopen(argv[1], "r"); // Open the file if an argument is provided
	}
	FILE* scanner = getScanner(fp); // Initialize the scanner for the input source
	FILE* writer = stdout; // Create a buffered writer for output

	// Read the number of elements and operations
	int n = getNextInt(scanner);
	int m = getNextInt(scanner);

	// Initialize the Segment structure
	Segment seg;
	init(&seg, n); // Initialize the segment with size n

	// Populate the segment with initial values
	for (int i = 0; i < n; i++) {
		maximize(&seg, i, getNextInt(scanner)); // Maximize the segment with the input values
	}

	// Perform m operations to maximize the segment
	for (int i = 0; i < m; i++) {
		maximize(&seg, top(&seg), seg.bucket[seg.h-1][0]>>1); // Maximize using the top value and half of the last bucket's first element
	}

	// Calculate the final answer by summing up the values in the first bucket
	int64_t ans = 0;
	for (int i = 0; i < n; i++) {
		ans += seg.bucket[0][i]; // Accumulate the values
	}

	// Output the final result
	fprintf(writer, "%" PRId64 "\n", ans);
	fflush(writer); // Flush the buffered writer to ensure all output is written
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include <inttypes.h>

// getScanner initializes a new scanner for reading from the provided file pointer.
FILE* getScanner(FILE* fp) {
	return fp;
}

// getNextString retrieves the 