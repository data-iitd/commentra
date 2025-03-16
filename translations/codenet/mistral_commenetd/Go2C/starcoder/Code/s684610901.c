#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a custom type 'pair' for sorting
typedef struct {
	int64_t index; // Index for sorting
	void *p1, *p2; // Two elements to be compared
} pair;

// Define a slice type 'pairs' for sorting 'pair' type
typedef struct {
	pair *data; // Pointer to the underlying array
	int64_t len; // Length of the underlying array
	int64_t cap; // Capacity of the underlying array
} pairs;

// Implement sort.Interface methods for 'pairs' type
int64_t pairsLen(pairs *slice) {
	return slice->len;
}

int64_t pairsLess(pairs *slice, int64_t i, int64_t j) {
	return slice->data[i].index < slice->data[j].index;
}

void pairsSwap(pairs *slice, int64_t i, int64_t j) {
	pair tmp = slice->data[i];
	slice->data[i] = slice->data[j];
	slice->data[j] = tmp;
}

// Define a custom type 'Int64Slice' for sorting int64 slices
typedef struct {
	int64_t *data; // Pointer to the underlying array
	int64_t len; // Length of the underlying array
	int64_t cap; // Capacity of the underlying array
} Int64Slice;

// Implement sort.Interface methods for 'Int64Slice' type
int64_t Int64SliceLen(Int64Slice *slice) {
	return slice->len;
}

int64_t Int64SliceLess(Int64Slice *slice, int64_t i, int64_t j) {
	return slice->data[i] < slice->data[j];
}

void Int64SliceSwap(Int64Slice *slice, int64_t i, int64_t j) {
	int64_t tmp = slice->data[i];
	slice->data[i] = slice->data[j];
	slice->data[j] = tmp;
}

// Define some constants
#define initialBufSize 10000 // Initial buffer size for bufio.NewScanner
#define maxBufSize 1000000 // Maximum buffer size for bufio.NewScanner
#define INF 1000000000 // Infinite value for some calculations

// Initialize some global variables
int64_t A, B, C; // Input A, B, and C
pair *p; // Pointer to an array of pairs
Int64Slice *di, *dj; // Pointer to an array of direction vectors for 2D grid traversal

// Main function
int main() {
	// Initialize the buffer with the given size
	char buf[initialBufSize];
	scanf("%s", buf);
	scanner = bufio.NewScanner(os.Stdin) // Input scanner
	scanner.Buffer(buf, maxBufSize)
	scanner.Split(bufio.ScanWords) // Split input by words

	// Read input A, B, and C
	scanf("%d %d %d", &A, &B, &C);

	// Check if C is within the range of A and B
	if (C >= A && C <= B) {
		printf("Yes\n"); // Print "Yes" if condition is true
	} else {
		printf("No\n");  // Print "No" if condition is false
	}
}

// Helper functions for reading input
void NextPermutation(int64_t *x, int64_t n) {
	// Implementation of next permutation algorithm for sorting
}

int64_t **doubleAry(int64_t h, int64_t w, int64_t init) {
	// Function to initialize a 2D int64 array with given dimensions and initial value
}

int aryEq(int64_t *a, int64_t *b, int64_t n) {
	// Function to check if two arrays are equal
}

int64_t *clone(int64_t *n, int64_t n) {
	// Function to clone a slice
}

void write(char *s) {
	// Function to write a string to the output writer
}

void print() {
	// Function to flush the output writer
}

char *readLine() {
	// Function to read a line from the input scanner
}

int64_t readInt() {
	// Function to read an integer from the input scanner
}

double readFloat() {
	// Function to read a float from the input scanner
}

int64_t *readRunes() {
	// Function to read a rune slice from the input scanner
}

char *readString() {
	// Function to read a string from the input scanner
}

char **readStrings() {
	// Function to read a string slice from the input scanner
}

int64_t s2i(char *s) {
	// Function to convert a string to an integer
}

char *i2s(int64_t i) {
	// Function to convert an integer to a string
}

int64_t abs(int64_t i) {
	// Function to get the absolute value of an integer
}

int64_t max(int64_t a, int64_t b) {
	// Function to get the maximum value from a slice of integers
}

int64_t min(int64_t a, int64_t b) {
	// Function to get the minimum value from a slice of integers
}

int64_t sum(int64_t *i, int64_t n) {
	// Function to get the sum of elements in a slice of integers
}

char **split(char *s) {
	// Function to split a string into a slice of strings using space as delimiter
}

int64_t *strAry2intAry(char **strs, int64_t n) {
	// Function to convert a slice of strings to a slice of integers
}

char **intAry2strAry(int64_t *nums, int64_t n) {
	// Function to convert a slice of integers to a slice of strings
}

char *ary2str(char **strs, int64_t n) {
	// Function to join a slice of strings into a single string using space as delimiter
}

int64_t *reverse(int64_t *res, int64_t n) {
	// Function to reverse the order of elements in a slice
}

char **reverseStr(char **res, int64_t n) {
	// Function to reverse the order of elements in a slice of strings
}

void ini(int *res, int64_t n, int init) {
	// Function to initialize the first element of a slice with a given value
}

// Uncomment the following code if you want to use regexp package
// void regexpExample() {
//     // Your code here!
//     char *str = "13:20"
//     r := regexp.MustCompile(`(\d+):(\d+)`)
//     fmt.Println(r.FindStringSubmatch(str))
// }

// Define a custom type 'Country' with gold, silver, and bronze fields
// typedef struct {
//     int gold;
//     int silver;
//     int bronze;
// } Country;

// Function to sort a slice of 'Country' based on bronze, silver, and gold fields in that order
// Country *stableSortExample() {
//     // Your code here!
// }

