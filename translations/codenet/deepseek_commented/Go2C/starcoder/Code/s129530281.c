#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// getScanner initializes a new scanner that reads from the given file pointer.
FILE* getScanner(FILE* fp) {
	if (fp == NULL) {
		fp = stdin;
	}
	return fp;
}

// getNextString reads the next word from the scanner.
char* getNextString(FILE* fp) {
	static char* word = NULL;
	static int wordSize = 0;
	if (word == NULL) {
		wordSize = 1000;
		word = malloc(sizeof(char) * wordSize);
	}
	char* ret = fgets(word, wordSize, fp);
	if (ret == NULL) {
		return NULL;
	}
	int i = strlen(word) - 1;
	while (i >= 0 && word[i] == '\n') {
		word[i] = '\0';
		i--;
	}
	return word;
}

// getNextInt converts the next word to an integer.
int getNextInt(FILE* fp) {
	char* word = getNextString(fp);
	if (word == NULL) {
		return 0;
	}
	return atoi(word);
}

// getNextInt64 converts the next word to a 64-bit integer.
int64_t getNextInt64(FILE* fp) {
	char* word = getNextString(fp);
	if (word == NULL) {
		return 0;
	}
	return atoll(word);
}

// getNextUint64 converts the next word to an unsigned 64-bit integer.
uint64_t getNextUint64(FILE* fp) {
	char* word = getNextString(fp);
	if (word == NULL) {
		return 0;
	}
	return strtoull(word, NULL, 10);
}

// getNextFloat64 converts the next word to a floating-point number.
double getNextFloat64(FILE* fp) {
	char* word = getNextString(fp);
	if (word == NULL) {
		return 0;
	}
	return atof(word);
}

// Segment struct represents a segment tree and includes methods to initialize it and update/query it.
typedef struct Segment {
	int n, h, i, chunk;
	int* unit;
	int** bucket;
} Segment;

// init initializes the segment tree with a given size n.
void init(Segment* seg, int n) {
	seg->n = n;
	seg->unit = malloc(sizeof(int));
	seg->unit[0] = 1;
	seg->bucket = malloc(sizeof(int*));
	seg->bucket[0] = malloc(sizeof(int) * n);

	int chunk = 8;
	for (int i = 0; n > 1; i++) {
		n = (n-1)/chunk + 1;
		seg->bucket = realloc(seg->bucket, sizeof(int*) * (i+2));
		seg->bucket[i+1] = malloc(sizeof(int) * n);
		seg->unit = realloc(seg->unit, sizeof(int) * (i+2));
		seg->unit[i+1] = seg->unit[i] * chunk;
	}
	seg->h = i+2;
	seg->chunk = chunk;
}

// maximize updates the value at a given index in the segment tree.
void maximize(Segment* seg, int index, int value) {
	seg->bucket[0][index] = value;
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

// top returns the index of the maximum value in the segment tree.
int top(Segment* seg) {
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

// Main function handles file input, initializes a segment tree, and processes the input to compute an answer.
int main(int argc, char** argv) {
	FILE* fp = getScanner(NULL);
	if (argc > 1) {
		fp = fopen(argv[1], "r");
	}
	if (fp == NULL) {
		return EXIT_FAILURE;
	}

	// Read the number of elements (n) and the number of operations (m).
	int n = getNextInt(fp);
	int m = getNextInt(fp);

	// Initialize the segment tree.
	Segment seg;
	init(&seg, n);

	// Populate the segment tree with initial values.
	for (int i = 0; i < n; i++) {
		maximize(&seg, i, getNextInt(fp));
	}

	// Perform the specified number of operations on the segment tree.
	for (int i = 0; i < m; i++) {
		maximize(&seg, top(&seg), seg.bucket[seg.h-1][0]>>1);
	}

	// Calculate the sum of the values in the root bucket of the segment tree.
	int64_t ans = 0;
	for (int i = 0; i < n; i++) {
		ans += seg.bucket[0][i];
	}

	// Write the result to the standard output.
	printf("%lld\n", ans);

	return EXIT_SUCCESS;
}

