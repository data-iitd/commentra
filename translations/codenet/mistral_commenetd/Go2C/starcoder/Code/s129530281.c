
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

// Segment type represents a segment tree data structure
typedef struct {
	int n, h, i, chunk;
	int *unit;
	int **bucket;
} Segment;

// init function initializes the Segment struct with the given size n
void init(Segment *seg, int n) {
	seg->n = n;
	seg->unit = malloc(sizeof(int));
	seg->unit[0] = 1;
	seg->bucket = malloc(sizeof(int*));
	seg->bucket[0] = malloc(sizeof(int)*n);

	// Calculate the chunk size for the segment tree
	int chunk = 8;
	for (int i = 0; n > 1; i++) {
		n = (n-1)/chunk + 1;
		seg->bucket = realloc(seg->bucket, sizeof(int*)*(i+2));
		seg->bucket[i+1] = malloc(sizeof(int)*n);
		seg->unit = realloc(seg->unit, sizeof(int)*(i+2));
		seg->unit[i+1] = seg->unit[i]*chunk;
	}
	seg->h = i+2;
	seg->chunk = chunk;
}

// maximize function updates the segment tree with the given index and value
void maximize(Segment *seg, int index, int value) {
	// Update the leaf node with the given index and value
	seg->bucket[0][index] = value;

	// Propagate the update to the parent nodes
	for (seg->i = 0; seg->i < seg->h-1; seg->i++) {
		int s = index - index%seg->chunk;
		int t = s + seg->chunk;
		if (t > seg->n) {
			t = seg->n;
		}
		int parent = index / seg->chunk;
		int max = 0;
		for (int i = s; i < t; i++) {
			if (max < seg->bucket[seg->i][i]) {
				max = seg->bucket[seg->i][i];
			}
		}
		seg->bucket[seg->i+1][parent] = max;
		index /= seg->chunk;
	}
}

// top function returns the index of the maximum value in the current segment
int top(Segment *seg) {
	int index = 0;
	for (seg->i = seg->h - 2; seg->i >= 0; seg->i--) {
		int s = index * seg->chunk;
		int t = s + seg->chunk;
		if (t > seg->n) {
			t = seg->n;
		}
		for (int i = s; i < t; i++) {
			if (seg->bucket[seg->i][i] == seg->bucket[seg->i+1][index]) {
				index = i;
				break;
			}
		}
	}

	return index;
}

// main function is the entry point of the program
int main(int argc, char *argv[]) {
	// Open the standard input file if a command-line argument is provided
	FILE *fp = fopen(argc > 1? argv[1] : "input.txt", "r");
	if (fp == NULL) {
		return EXIT_FAILURE;
	}

	// Initialize a bufio.Writer for formatted output
	FILE *writer = fopen("output.txt", "w");
	if (writer == NULL) {
		return EXIT_FAILURE;
	}

	// Read the first two integers from the input
	int n = 0;
	fscanf(fp, "%d", &n);
	int m = 0;
	fscanf(fp, "%d", &m);

	// Initialize the Segment struct with the given size n
	Segment seg;
	init(&seg, n);

	// Process the input data by maximizing the segments
	for (int i = 0; i < n; i++) {
		int value = 0;
		fscanf(fp, "%d", &value);
		maximize(&seg, i, value);
	}
	for (int i = 0; i < m; i++) {
		int value = 0;
		fscanf(fp, "%d", &value);
		maximize(&seg, seg.top(), value/2);
	}

	// Calculate the answer and print it to the output
	int64_t ans = 0;
	for (int i = 0; i < n; i++) {
		ans += seg.bucket[0][i];
	}

	// Print the answer to the output
	fprintf(writer, "%ld\n", ans);

	// Close the input and output files
	fclose(fp);
	fclose(writer);

	return EXIT_SUCCESS;
}

