#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
#include <stdarg.h>
#include <ctype.h>
#include <limits.h>
#include <float.h>
#include <time.h>
#include <assert.h>

#define initialBufSize 10000
#define maxBufSize 10000000
#define INF 100000000

// Define a structure for sorting pairs
typedef struct {
	int64_t index;
	void *p1;
	void *p2;
} pair;

// Implement sort.Interface for pairs
int pairs_len(pairs *slice) {
	return slice->len;
}

int pairs_less(pairs *slice, int i, int j) {
	return slice->pairs[i].index < slice->pairs[j].index;
}

void pairs_swap(pairs *slice, int i, int j) {
	pair tmp = slice->pairs[i];
	slice->pairs[i] = slice->pairs[j];
	slice->pairs[j] = tmp;
}

// Define a structure for sorting int64 slices
typedef struct {
	int64_t *ary;
	int64_t len;
} Int64Slice;

// Implement sort.Interface for Int64Slice
int Int64Slice_len(Int64Slice *slice) {
	return slice->len;
}

int Int64Slice_less(Int64Slice *slice, int i, int j) {
	return slice->ary[i] < slice->ary[j];
}

void Int64Slice_swap(Int64Slice *slice, int i, int j) {
	int64_t tmp = slice->ary[i];
	slice->ary[i] = slice->ary[j];
	slice->ary[j] = tmp;
}

// Utility functions for sorting int64 slices
void Int64s(int64_t *ary, int64_t len) {
	sort(ary, len);
}

bool Int64sSliceAreSorted(int64_t *ary, int64_t len) {
	return is_sorted(ary, len);
}

// Global variables for input/output handling and direction vectors
FILE *scanner;
FILE *writer;
int64_t di[] = {-1, 0, 1, 0}; // Direction vectors for row movement
int64_t dj[] = {0, -1, 0, 1}; // Direction vectors for column movement

// Utility functions for reading input
int64_t readInt() {
	char *line = NULL;
	size_t size = 0;
	getline(&line, &size, scanner);
	int64_t read = strtol(line, NULL, 10);
	free(line);
	return read;
}

// Utility functions for writing output
void write(char *s) {
	fprintf(writer, "%s", s);
}

void print() {
	fflush(writer);
}

char *readLine() {
	char *line = NULL;
	size_t size = 0;
	getline(&line, &size, scanner);
	return line;
}

// Utility functions for reading input
int64_t s2i(char *s) {
	int64_t intVal = strtol(s, NULL, 10);
	return intVal;
}

// Utility functions for reading input
char *i2s(int64_t i) {
	char *strVal = malloc(sizeof(char) * 100);
	sprintf(strVal, "%ld", i);
	return strVal;
}

// Utility functions for reading input
double s2f(char *s) {
	double floatVal = strtod(s, NULL);
	return floatVal;
}

// Utility functions for reading input
int64_t abs(int64_t i) {
	return labs(i);
}

// Utility functions for reading input
int64_t max(int64_t a, int64_t b) {
	return a > b ? a : b;
}

// Utility functions for reading input
int64_t min(int64_t a, int64_t b) {
	return a < b ? a : b;
}

// Utility functions for reading input
int64_t sum(int64_t *i, int64_t len) {
	int64_t sum = 0;
	for (int64_t j = 0; j < len; j++) {
		sum += i[j];
	}
	return sum;
}

// Utility functions for reading input
char **split(char *s) {
	char **res = malloc(sizeof(char *) * 100);
	int64_t i = 0;
	char *token = strtok(s, " ");
	while (token != NULL) {
		res[i] = token;
		i++;
		token = strtok(NULL, " ");
	}
	return res;
}

// Utility functions for reading input
int64_t *strAry2intAry(char **strs, int64_t len) {
	int64_t *res = malloc(sizeof(int64_t) * len);
	for (int64_t i = 0; i < len; i++) {
		res[i] = s2i(strs[i]);
	}
	return res;
}

// Utility functions for reading input
char **intAry2strAry(int64_t *nums, int64_t len) {
	char **res = malloc(sizeof(char *) * len);
	for (int64_t i = 0; i < len; i++) {
		res[i] = i2s(nums[i]);
	}
	return res;
}

// Utility functions for reading input
char *ary2str(char **strs, int64_t len) {
	char *res = malloc(sizeof(char) * 10000);
	for (int64_t i = 0; i < len; i++) {
		strcat(res, strs[i]);
		strcat(res, " ");
	}
	return res;
}

// Utility functions for reading input
int64_t *reverse(int64_t *res, int64_t len) {
	for (int64_t i = 0, j = len - 1; i < j; i++, j--) {
		int64_t tmp = res[i];
		res[i] = res[j];
		res[j] = tmp;
	}
	return res;
}

// Utility functions for reading input
char **reverseStr(char **res, int64_t len) {
	for (int64_t i = 0, j = len - 1; i < j; i++, j--) {
		char *tmp = res[i];
		res[i] = res[j];
		res[j] = tmp;
	}
	return res;
}

// Utility functions for reading input
void ini(int64_t *res, int64_t len, int64_t init) {
	if (len == 0) {
		return;
	}
	res[0] = init;
	for (int64_t i = 0; i < len; i++) {
		memmove(res + i, res, i * sizeof(int64_t));
	}
}

// Uncomment the following function to see a regex example
// void regexpExample() {
//     // Your code here!
//     char *str = "13:20";
//     regex_t r;
//     regcomp(&r, "(\\d+):(\\d+)", 0);
//     regmatch_t pmatch[3];
//     regexec(&r, str, 3, pmatch, 0);
//     printf("%s\n", str + pmatch[1].rm_so);
//     printf("%s\n", str + pmatch[2].rm_so);
// }

// Uncomment the following struct and function to see a stable sort example
// typedef struct {
//     int64_t gold;
//     int64_t silver;
//     int64_t blonze;
// } Country;

// // Example of stable sorting
// Country *stableSortExample() {
//     Country *country = malloc(sizeof(Country) * 4);
//     country[0].gold = 1;
//     country[0].silver = 2;
//     country[0].blonze = 3;
//     country[1].gold = 1;
//     country[1].silver = 2;
//     country[1].blonze = 3;
//     country[2].gold = 1;
//     country[2].silver = 3;
//     country[2].blonze = 2;
//     country[3].gold = 1;
//     country[3].silver = 3;
//     country[3].blonze = 3;
//     stable_sort(country, 4, sizeof(Country), (int (*)(const void *, const void *))compare_blonze);
//     stable_sort(country, 4, sizeof(Country), (int (*)(const void *, const void *))compare_silver);
//     stable_sort(country, 4, sizeof(Country), (int (*)(const void *, const void *))compare_gold);
//     return country;
// }

// int compare_blonze(const void *a, const void *b) {
//     return ((Country *)a)->blonze - ((Country *)b)->blonze;
// }

// int compare_silver(const void *a, const void *b) {
//     return ((Country *)a)->silver - ((Country *)b)->silver;
// }

// int compare_gold(const void *a, const void *b) {
//     return ((Country *)a)->gold - ((Country *)b)->gold;
// }

int main() {
	// Set up the scanner buffer and read three integers A, B, C
	char *buf = malloc(sizeof(char) * initialBufSize);
	scanner = fmemopen(buf, initialBufSize, "r");
	writer = fmemopen(buf, initialBufSize, "w");
	int64_t A = readInt();
	int64_t B = readInt();
	int64_t C = readInt();
	
	// Check if C is within the range [A, B] and print the result
	if (C >= A && C <= B) {
		write("Yes\n");
	} else {
		write("No\n");
	}
	print();
	return 0;
}

// 