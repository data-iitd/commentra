
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// bufReader type is a custom reader that reads lines from os.Stdin
typedef struct {
	char *buf;
	size_t size;
	size_t pos;
} bufReader;

// Function (r *bufReader) readLine reads a line from os.Stdin and stores it in the buffer
void (r *bufReader) readLine() {
	// If the buffer is not empty, return
	if (r->pos < r->size) {
		return;
	}
	// Clear the buffer
	free(r->buf);
	// Allocate a new buffer of size 1024
	r->buf = malloc(1024);
	// Read a line from os.Stdin and store it in the buffer
	r->size = fread(r->buf, 1, 1024, stdin);
	// Set the position to 0
	r->pos = 0;
}

// Function (r *bufReader) next returns the next token (i.e., a word or a number) from the buffer
char * (r *bufReader) next() {
	// Read a line from the buffer
	r->readLine();
	// Find the index of the first whitespace character in the line
	size_t from = r->pos;
	// Iterate through the line until a whitespace character is found
	while (r->pos < r->size && r->buf[r->pos]!='') {
		// Increment the position
		r->pos++;
	}
	// Return the substring from the start index to the current index
	char *s = malloc(r->pos - from + 1);
	memcpy(s, r->buf + from, r->pos - from);
	s[r->pos - from] = '\0';
	// Increment the position
	r->pos++;
	// Return the token
	return s;
}

// Function nextLine returns the next line from the buffer
char * nextLine() {
	// Read a line from the buffer
	readLine();
	// Return the substring from the current index to the end of the buffer
	char *s = malloc(r->size - r->pos + 1);
	memcpy(s, r->buf + r->pos, r->size - r->pos);
	s[r->size - r->pos] = '\0';
	// Set the position to the end of the buffer
	r->pos = r->size;
	// Return the line
	return s;
}

// Function nextInt64 parses an integer from the custom reader and returns it as an int64 type
int64_t nextInt64() {
	// Parse an integer from the custom reader and return it as an int64 type
	int64_t i;
	scanf("%lld", &i);
	return i;
}

// Function nextInt parses an integer from the custom reader and returns it as an int type
int nextInt() {
	// Parse an integer from the custom reader and return it as an int type
	return (int) nextInt64();
}

// Function out is used for printing output to the console
void out(int64_t a,...) {
	// Write the formatted output to the console
	va_list args;
	va_start(args, a);
	vprintf(a, args);
	va_end(args);
	printf("\n");
}

// Function max64 returns the maximum of two int64 values
int64_t max64(int64_t x, int64_t y) {
	// If x is greater than y, return x; otherwise, return y
	if (x > y) {
		return x;
	}
	return y;
}

// Function max returns the maximum of two int values
int max(int x, int y) {
	// Return the maximum of x and y as an int value
	return (int) max64(x, y);
}

// Function min64 returns the minimum of two int64 values
int64_t min64(int64_t x, int64_t y) {
	// If x is less than y, return x; otherwise, return y
	if (x < y) {
		return x;
	}
	return y;
}

// Function min returns the minimum of two int values
int min(int x, int y) {
	// Return the minimum of x and y as an int value
	return (int) min64(x, y);
}

// Function abs64 returns the absolute value of an int64 value
int64_t abs64(int64_t x) {
	// If x is negative, return the negative of x; otherwise, return x
	if (x < 0) {
		return -x;
	}
	return x;
}

// Function abs returns the absolute value of an int value
int abs(int x) {
	// Return the absolute value of x as an int value
	return (int) abs64(x);
}

// Function joinInt64s joins an array of int64 values with a given separator and returns the resulting string
char * joinInt64s(int64_t *a, size_t n, char *sep) {
	// Create a string buffer
	char *b = malloc(n * 20);
	// Iterate through the array and convert each int64 value to a string
	for (size_t i = 0; i < n; i++) {
		// If i is not the first element, append the separator
		if (i > 0) {
			strcat(b, sep);
		}
		// Convert the int64 value to a string and append it to the string buffer
		strcat(b, (char *) malloc(20));
		sprintf(b + strlen(b), "%lld", a[i]);
	}
	// Return the string buffer
	return b;
}

// Function joinInts joins an array of int values with a given separator and returns the resulting string
char * joinInts(int *a, size_t n, char *sep) {
	// Create a string buffer
	char *b = malloc(n * 20);
	// Iterate through the array and convert each int value to a string
	for (size_t i = 0; i < n; i++) {
		// If i is not the first element, append the separator
		if (i > 0) {
			strcat(b, sep);
		}
		// Convert the int value to a string and append it to the string buffer
		strcat(b, (char *) malloc(20));
		sprintf(b + strlen(b), "%d", a[i]);
	}
	// Return the string buffer
	return b;
}

// Function divUp64 returns the smallest integer n such that n*divisor >= dividend
int64_t divUp64(int64_t x, int64_t y) {
	// Return the smallest integer n such that n*divisor >= dividend
	return (x + y - 1) / y;
}

// Function divUp returns the smallest integer n such that n*divisor >= dividend
int divUp(int x, int y) {
	// Return the smallest integer n such that n*divisor >= dividend
	return (int) divUp64(x, y);
}

// Function gcd64 returns the greatest common divisor of two int64 values
int64_t gcd64(int64_t x, int64_t y) {
	// If x is greater than y, swap x and y
	if (x < y) {
		x, y = y, x;
	}
	// Iterate through the range of possible divisors
	while (y!= 0) {
		// Calculate the remainder of x/y
		x, y = y, x % y;
	}
	// Return x as the greatest common divisor
	return x;
}

// Function gcd returns the greatest common divisor of two int values
int gcd(int x, int y) {
	// Return the greatest common divisor of x and y as an int value
	return (int) gcd64(x, y);
}

// Function lcm64 returns the least common multiple of two int64 values
int64_t lcm64(int64_t x, int64_t y) {
	// Calculate the greatest common divisor of x and y
	int64_t gcd = gcd64(x, y);
	// Return the product of x and y divided by their greatest common divisor
	return x * y / gcd;
}

// Function lcm returns the least common multiple of two int values
int lcm(int x, int y) {
	// Return the least common multiple of x and y as an int value
	return (int) lcm64(x, y);
}

// Function pow64 returns x raised to the power of y as an int64 value
int64_t pow64(int64_t x, int64_t y) {
	// Return x raised to the power of y as an int64 value using the math.Pow function
	return (int64_t) pow(x, y);
}

// Function pow returns x raised to the power of y as an int value
int pow(int x, int y) {
	// Return x raised to the power of y as an int value
	return (int) pow64(x, y);
}

// Function main is the entry point of the program
int main() {
	// Read two integers N and K from the custom reader
	int N = nextInt();
	int K = nextInt();
	// Initialize an array A of size N
	int *A = malloc(N * sizeof(int));
	// Read N integers from the custom reader and store them in the array A
	for (int i = 0; i < N; i++) {
		A[i] = nextInt();
	}
	// Initialize variables maxProfit, maxCnt, and maxA
	int maxProfit = 0;
	int maxCnt = 0;
	int maxA = A[N - 1];
	// Iterate through the array A from the last index to the first index
	for (int i = N - 2; i >= 0; i--) {
		// Calculate the profit of the current transaction
		int profit = max(0, maxA - A[i]);
		// If the current profit is greater than the maximum profit found so far, update maxProfit and maxCnt
		if (maxProfit < profit) {
			maxProfit = profit;
			maxCnt = 1;
		} else if (maxProfit == profit) {
			maxCnt++;
		}
		// Update maxA with the maximum of the current element and maxA
		maxA = max(maxA, A[i]);
	}
	// Write the output to the console
	out(maxCnt);
}

