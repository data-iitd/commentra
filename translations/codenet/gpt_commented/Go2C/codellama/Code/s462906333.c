
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a large constant for infinity
#define inf 1e14

// ---------------------------------------------------------
int main() {
	// Set log flags to show the file name and line number
	// log.SetFlags(log.Lshortfile)

	// Initialize a new scanner for input
	// next := newScanner()

	// Read the number of elements and the value of x
	int n, x;
	scanf("%d %d", &n, &x);

	// Create a slice to hold the input integers
	int a[n];

	// Read n integers into the slice a
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}

	// Create a copy of the slice a for manipulation
	int v[n];
	memcpy(v, a, n * sizeof(int));

	// Initialize the answer to infinity
	int ans = inf;

	// Iterate over each possible k value
	for (int k = 0; k < n; k++) {
		int kans = 0; // Initialize the current answer for this k

		// Calculate the minimum values for the current k
		for (int i = 0; i < n; i++) {
			if (i - k < 0) {
				// If i-k is out of bounds, use the wrapped index
				v[i] = min(v[i], a[n + i - k]);
			} else {
				// Otherwise, use the normal index
				v[i] = min(v[i], a[i - k]);
			}
			// Accumulate the current answer
			kans += v[i];
		}

		// Update the overall answer with the minimum found so far
		ans = min(ans, kans + k * x);
	}

	// Print the final answer
	printf("%d\n", ans);

	return 0;
}

// ---------------------------------------------------------

// Pair represents a pair of integers
typedef struct {
	int a, b;
} Pair;

// Pairs is a slice of Pair structs that can be sorted
typedef struct {
	Pair *pairs;
	int len;
} Pairs;

// Implement the sort.Interface for Pairs
int Pairs_Len(Pairs *p) {
	return p->len;
}
void Pairs_Swap(Pairs *p, int i, int j) {
	Pair tmp = p->pairs[i];
	p->pairs[i] = p->pairs[j];
	p->pairs[j] = tmp;
}
int Pairs_Less(Pairs *p, int i, int j) {
	// Define sorting criteria based on the first and second elements of the pairs
	if (p->pairs[i].a < p->pairs[j].a) {
		return 1;
	} else if (p->pairs[i].a == p->pairs[j].a) {
		return p->pairs[i].b < p->pairs[j].b;
	}
	return 0;
}

// -------------------------------

// in checks if c is within the range [a, z)
int in(int c, int a, int z) {
	return c >= a && c < z;
}

// btoi converts a boolean to an integer (1 for true, 0 for false)
int btoi(int b) {
	if (b) {
		return 1;
	}
	return 0;
}

// itob converts an integer to a boolean (false for 0, true for non-zero)
int itob(int a) {
	if (a == 0) {
		return 0;
	}
	return 1;
}

// max returns the maximum value from a list of integers
int max(int a, ...) {
	int r = a;
	va_list args;
	va_start(args, a);
	for (int i = 0; i < 1000; i++) {
		int v = va_arg(args, int);
		if (r < v) {
			r = v;
		}
	}
	va_end(args);
	return r;
}

// min returns the minimum value from a list of integers
int min(int a, ...) {
	int r = a;
	va_list args;
	va_start(args, a);
	for (int i = 0; i < 1000; i++) {
		int v = va_arg(args, int);
		if (r > v) {
			r = v;
		}
	}
	va_end(args);
	return r;
}

// minmax returns the minimum and maximum of two integers
int minmax(int a, int b) {
	if (a > b) {
		return b, a;
	}
	return a, b;
}

// abs returns the absolute value of an integer
int abs(int a) {
	if (a < 0) {
		return -a;
	}
	return a;
}

// sum returns the sum of a list of integers
int sum(int a, ...) {
	int r = a;
	va_list args;
	va_start(args, a);
	for (int i = 0; i < 1000; i++) {
		int v = va_arg(args, int);
		r += v;
	}
	va_end(args);
	return r;
}

// ---------- buffered scanner -----------------------------------------

// scanner is a custom buffered scanner for reading input
typedef struct {
	FILE *r; // Buffered reader
	char *buf; // Buffer to hold read data
	int p; // Current position in the buffer
} scanner;

// newScanner initializes a new scanner with a specified buffer size
scanner *newScanner() {
	FILE *rdr = fopen("input.txt", "r");
	scanner *s = malloc(sizeof(scanner));
	s->r = rdr;
	s->buf = malloc(10000);
	s->p = 0;
	return s;
}

// next reads the next token from the input
char *next(scanner *s) {
	s->pre(); // Ensure the buffer is filled
	int start = s->p;
	for (; s->p < strlen(s->buf); s->p++) {
		if (s->buf[s->p] == ' ') {
			break;
		}
	}
	char *result = malloc(s->p - start + 1);
	strncpy(result, s->buf + start, s->p - start);
	result[s->p - start] = '\0';
	s->p++; // Move past the space
	return result;
}

// Line reads the remainder of the current line
char *Line(scanner *s) {
	s->pre(); // Ensure the buffer is filled
	int start = s->p;
	s->p = strlen(s->buf); // Move to the end of the buffer
	char *result = malloc(s->p - start + 1);
	strncpy(result, s->buf + start, s->p - start);
	result[s->p - start] = '\0';
	return result;
}

// Int reads the next integer from the input
int Int(scanner *s) {
	char *v = next(s);
	int result = atoi(v);
	free(v);
	return result;
}

// Int64 reads the next int64 from the input
int64_t Int64(scanner *s) {
	char *v = next(s);
	int64_t result = atoll(v);
	free(v);
	return result;
}

// pre fills the buffer if the current position is at the end
void pre(scanner *s) {
	if (s->p >= strlen(s->buf)) {
		s->readLine(); // Read a new line into the buffer
		s->p = 0; // Reset the position to the start of the buffer
	}
}

// readLine reads a line from the input into the buffer
void readLine(scanner *s) {
	s->buf = realloc(s->buf, 10000);
	fgets(s->buf, 10000, s->r);
}

