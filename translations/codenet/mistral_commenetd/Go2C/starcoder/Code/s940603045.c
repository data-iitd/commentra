#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constants and variables declaration
const int inf = INT_MAX; // Constants for maximum signed integer value

// var mod = 1000000007; // Unused constant, can be removed

int dx[9] = {0, 1, 1, 1, 0, -1, -1, -1, 0}; // 8 directions for movement
int dy[9] = {1, 1, 0, -1, -1, -1, 0, 1, 0};

// Global variables declaration
char buf[10000]; // Global buffer for storing the input line
int p = 0;        // Position in the buffer

// ---------------------------------------------------------

// init function initializes the program
void init() {
	setbuf(stdout, NULL); // Disable buffering for stdout
}

// main function is the entry point of the program
int main() {
	// Read input N as a string
	scanf("%s", buf);
	// Convert N to an integer
	int n = 0;
	for (int i = 0; buf[i]; i++) {
		n += buf[i] - '0'; // Convert each digit to an integer and add to the sum
	}
	// Read input m as an integer
	int m;
	scanf("%d", &m);
	// Check if m is divisible by n
	if (m % n == 0) {
		printf("Yes\n"); // Print "Yes" if m is divisible by n
	} else {
		printf("No\n"); // Print "No" if m is not divisible by n
	}
}

// ---------------------------------------------------------

// Pair type definition for storing two integers
typedef struct {
	int a, b;
} Pair;

// Pairs type definition for storing a slice of Pair
typedef struct {
	Pair p[10000]; // Array of Pairs
	int n;         // Number of Pairs
} Pairs;

// Implement Len, Swap, and Less methods for sorting Pairs based on the second element
int Len(Pairs p) {
	return p.n;
}
void Swap(Pairs p, int i, int j) {
	Pair t = p.p[i];
	p.p[i] = p.p[j];
	p.p[j] = t;
}
int Less(Pairs p, int i, int j) {
	return p.p[i].b < p.p[j].b; // Sort based on the second element
}

// ------int methods-------------------------
int in(int c, int a, int z) {
	return c >= a && c < z; // Check if c is within the range [a, z)
}
int out(int c, int a, int z) {
	return!in(c, a, z); // Check if c is outside the range [a, z)
}
int btoi(int b) {
	return b? 1 : 0; // Convert boolean to integer: 1 for true, 0 for false
}
int itob(int a) {
	return a!= 0; // Convert integer to boolean: true for non-zero, false for zero
}
int max(int a, int b) {
	return a > b? a : b; // Find the maximum integer among the given integers
}
int min(int a, int b) {
	return a < b? a : b; // Find the minimum integer among the given integers
}
int sum(int a[], int n) {
	int r = 0;
	for (int i = 0; i < n; i++) {
		r += a[i]; // Calculate the sum of all integers in the given array
	}
	return r;
}
int pro(int a[], int n) {
	int r = 1;
	for (int i = 0; i < n; i++) {
		r *= a[i]; // Calculate the product of all integers in the given array
	}
	return r;
}

void fill(int a[], int n, int v) {
	for (int i = 0; i < n; i++) {
		a[i] = v; // Fill the given array with the given integer value
	}
}
void minmax(int a, int b, int *min, int *max) {
	if (a > b) {
		*min = b;
		*max = a; // Return the minimum and maximum integers among the given integers
	} else {
		*min = a;
		*max = b;
	}
}

int abs(int a) {
	return a < 0? -a : a; // Calculate the absolute value of an integer
}

// ---------- buffered scanner -----------------------------------------
void newScanner() {
	p = 0; // Initialize the position in the buffer
}
char next() {
	while (p < strlen(buf)) {
		if (buf[p] =='') {
			p++; // Increment the position in the buffer
			break;
		}
		p++;
	}
	char result[10000];
	int start = p;
	while (p < strlen(buf)) {
		if (buf[p] =='') {
			break; // Find the position of the next whitespace character
		}
		p++;
	}
	int end = p;
	strncpy(result, buf + start, end - start);
	result[end - start] = 0;
	p++;
	return result;
}
char Line() {
	char result[10000];
	int start = p;
	p = strlen(buf);
	strncpy(result, buf + start, p - start);
	result[p - start] = 0;
	return result;
}
char String() {
	return next(); // Call next() method to read the next token as a string
}
int Int() {
	int v;
	scanf("%d", &v);
	return v;
}
int Ints(int n) {
	int r[10000];
	for (int i = 0; i < n; i++) {
		r[i] = Int(); // Read and store n integers in the array
	}
	return r;
}
int Int64() {
	int64_t v;
	scanf("%lld", &v);
	return v;
}
int Uint64() {
	uint64_t v;
	scanf("%llu", &v);
	return v;
}
double Float64() {
	double v;
	scanf("%lf", &v);
	return v;
}

// 