
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Define a custom type 'pair' for sorting
typedef struct {
    int index;
    int p1;
    int p2;
} pair;

// Define a slice type 'pairs' for sorting 'pair' type
typedef struct {
    int len;
    pair *data;
} pairs;

// Implement sort.Interface methods for 'pairs' type
int pairs_len(pairs *slice) {
    return slice->len;
}

int pairs_less(pairs *slice, int i, int j) {
    return slice->data[i].index < slice->data[j].index;
}

void pairs_swap(pairs *slice, int i, int j) {
    pair temp = slice->data[i];
    slice->data[i] = slice->data[j];
    slice->data[j] = temp;
}

// Define a custom type 'Int64Slice' for sorting int64 slices
typedef struct {
    int len;
    int64_t *data;
} Int64Slice;

// Implement sort.Interface methods for 'Int64Slice' type
int Int64Slice_len(Int64Slice *slice) {
    return slice->len;
}

int Int64Slice_less(Int64Slice *slice, int i, int j) {
    return slice->data[i] < slice->data[j];
}

void Int64Slice_swap(Int64Slice *slice, int i, int j) {
    int64_t temp = slice->data[i];
    slice->data[i] = slice->data[j];
    slice->data[j] = temp;
}

// Define some constants
const int initialBufSize = 1e4; // Initial buffer size for bufio.NewScanner
const int maxBufSize = 1e8; // Maximum buffer size for bufio.NewScanner
const int INF = 1e8; // Infinite value for some calculations

// Initialize some global variables
FILE *scanner; // Input scanner
FILE *writer; // Output writer
int di[] = {-1, 0, 1, 0}; // Direction vectors for 2D grid traversal
int dj[] = {0, -1, 0, 1}; // Direction vectors for 2D grid traversal

// Main function
int main() {
    // Initialize the buffer with the given size
    char *buf = (char *)malloc(initialBufSize * sizeof(char));
    scanner = fopen("input.txt", "r");
    writer = fopen("output.txt", "w");
    fscanf(scanner, "%s", buf);
    fclose(scanner);
    fclose(writer);

    // Read input A, B, and C
    int A, B, C;
    fscanf(scanner, "%d %d %d", &A, &B, &C);

    // Check if C is within the range of A and B
    if (C >= A && C <= B) {
        fprintf(writer, "Yes\n"); // Print "Yes" if condition is true
    } else {
        fprintf(writer, "No\n"); // Print "No" if condition is false
    }

    return 0;
}

// Helper functions for reading input
int NextPermutation(int *x) {
    // Implementation of next permutation algorithm for sorting
}

int **doubleAry(int h, int w, int init) {
    // Function to initialize a 2D int64 array with given dimensions and initial value
}

int aryEq(int *a, int *b) {
    // Function to check if two arrays are equal
}

int *clone(int *n) {
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

int readInt() {
    // Function to read an integer from the input scanner
}

double readFloat() {
    // Function to read a float from the input scanner
}

char *readRunes() {
    // Function to read a rune slice from the input scanner
}

char *readString() {
    // Function to read a string from the input scanner
}

char **readStrings() {
    // Function to read a string slice from the input scanner
}

int s2i(char *s) {
    // Function to convert a string to an integer
}

char *i2s(int i) {
    // Function to convert an integer to a string
}

int abs(int i) {
    // Function to get the absolute value of an integer
}

int max(int a, int b) {
    // Function to get the maximum value from a slice of integers
}

int min(int a, int b) {
    // Function to get the minimum value from a slice of integers
}

int sum(int *i) {
    // Function to get the sum of elements in a slice of integers
}

char **split(char *s) {
    // Function to split a string into a slice of strings using space as delimiter
}

int *strAry2intAry(char **strs) {
    // Function to convert a slice of strings to a slice of integers
}

char **intAry2strAry(int *nums) {
    // Function to convert a slice of integers to a slice of strings
}

char *ary2str(char **strs) {
    // Function to join a slice of strings into a single string using space as delimiter
}

int *reverse(int *res) {
    // Function to reverse the order of elements in a slice
}

char **reverseStr(char **res) {
    // Function to reverse the order of elements in a slice of strings
}

void ini(int *res, int init) {
    // Function to initialize the first element of a slice with a given value
}

// Uncomment the following code if you want to use regexp package
// void regexpExample() {
//     // Your code here!
//     char *str = "13:20";
//     regex_t r;
//     regcomp(&r, "(\\d+):(\\d+)", 0);
//     regmatch_t pmatch[3];
//     regexec(&r, str, 3, pmatch, 0);
//     printf("%s\n", str);
// }

// Define a custom type 'Country' with gold, silver, and bronze fields
// typedef struct {
//     int gold;
//     int silver;
//     int blonze;
// } Country;

// Function to sort a slice of 'Country' based on bronze, silver, and gold fields in that order
// Country *stableSortExample() {
//     // Your code here!
// }

