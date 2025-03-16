#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

// bufReader is a struct to efficiently read input.
typedef struct {
	FILE *r;
	char buf[1024];
	int i;
} bufReader;

// Initialize global reader and writer for input and output operations.
bufReader reader = {
	.r = fopen("input.txt", "r"),
	.i = 0,
};

// next returns the next token (word) from the input.
char *next() {
	if (reader.i >= strlen(reader.buf)) {
		fgets(reader.buf, sizeof(reader.buf), reader.r);
		reader.i = 0;
	}
	char *s = reader.buf + reader.i;
	reader.i += strcspn(s, " \n");
	if (reader.buf[reader.i] == '\n') {
		reader.i++;
	}
	return s;
}

// nextInt64 reads the next token as an int64.
int64_t nextInt64() {
	int64_t i;
	fscanf(reader.r, "%ld", &i);
	return i;
}

// nextInt reads the next token as an int.
int nextInt() {
	return (int) nextInt64();
}

// nextLine is a wrapper for reader.nextLine().
char *nextLine() {
	char *s = reader.buf + reader.i;
	reader.i = strlen(reader.buf);
	return s;
}

// out prints the arguments to the output.
void out(int n,...) {
	va_list args;
	va_start(args, n);
	for (int i = 0; i < n; i++) {
		if (i > 0) {
			printf(" ");
		}
		printf("%d", va_arg(args, int));
	}
	va_end(args);
	printf("\n");
}

// max64 returns the maximum of two int64 values.
int64_t max64(int64_t x, int64_t y) {
	if (x > y) {
		return x;
	}
	return y;
}

// max returns the maximum of two int values.
int max(int x, int y) {
	return (int) max64(x, y);
}

// min64 returns the minimum of two int64 values.
int64_t min64(int64_t x, int64_t y) {
	if (x < y) {
		return x;
	}
	return y;
}

// min returns the minimum of two int values.
int min(int x, int y) {
	return (int) min64(x, y);
}

// abs64 returns the absolute value of an int64.
int64_t abs64(int64_t x) {
	if (x < 0) {
		return -x;
	}
	return x;
}

// abs returns the absolute value of an int.
int abs(int x) {
	return (int) abs64(x);
}

// joinInt64s joins an array of int64 values into a string with a separator.
char *joinInt64s(int64_t *a, int n, char *sep) {
	char *b = malloc(n * 20);
	char *p = b;
	for (int i = 0; i < n; i++) {
		if (i > 0) {
			p += sprintf(p, "%s", sep);
		}
		p += sprintf(p, "%ld", a[i]);
	}
	return b;
}

// joinInts joins an array of int values into a string with a separator.
char *joinInts(int *a, int n, char *sep) {
	char *b = malloc(n * 20);
	char *p = b;
	for (int i = 0; i < n; i++) {
		if (i > 0) {
			p += sprintf(p, "%s", sep);
		}
		p += sprintf(p, "%d", a[i]);
	}
	return b;
}

// divUp64 returns the ceiling of the division of x by y.
int64_t divUp64(int64_t x, int64_t y) {
	return (x + y - 1) / y;
}

// divUp returns the ceiling of the division of x by y.
int divUp(int x, int y) {
	return (int) divUp64(x, y);
}

// gcd64 returns the greatest common divisor of two int64 values.
int64_t gcd64(int64_t x, int64_t y) {
	if (x < y) {
		x, y = y, x;
	}
	while (y!= 0) {
		x, y = y, x % y;
	}
	return x;
}

// gcd returns the greatest common divisor of two int values.
int gcd(int x, int y) {
	return (int) gcd64(x, y);
}

// lcm64 returns the least common multiple of two int64 values.
int64_t lcm64(int64_t x, int64_t y) {
	return x * y / gcd64(x, y);
}

// lcm returns the least common multiple of two int values.
int lcm(int x, int y) {
	return (int) lcm64(x, y);
}

// pow64 returns the result of raising x to the power of y.
int64_t pow64(int64_t x, int64_t y) {
	return (int64_t) pow(x, y);
}

// pow returns the result of raising x to the power of y.
int pow(int x, int y) {
	return (int) pow64(x, y);
}

// main function calls solve and flushes the writer at the end.
int main() {
	solve();
	fclose(reader.r);
	return 0;
}

// solve function implements the main logic of the program.
void solve() {
	int N, _;
	N = nextInt();
	_ = nextInt();
	int *A = malloc(N * sizeof(int));
	for (int i = 0; i < N; i++) {
		A[i] = nextInt();
	}
	int maxProfit = 0;
	int maxCnt = 0;
	int maxA = A[N - 1];
	for (int i = N - 2; i >= 0; i--) {
		int profit = max(0, maxA - A[i]);
		if (maxProfit < profit) {
			maxProfit = profit;
			maxCnt = 1;
		} else if (maxProfit == profit) {
			maxCnt++;
		}
		maxA = max(maxA, A[i]);
	}
	out(maxCnt);
}

