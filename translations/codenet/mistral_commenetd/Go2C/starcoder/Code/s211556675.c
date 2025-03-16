#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// I/O
typedef struct {
	char *s;
	int len;
	int pos;
} Reader;

// NewReader initializes a new Reader struct with a string
Reader *NewReader(char *s) {
	Reader *r = malloc(sizeof(Reader));
	r->s = s;
	r->len = strlen(s);
	r->pos = 0;
	return r;
}

// (r *Reader) nextStr reads a single word as a string from the input
char *nextStr(Reader *r) {
	char *res = malloc(sizeof(char) * 1024);
	int i = 0;
	while (r->pos < r->len && s[r->pos]!='') {
		res[i++] = s[r->pos++];
	}
	res[i] = '\0';
	return res;
}

// (r *Reader) nextInt reads a single integer from the input
int nextInt(Reader *r) {
	int res = 0;
	int neg = 0;
	while (r->pos < r->len && s[r->pos] =='') {
		r->pos++;
	}
	if (r->pos == r->len) {
		return 0;
	}
	if (s[r->pos] == '-') {
		neg = 1;
		r->pos++;
	}
	while (r->pos < r->len && s[r->pos]!='') {
		res = res * 10 + (s[r->pos] - '0');
		r->pos++;
	}
	if (neg) {
		return -res;
	}
	return res;
}

// (r *Reader) nextFloat reads a single floating-point number from the input
float nextFloat(Reader *r) {
	float res = 0;
	int neg = 0;
	while (r->pos < r->len && s[r->pos] =='') {
		r->pos++;
	}
	if (r->pos == r->len) {
		return 0;
	}
	if (s[r->pos] == '-') {
		neg = 1;
		r->pos++;
	}
	while (r->pos < r->len && s[r->pos]!='') {
		res = res * 10 + (s[r->pos] - '0');
		r->pos++;
	}
	if (neg) {
		return -res;
	}
	return res;
}

// (r *Reader) nextRuneSlice reads a slice of runes from the input
Rune *nextRuneSlice(Reader *r) {
	Rune *res = malloc(sizeof(Rune) * 1024);
	int i = 0;
	while (r->pos < r->len && s[r->pos]!='') {
		res[i++] = s[r->pos++];
	}
	res[i] = '\0';
	return res;
}

// (r *Reader) nextIntSlice reads a slice of integers from the input with a given length
int *nextIntSlice(Reader *r, int n) {
	int *res = malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		res[i] = nextInt(r);
	}
	return res;
}

// (r *Reader) nextFloatSlice reads a slice of floating-point numbers from the input with a given length
float *nextFloatSlice(Reader *r, int n) {
	float *res = malloc(sizeof(float) * n);
	for (int i = 0; i < n; i++) {
		res[i] = nextFloat(r);
	}
	return res;
}

// Arithmetic
int max(int nums[], int n) {
	int m = nums[0];
	for (int i = 1; i < n; i++) {
		if (m < nums[i]) {
			m = nums[i];
		}
	}
	return m;
}

int min(int nums[], int n) {
	int m = nums[0];
	for (int i = 1; i < n; i++) {
		if (m > nums[i]) {
			m = nums[i];
		}
	}
	return m;
}

int abs(int x) {
	if (x > 0) {
		return x;
	}
	return -x;
}

int pow(int x, int y) {
	int res = 1;
	for (int i = 0; i < y; i++) {
		res *= x;
	}
	return res;
}

// Sort
typedef struct {
	int id;
	int num;
} Val;

// ByNum is a type alias for a slice of Val structs, used for sorting
typedef Val ByNum[];

int Len(ByNum a) {
	return sizeof(a) / sizeof(a[0]);
}

int Less(ByNum a, int i, int j) {
	return a[i].num < a[j].num;
}

void Swap(ByNum a, int i, int j) {
	Val tmp = a[i];
	a[i] = a[j];
	a[j] = tmp;
}

// Main function
int main() {
	Reader *r = NewReader(s); // Initialize a new Reader
	Writer *wtr = NewWriter(os.Stdout); // Initialize a new Writer for output

	// Read input values
	int A, B, C, K = nextInt(r), nextInt(r), nextInt(r), nextInt(r);

	// Find the maximum value among A, B, and C
	int ma = max(A, B, C);

	// Calculate the rest of the numbers that need to be multiplied by 2 to reach or exceed K
	int rest = 0;
	if (ma == A) {
		rest += B + C;
	} else if (ma == B) {
		rest += A + C;
	} else {
		rest += A + B;
	}

	// Calculate the final answer
	int answer = pow(ma, K) + rest;

	// Write the answer to the output
	printf("%d\n", answer);
	Flush(wtr); // Flush the buffer to write the output
}

