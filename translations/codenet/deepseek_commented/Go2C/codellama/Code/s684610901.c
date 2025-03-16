
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>

// Package main defines the entry point for the program.

/*==========================================
 *             Custom Sorting Types
 *==========================================*/
// pair struct holds two values and an index for sorting.
typedef struct {
	int64_t index;
	int64_t p1;
	int64_t p2;
} pair;

// pairs is a slice of pair structs for sorting.
typedef struct {
	int64_t len;
	pair *pairs;
} pairs;

// Len returns the length of the pairs slice.
int64_t pairs_len(pairs *slice) {
	return slice->len;
}

// Less compares two pairs based on their index.
bool pairs_less(pairs *slice, int64_t i, int64_t j) {
	return slice->pairs[i].index < slice->pairs[j].index;
}

// Swap exchanges two pairs in the slice.
void pairs_swap(pairs *slice, int64_t i, int64_t j) {
	pair tmp = slice->pairs[i];
	slice->pairs[i] = slice->pairs[j];
	slice->pairs[j] = tmp;
}

// Int64Slice is a type alias for sorting slices of int64.
typedef struct {
	int64_t len;
	int64_t *ary;
} Int64Slice;

// Len returns the length of the Int64Slice.
int64_t int64s_len(Int64Slice *slice) {
	return slice->len;
}

// Less compares two int64 values.
bool int64s_less(Int64Slice *slice, int64_t i, int64_t j) {
	return slice->ary[i] < slice->ary[j];
}

// Swap exchanges two int64 values in the slice.
void int64s_swap(Int64Slice *slice, int64_t i, int64_t j) {
	int64_t tmp = slice->ary[i];
	slice->ary[i] = slice->ary[j];
	slice->ary[j] = tmp;
}

// Int64s sorts a slice of int64.
void int64s(Int64Slice *slice) {
	int64_t i, j, k, l;
	int64_t n = slice->len;
	for (i = 1; i < n; i++) {
		k = i;
		l = slice->ary[i];
		for (j = i - 1; j >= 0 && slice->ary[j] > l; j--) {
			slice->ary[k] = slice->ary[j];
			k = j;
		}
		slice->ary[k] = l;
	}
}

// Int64sSliceAreSorted checks if a slice of int64 is sorted.
bool int64s_slice_are_sorted(Int64Slice *slice) {
	int64_t i, j;
	int64_t n = slice->len;
	for (i = 0; i < n - 1; i++) {
		if (slice->ary[i] > slice->ary[i + 1]) {
			return false;
		}
	}
	return true;
}

/*==========================================
 *             Constants and Variables
 *==========================================*/
// scanner and writer are initialized for reading from standard input and writing to standard output.
FILE *scanner;
FILE *writer;
int64_t di[] = {-1, 0, 1, 0};
int64_t dj[] = {0, -1, 0, 1};

/*==========================================
 *             Main Function
 *==========================================*/
// main function reads three integers and checks if the third integer lies between the first and second.
int main() {
	int64_t A, B, C;
	A = scanInt();
	B = scanInt();
	C = scanInt();
	if (C >= A && C <= B) {
		fprintf(writer, "Yes\n");
	} else {
		fprintf(writer, "No\n");
	}
	return 0;
}

/*==========================================
 *             Library
 *==========================================*/
// NextPermutation finds the next permutation of a slice.
bool next_permutation(Int64Slice *x) {
	int64_t n = x->len;
	if (n < 2) {
		return false;
	}
	int64_t j = n - 2;
	for (; !int64s_less(x, j, j + 1); j--) {
		if (j == 0) {
			return false;
		}
	}
	int64_t l = n - 1;
	for (; !int64s_less(x, j, l); l--) {
	}
	int64_t k = j + 1;
	int64_t l = n - 1;
	for (; k < l; k++, l--) {
		int64_t tmp = x->ary[k];
		x->ary[k] = x->ary[l];
		x->ary[l] = tmp;
	}
	return true;
}

// doubleAry creates a 2D slice initialized with a given value.
Int64Slice **doubleAry(int64_t h, int64_t w, int64_t init) {
	Int64Slice **res = (Int64Slice **)malloc(h * sizeof(Int64Slice *));
	for (int64_t i = 0; i < h; i++) {
		res[i] = (Int64Slice *)malloc(w * sizeof(Int64Slice));
		for (int64_t j = 0; j < w; j++) {
			res[i][j].len = 0;
			res[i][j].ary = (int64_t *)malloc(init * sizeof(int64_t));
			for (int64_t k = 0; k < init; k++) {
				res[i][j].ary[k] = 0;
			}
		}
	}
	return res;
}

// aryEq checks if two slices are equal.
bool aryEq(int64_t *a, int64_t *b) {
	int64_t i;
	for (i = 0; i < a->len; i++) {
		if (a->ary[i] != b->ary[i]) {
			return false;
		}
	}
	return true;
}

// clone creates a copy of a slice.
int64_t *clone(int64_t *n) {
	int64_t *r = (int64_t *)malloc(n->len * sizeof(int64_t));
	for (int64_t i = 0; i < n->len; i++) {
		r->ary[i] = n->ary[i];
	}
	return r;
}

// write writes a string to the writer.
void write(char *s) {
	fprintf(writer, "%s", s);
}

// print flushes the writer.
void print() {
	fflush(writer);
}

// readLine reads a line of text from the scanner.
char *readLine() {
	char *s = (char *)malloc(1000000 * sizeof(char));
	fscanf(scanner, "%s", s);
	return s;
}

// readInt reads an integer from the scanner.
int64_t readInt() {
	int64_t read;
	fscanf(scanner, "%lld", &read);
	return read;
}

// readFloat reads a float from the scanner.
double readFloat() {
	double read;
	fscanf(scanner, "%lf", &read);
	return read;
}

// readRunes reads a slice of runes from the scanner.
char *readRunes() {
	char *s = (char *)malloc(1000000 * sizeof(char));
	fscanf(scanner, "%s", s);
	return s;
}

// readString reads a string from the scanner.
char *readString() {
	char *s = (char *)malloc(1000000 * sizeof(char));
	fscanf(scanner, "%s", s);
	return s;
}

// readStrings reads multiple strings from the scanner.
char **readStrings() {
	char **s = (char **)malloc(1000000 * sizeof(char *));
	for (int64_t i = 0; i < 1000000; i++) {
		s[i] = (char *)malloc(1000000 * sizeof(char));
		fscanf(scanner, "%s", s[i]);
	}
	return s;
}

// s2i converts a string to an integer.
int64_t s2i(char *s) {
	int64_t intVal;
	int64_t e = sscanf(s, "%lld", &intVal);
	if (e != 1) {
		printf("Error: s2i\n");
		exit(1);
	}
	return intVal;
}

// i2s converts an integer to a string.
char *i2s(int64_t i) {
	char *strVal = (char *)malloc(1000000 * sizeof(char));
	int64_t e = sprintf(strVal, "%lld", i);
	if (e < 0) {
		printf("Error: i2s\n");
		exit(1);
	}
	return strVal;
}

// s2f converts a string to a float.
double s2f(char *s) {
	double floatVal;
	int64_t e = sscanf(s, "%lf", &floatVal);
	if (e != 1) {
		printf("Error: s2f\n");
		exit(1);
	}
	return floatVal;
}

// abs returns the absolute value of an integer.
int64_t abs(int64_t i) {
	return (int64_t)fabs((double)i);
}

// max returns the maximum value in a list of integers.
int64_t max(int64_t a, int64_t b) {
	int64_t ans = a;
	if (ans < b) {
		ans = b;
	}
	return ans;
}

// min returns the minimum value in a list of integers.
int64_t min(int64_t a, int64_t b) {
	int64_t ans = a;
	if (ans > b) {
		ans = b;
	}
	return ans;
}

// sum returns the sum of a slice of integers.
int64_t sum(int64_t *i) {
	int64_t sum = 0;
	for (int64_t j = 0; j < i->len; j++) {
		sum += i->ary[j];
	}
	return sum;
}

// split splits a string into a slice of strings.
char **split(char *s) {
	char **strs = (char **)malloc(1000000 * sizeof(char *));
	int64_t i = 0;
	char *token = strtok(s, " ");
	while (token != NULL) {
		strs[i] = (char *)malloc(1000000 * sizeof(char));
		strcpy(strs[i], token);
		i++;
		token = strtok(NULL, " ");
	}
	return strs;
}

// strAry2intAry converts a slice of strings to a slice of integers.
int64_t *strAry2intAry(char **strs) {
	int64_t *res = (int64_t *)malloc(1000000 * sizeof(int64_t));
	int64_t i = 0;
	for (; i < 1000000; i++) {
		res[i] = s2i(strs[i]);
	}
	return res;
}

// intAry2strAry converts a slice of integers to a slice of strings.
char **intAry2strAry(int64_t *nums) {
	char **res = (char **)malloc(1000000 * sizeof(char *));
	int64_t i = 0;
	for (; i < 1000000; i++) {
		res[i] = i2s(nums[i]);
	}
	return res;
}

// ary2str joins a slice of strings into a single string.
char *ary2str(char **strs) {
	char *res = (char *)malloc(1000000 * sizeof(char));
	int64_t i = 0;
	for (; i < 1000000; i++) {
		strcat(res, strs[i]);
		strcat(res, " ");
	}
	return res;
}

// reverse reverses a slice of integers.
int64_t *reverse(int64_t *res) {
	int64_t i, j;
	for (i = 0, j = res->len - 1; i < j; i++, j--) {
		int64_t tmp = res->ary[i];
		res->ary[i] = res->ary[j];
		res->ary[j] = tmp;
	}
	return res;
}

// reverseStr reverses a slice of strings.
char **reverseStr(char **res) {
	int64_t i, j;
	for (i = 0, j = res->len - 1; i < j; i++, j--) {
		char *tmp = res[i];
		res[i] = res[j];
		res[j] = tmp;
	}
	return res;
}

// ini initializes a slice with a specific value.
void ini(int64_t *res, int64_t init) {
	if (res->len == 0) {
		return;
	}
	res->ary[0] = init;
	for (int64_t i = 0; i < res->len; i++) {
		memcpy(res->ary + i, res->ary, i * sizeof(int64_t));
	}
}

// scanInt scans an integer from the scanner.
int64_t scanInt() {
	int64_t read;
	fscanf(scanner, "%lld", &read);
	return read;
}

// scanFloat scans a float from the scanner.
double scanFloat() {
	double read;
	fscanf(scanner, "%lf", &read);
	return read;
}

// scanString scans a string from the scanner.
char *scanString() {
	char *s = (char *)malloc(1000000 * sizeof(char));
	fscanf(scanner, "%s", s);
	return s;
}

// scanStrings scans multiple strings from the scanner.
char **scanStrings() {
	char **s = (char **)malloc(1000000 * sizeof(char *));
	for (int64_t i = 0; i < 1000000; i++) {
		s[i] = (char *)malloc(1000000 * sizeof(char));
		fscanf(scanner, "%s", s[i]);
	}
	return s;
}

// scanInts scans multiple integers from the scanner.
int64_t *scanInts() {
	int64_t *s = (int64_t *)malloc(1000000 * sizeof(int64_t));
	for (int64_t i = 0; i < 1000000; i++) {
		fscanf(scanner, "%lld", &s[i]);
	}
	return s;
}

// scanFloats scans multiple floats from the scanner.
double *scanFloats() {
	double *s = (double *)malloc(1000000 * sizeof(double));
	for (int64_t i = 0; i < 1000000; i++) {
		fscanf(scanner, "%lf", &s[i]);
	}
	return s;
}

// scanRunes scans a slice of runes from the scanner.
char *scanRunes() {
	char *s = (char *)malloc(1000000 * sizeof(char));
	fscanf(scanner, "%s", s);
	return s;
}

// scanLines scans multiple lines of text from the scanner.
char **scanLines() {
	char **s = (char **)malloc(1000000 * sizeof(char *));
	for (int64_t i = 0; i < 100