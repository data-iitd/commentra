
#include <stdio.h>
#include <stdlib.h>

// Define a custom type 'pair' for sorting
typedef struct {
    int index;
    int p1;
    int p2;
} pair;

// Define a slice type 'pairs' for sorting 'pair' type
typedef pair* pairs;

// Implement sort.Interface methods for 'pairs' type
int pairsLen(pairs slice) {
    return slice->len;
}

int pairsLess(pairs slice, int i, int j) {
    return slice[i].index < slice[j].index;
}

void pairsSwap(pairs slice, int i, int j) {
    pair temp = slice[i];
    slice[i] = slice[j];
    slice[j] = temp;
}

// Define a custom type 'Int64Slice' for sorting int64 slices
typedef long* Int64Slice;

// Implement sort.Interface methods for 'Int64Slice' type
int Int64SliceLen(Int64Slice slice) {
    return slice->len;
}

int Int64SliceLess(Int64Slice slice, int i, int j) {
    return slice[i] < slice[j];
}

void Int64SliceSwap(Int64Slice slice, int i, int j) {
    long temp = slice[i];
    slice[i] = slice[j];
    slice[j] = temp;
}

// Define some constants
#define initialBufSize 1e4 // Initial buffer size for bufio.NewScanner
#define maxBufSize    1e8 // Maximum buffer size for bufio.NewScanner
#define INF           1e8 // Infinite value for some calculations

// Initialize some global variables
char buf[maxBufSize];
FILE *scanner = fmemopen(buf, initialBufSize, "r+");
FILE *writer = stdout;
int di[] = {-1, 0, 1, 0}; // Direction vectors for 2D grid traversal
int dj[] = {0, -1, 0, 1}; // Direction vectors for 2D grid traversal

int main() {
    // Initialize the buffer with the given size
    fseek(scanner, 0, SEEK_END);
    int size = ftell(scanner);
    fseek(scanner, 0, SEEK_SET);
    fread(buf, 1, size, scanner);

    // Read input A, B, and C
    int A, B, C;
    fscanf(scanner, "%d %d %d", &A, &B, &C);

    // Check if C is within the range of A and B
    if (C >= A && C <= B) {
        fprintf(writer, "Yes\n"); // Print "Yes" if condition is true
    } else {
        fprintf(writer, "No\n");  // Print "No" if condition is false
    }

    return 0;
}

// Helper functions for reading input
int NextPermutation(int *x, int n) {
    // Implementation of next permutation algorithm for sorting
}

int **doubleAry(int h, int w, int init) {
    // Function to initialize a 2D int array with given dimensions and initial value
}

int aryEq(int *a, int *b, int n) {
    // Function to check if two arrays are equal
}

int *clone(int *n, int size) {
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

float readFloat() {
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

int max(int *i, int n) {
    // Function to get the maximum value from a slice of integers
}

int min(int *i, int n) {
    // Function to get the minimum value from a slice of integers
}

int sum(int *i, int n) {
    // Function to get the sum of elements in a slice of integers
}

char **split(char *s) {
    // Function to split a string into a slice of strings using space as delimiter
}

int *strAry2intAry(char **strs, int n) {
    // Function to convert a slice of strings to a slice of integers
}

char **intAry2strAry(int *nums, int n) {
    // Function to convert a slice of integers to a slice of strings
}

char *ary2str(char **strs, int n) {
    // Function to join a slice of strings into a single string using space as delimiter
}

void reverse(int *res, int n) {
    // Function to reverse the order of elements in a slice
}

void reverseStr(char **res, int n) {
    // Function to reverse the order of elements in a slice of strings
}

void ini(int *res, int init, int n) {
    // Function to initialize the first element of a slice with a given value
}

// Uncomment the following code if you want to use regexp package
// void regexpExample() {
//     // Your code here!
//     char *str = "13:20";
//     regex_t r;
//     int reti;
//     char errbuf[100];
//     reti = regcomp(&r, "([0-9]+):([0-9]+)", 0);
//     if (reti) {
//         regerror(reti, &r, errbuf, sizeof(errbuf));
//         fprintf(stderr, "Could not compile regex\n");
//         exit(1);
//     }
//     regmatch_t matches[2];
//     reti = regexec(&r, str, 2, matches, 0);
//     if (!reti) {
//         char *hour = malloc(matches[1].rm_eo - matches[1].rm_so + 1);
//         strncpy(hour, str + matches[1].rm_so, matches[1].rm_eo - matches[1].rm_so);
//         hour[matches[1].rm_eo - matches[1].rm_so] = '\0';
//         char *minute = malloc(matches[2].rm_eo - matches[2].rm_so + 1);
//         strncpy(minute, str + matches[2].rm_so, matches[2].rm_eo - matches[2].rm_so);
//         minute[matches[2].rm_eo - matches[2].rm_so] = '\0';
//         printf("Hour: %s, Minute: %s\n", hour, minute);
//         free(hour);
//         free(minute);
//     } else {
//         char errbuf[100];
//         regerror(reti, &r, errbuf, sizeof(errbuf));
//         fprintf(stderr, "Match failed: %s\n", errbuf);
//     }
//     regfree(&r);
// }

// Define a custom type 'Country' with gold, silver, and bronze fields
// typedef struct {
//     int gold;
//     int silver;
//     int bronze;
// } Country;

// Function to sort a slice of 'Country' based on bronze, silver, and gold fields in that order
// Country* stableSortExample() {
//     // Your code here!
//     Country countries[3] = {
//         {1, 2, 3},
//         {3, 2, 1},
//         {2, 3, 1}
//     };
//     qsort(countries, 3, sizeof(Country), cmpfunc);
//     return countries;
// }

// int cmpfunc(const void *a, const void *b) {
//     Country *c1 = (Country*)a;
//     Country *c2 = (Country*)b;

//     if (c1->bronze == c2->bronze) {
//         if (c1->silver == c2->silver) {
//             return c1->gold - c2->gold;
//         } else {
//             return c1->silver - c2->silver;
//         }
//     } else {
//         return c1->bronze - c2->bronze;
//     }
// }