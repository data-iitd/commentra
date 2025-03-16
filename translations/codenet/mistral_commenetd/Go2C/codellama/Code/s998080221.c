
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Function (r *bufReader) readLine reads a line from os.Stdin and stores it in the buffer
void readLine(bufReader *r) {
	// If the index is less than the length of the buffer, it means that there is still some data left in the buffer
	if (r->i < r->bufLen) {
		return;
	}
	// Clear the buffer and set the index to 0
	r->bufLen = 0;
	r->i = 0;
	// Read a line from os.Stdin and store it in the buffer
	while (1) {
		// Read a line from os.Stdin
		char *line = fgets(r->buf, sizeof(r->buf), stdin);
		// If an error occurs during reading, panic with the error message
		if (line == NULL) {
			fprintf(stderr, "Error reading from stdin\n");
			exit(1);
		}
		// If the line is not a prefix (i.e., it is a complete line), break the loop
		if (strchr(line, '\n') != NULL) {
			break;
		}
		// Append the line to the buffer
		r->bufLen += strlen(line);
	}
}

// Function (r *bufReader) next returns the next token (i.e., a word or a number) from the buffer
char *next(bufReader *r) {
	// Read a line from the buffer
	readLine(r);
	// Find the index of the first whitespace character in the line
	int from = r->i;
	// Iterate through the line until a whitespace character is found
	while (r->i < r->bufLen) {
		// If the current character is a whitespace character, break the loop
		if (r->buf[r->i] == ' ') {
			break;
		}
		// Increment the index
		r->i++;
	}
	// Return the substring from the start index to the current index
	char *s = malloc(r->i - from + 1);
	strncpy(s, r->buf + from, r->i - from);
	s[r->i - from] = '\0';
	// Increment the index
	r->i++;
	// Return the token
	return s;
}

// Function nextInt64 parses an integer from the custom reader and returns it as an int64 type
int64_t nextInt64() {
	// Parse an integer from the custom reader and return it as an int64 type
	int64_t i;
	char *s = next(reader);
	int err = sscanf(s, "%lld", &i);
	// If an error occurs during parsing, panic with the error message
	if (err != 1) {
		fprintf(stderr, "Error parsing integer from stdin\n");
		exit(1);
	}
	// Return the integer
	return i;
}

// Function nextInt parses an integer from the custom reader and returns it as an int type
int nextInt() {
	// Parse an integer from the custom reader and return it as an int type
	return (int)nextInt64();
}

// Function nextLine reads a line from the custom reader and returns it as a string
char *nextLine() {
	// Read a line from the custom reader and return it as a string
	readLine(reader);
	// Return the substring from the current index to the end of the buffer
	char *s = malloc(reader->bufLen - reader->i + 1);
	strncpy(s, reader->buf + reader->i, reader->bufLen - reader->i);
	s[reader->bufLen - reader->i] = '\0';
	// Set the index to the end of the buffer
	reader->i = reader->bufLen;
	// Return the line
	return s;
}

// Function out is used for printing output to the console
void out(char *s) {
	// Write the formatted output to the bufio.Writer
	fprintf(stdout, "%s\n", s);
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
	return (int)max64((int64_t)x, (int64_t)y);
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
	return (int)min64((int64_t)x, (int64_t)y);
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
	return (int)abs64((int64_t)x);
}

// Function joinInt64s joins an array of int64 values with a given separator and returns the resulting string
char *joinInt64s(int64_t *a, int n, char *sep) {
	// Create a slice of strings by converting each int64 value to a string
	char **b = malloc(n * sizeof(char *));
	// Iterate through the array and convert each int64 value to a string
	for (int i = 0; i < n; i++) {
		b[i] = malloc(20);
		sprintf(b[i], "%lld", a[i]);
	}
	// Join the strings in the slice with the given separator and return the resulting string
	char *s = malloc(1000000);
	strcpy(s, b[0]);
	for (int i = 1; i < n; i++) {
		strcat(s, sep);
		strcat(s, b[i]);
	}
	// Free the memory allocated for the slice of strings
	for (int i = 0; i < n; i++) {
		free(b[i]);
	}
	free(b);
	// Return the resulting string
	return s;
}

// Function joinInts joins an array of int values with a given separator and returns the resulting string
char *joinInts(int *a, int n, char *sep) {
	// Create a slice of strings by converting each int value to a string
	char **b = malloc(n * sizeof(char *));
	// Iterate through the array and convert each int value to a string
	for (int i = 0; i < n; i++) {
		b[i] = malloc(20);
		sprintf(b[i], "%d", a[i]);
	}
	// Join the strings in the slice with the given separator and return the resulting string
	char *s = malloc(1000000);
	strcpy(s, b[0]);
	for (int i = 1; i < n; i++) {
		strcat(s, sep);
		strcat(s, b[i]);
	}
	// Free the memory allocated for the slice of strings
	for (int i = 0; i < n; i++) {
		free(b[i]);
	}
	free(b);
	// Return the resulting string
	return s;
}

// Function divUp64 returns the smallest integer n such that n*divisor >= dividend
int64_t divUp64(int64_t x, int64_t y) {
	// Return the smallest integer n such that n*divisor >= dividend
	return (x + y - 1) / y;
}

// Function divUp returns the smallest integer n such that n*divisor >= dividend
int divUp(int x, int y) {
	// Return the smallest integer n such that n*divisor >= dividend
	return (int)divUp64((int64_t)x, (int64_t)y);
}

// Function gcd64 returns the greatest common divisor of two int64 values
int64_t gcd64(int64_t x, int64_t y) {
	// If x is greater than y, swap x and y
	if (x < y) {
		x = y;
		y = x;
	}
	// Iterate through the range of possible divisors
	while (y != 0) {
		// Calculate the remainder of x/y
		x = y;
		y = x % y;
	}
	// Return x as the greatest common divisor
	return x;
}

// Function gcd returns the greatest common divisor of two int values
int gcd(int x, int y) {
	// Return the greatest common divisor of x and y as an int value
	return (int)gcd64((int64_t)x, (int64_t)y);
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
	return (int)lcm64((int64_t)x, (int64_t)y);
}

// Function pow64 returns x raised to the power of y as an int64 value
int64_t pow64(int64_t x, int64_t y) {
	// Return x raised to the power of y as an int64 value using the math.Pow function
	return (int64_t)pow((double)x, (double)y);
}

// Function pow returns x raised to the power of y as an int value
int pow(int x, int y) {
	// Return x raised to the power of y as an int value
	return (int)pow64((int64_t)x, (int64_t)y);
}

// Function main is the entry point of the program
int main() {
	// Call the solve function to solve the problem
	solve();
	// Flush the bufio.Writer to write the output to the console
	fflush(stdout);
	// Return 0 to indicate success
	return 0;
}

// Function solve reads input from the custom reader, processes it, and writes the output to the bufio.Writer
void solve() {
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
	out(joinInts(&maxCnt, 1, " "));
}

