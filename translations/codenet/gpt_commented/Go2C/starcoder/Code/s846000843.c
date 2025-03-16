

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <inttypes.h>
#include <assert.h>

#define MAX_N 1000000

// Function declarations
int Abs(int a);
int Pow(int p, int q);
int Min(int nums[], int n);
int Max(int nums[], int n);
int SortAsc(int a[], int n);
int SortDesc(int a[], int n);
int GCD(int a, int b);
int LCM(int a, int b);
int CumSum(int nums[], int n);
int BisectLeft(int nums[], int left, int right, int target);
int Permutations(int nums[], int n);
int PowerSet(int nums[], int n);
int Combination(int nums[], int n, int k);
int CombinationCount(int n, int m, int maxInput);
int Fact(int n);
int Divisors(int n);

// Function definitions
int Abs(int a) {
	if (a >= 0) {
		return a;
	} else {
		return -a;
	}
}

int Pow(int p, int q) {
	return (int) pow((double) p, (double) q);
}

int Min(int nums[], int n) {
	if (n == 0) {
		return 0;
	}
	int res = nums[0];
	for (int i = 0; i < n; i++) {
		res = (int) fmin((double) res, (double) nums[i]);
	}
	return res;
}

int Max(int nums[], int n) {
	if (n == 0) {
		return 0;
	}
	int res = nums[0];
	for (int i = 0; i < n; i++) {
		res = (int) fmax((double) res, (double) nums[i]);
	}
	return res;
}

int SortAsc(int a[], int n) {
	qsort(a, n, sizeof(int), (int (*)(const void *, const void *)) &__compare_asc);
	return 0;
}

int SortDesc(int a[], int n) {
	qsort(a, n, sizeof(int), (int (*)(const void *, const void *)) &__compare_desc);
	return 0;
}

int GCD(int a, int b) {
	if (b == 0) {
		return a;
	}
	return GCD(b, a % b);
}

int LCM(int a, int b) {
	if (a == 0 && b == 0) {
		return 0;
	}
	return a * b / GCD(a, b);
}

int CumSum(int nums[], int n) {
	int sums[n+1];
	sums[0] = 0;
	for (int i = 0; i < n; i++) {
		sums[i+1] = sums[i] + nums[i];
	}
	return 0;
}

int BisectLeft(int nums[], int left, int right, int target) {
	if (left == right) {
		if (nums[left] == target) {
			return left;
		} else if (nums[left] < target) {
			return left + 1;
		} else {
			return left;
		}
	}

	int mid = (left + right) / 2;
	if (nums[mid] == target) {
		return mid;
	}

	if (nums[mid] > target) {
		return BisectLeft(nums, left, mid, target);
	} else if (nums[mid] < target) {
		return BisectLeft(nums, mid+1, right, target);
	}
	return 0;
}

int Permutations(int nums[], int n) {
	int ans[n];
	for (int i = 0; i < n; i++) {
		ans[i] = nums[i];
	}
	return 0;
}

int PowerSet(int nums[], int n) {
	int size = Pow(2, n);
	int result[size][n];

	int idx = 0;
	result[idx] = [];
	idx++;

	for (int i = 0; i < n; i++) {
		int max = idx;
		for (int j = 0; j < max; j++) {
			result[idx] = copyAndAppend(result[j], nums[i]);
			idx++;
		}
	}

	return 0;
}

int Combination(int nums[], int n, int k) {
	int size = n;
	int result[CombinationCount(n, k, 10e10)][k];
	int bi = (1 << uint(k)) - 1;
	int max = 1 << uint(size);
	int idx = 0;

	for (bi < max) {
		int flags = bi;
		int s[k];
		for (int i = 0; i < n; i++) {
			if (flags % 2!= 0) {
				s[i] = nums[i];
			}
			flags /= 2;
		}
		result[idx] = s;
		idx++;
		bi = Combination2NextIndex(bi);
	}
	return 0;
}

int CombinationCount(int n, int m, int maxInput) {
	int64_t memo[maxInput*maxInput];
	for (int i = 0; i < maxInput*maxInput; i++) {
		memo[i] = map[int64_t]int64_t();
	}
	return combinationCount(n, m, memo);
}

int combinationCount(int n, int m, int64_t memo[]) {
	if (n == m || m == 0) {
		return 1;
	}

	int64_t left, lOK;
	left, lOK = memo[n-1][m-1];
	int64_t right, rOK;
	right, rOK = memo[n-1][m];

	if (lOK && rOK) {
		return left + right;
	}

	if (lOK) {
		right = combinationCount(n-1, m, memo);
		memo[n-1][m] = right;
		return left + right;
	}

	if (rOK) {
		left = combinationCount(n-1, m-1, memo);
		memo[n-1][m-1] = left;
		return left + right;
	}

	left = combinationCount(n-1, m-1, memo);
	right = combinationCount(n-1, m, memo);
	memo[n-1][m-1] = left;
	memo[n-1][m] = right;
	return left + right;
}

int Fact(int n) {
	if (n == 0) {
		return 1;
	} else {
		return n * Fact(n-1);
	}
}

int Divisors(int n) {
	int divisors[n];
	for (int i = 1; i < (int) sqrt((double) n) + 1; i++) {
		if (n % i == 0) {
			divisors[i] = true;
			if (i!= n) {
				divisors[n/i] = true;
			}
		}
	}
	return 0;
}

int main() {
	// Initialize input/output handling
	Io io = NewIo();
	defer io.Flush();

	// Read the number of elements
	int n = io.Int();

	// Create a slice to hold the input integers
	int aa[n];

	// Read each integer and store it in the slice
	for (int i = 0; i < n; i++) {
		aa[i] = io.Int();
	}

	// Compute the cumulative sum of the input integers
	CumSum(aa, n);

	// Initialize the answer with a large value
	int ans = 2020202020;

	// Iterate through the cumulative sums to find the minimum difference
	for (int i = 1; i < n-1; i++) {
		ans = Min(ans, Abs(aa[n-1] - aa[i] - (aa[i] - aa[0])));
	}

	// Output the final answer
	io.PrintLn(ans);
	return 0;
}

// Io struct for handling input and output
typedef struct {
	FILE *reader;
	FILE *writer;
	char *tokens[1000000];
	int nextToken;
} Io;

// NewIo initializes a new Io instance
Io NewIo() {
	Io io;
	io.reader = fopen("input.txt", "r");
	io.writer = fopen("output.txt", "w");
	io.nextToken = 0;
	return io;
}

// Flush writes any buffered data to the output
void Flush(Io io) {
	fflush(io.writer);
}

// NextLine reads a full line from input
char *NextLine(Io io) {
	char *buffer = malloc(1000000);
	int bufferLen = 0;
	int bufferPos = 0;
	while (1) {
		char c = fgetc(io.reader);
		if (c == '\n' || c == EOF) {
			buffer[bufferPos] = '\0';
			break;
		}
		buffer[bufferPos] = c;
		bufferPos++;
		if (bufferPos >= bufferLen) {
			bufferLen += 1000000;
			buffer = realloc(buffer, bufferLen);
		}
	}
	return buffer;
}

// Next retrieves the next token from the input
char *Next(Io io) {
	while (io.nextToken >= sizeof(io.tokens) / sizeof(io.tokens[0])) {
		char *line = NextLine(io);
		int tokenCount = 0;
		char *token = strtok(line, " ");
		while (token!= NULL) {
			io.tokens[tokenCount] = token;
			tokenCount++;
			token = strtok(NULL, " ");
		}
		io.nextToken = 0;
	}
	char *r = io.tokens[io.nextToken];
	io.nextToken++;
	return r;
}

// Int converts the next token to an integer
int Int(Io io) {
	int i = atoi(Next(io));
	return i;
}

// Float converts the next token to a float64
float Float(Io io) {
	float i = atof(Next(io));
	return i;
}

// PrintLn prints a line to the output
void PrintLn(Io io,...) {
	va_list args;
	va_start(args, io);
	vfprintf(io.writer, args);
	va_end(args);
	fprintf(io.writer, "\n");
}

// Printf formats and prints to the output
void Printf(Io io, char *format,...) {
	va_list args;
	va_start(args, format);
	vfprintf(io.writer, format, args);
	va_end(args);
}

// PrintIntLn prints a slice of integers to the output
void PrintIntLn(Io io, int a[], int n) {
	for (int i = 0; i < n; i++) {
		PrintLn(io, a[i]);
	}
}

// PrintStringLn prints a slice of strings to the output
void PrintStringLn(Io io, char *a[], int n) {
	for (int i = 0; i < n; i++) {
		PrintLn(io, a[i]);
	}
}

// Log prints a variable to stderr for debugging
void Log(char *name, int value) {
	fprintf(stderr, "%s=%d\n", name, value);
}

// Abs returns the absolute value of an integer
int Abs(int a) {
	if (a >= 0) {
		return a;
	} else {
		return -a;
	}
}

// Pow calculates p raised to the power of q
int Pow(int p, int q) {
	return (int) pow((double) p, (double) q);
}

// Min returns the minimum value from a list of integers
int Min(int nums[], int n) {
	if (n == 0) {
		return 0;
	}
	int res = nums[0];
	for (int i = 0; i < n; i++) {
		res = (int) fmin((double) res, (double) nums[i]);
	}
	return res;
}

// Max returns the maximum value from a list of integers
int Max(int nums[], int n) {
	if (n == 0) {
		return 0;
	}
	int res = nums[0];
	for (int i = 0; i < n; i++) {
		res = (int) fmax((double) res, (double) nums[i]);
	}
	return res;
}

// SortAsc sorts a slice of integers in ascending order
int SortAsc(int a[], int n) {
	qsort(a, n, sizeof(int), (int (*)(const void *, const void *)) &__compare_asc);
	return 0;
}

// SortDesc sorts a slice of integers in descending order
int SortDesc(int a[], int n) {
	qsort(a, n, sizeof(int), (int (*)(const void *, const void *)) &__compare_desc);
	return 0;
}

// GCD computes the greatest common divisor of two integers
int GCD(int a, int b) {
	if (b == 0) {
		return a;
	}
	return GCD(b, a % b);
}

// LCM computes the least common multiple of two integers
int LCM(int a, int b) {
	if (a == 0 && b == 0) {
		return 0;
	}
	return a * b / GCD(a, b);
}

// CumSum computes the cumulative sum of a slice of integers
int CumSum(int nums[], int n) {
	int sums[n+1];
	sums[0] = 0;
	for (int i = 0; i < n; i++) {
		sums[i+1] = sums[i] + nums[i];
	}
	return 0;
}

// BisectLeft performs a binary search to find the leftmost index of a target in a sorted slice
int BisectLeft(int nums[], int left, int right, int target) {
	if (left == right) {
		if (nums[left] == target) {
			return left;
		} else if (nums[left] < target) {
			return left + 1;
		} else {
			return left;
		}
	}

	int mid = (left + right) / 2;
	if (nums[mid] == target) {
		return mid;
	}

	if (nums[mid] > target) {
		return BisectLeft(nums, left, mid, target);
	} else if (nums[mid] < target) {
		return BisectLeft(nums, mid+1, right, target);
	}
	return 0;
}

// Permutations generates all permutations of a slice of integers
int Permutations(int nums[], int n) {
	int ans[n];
	for (int i = 0; i < n; i++) {
		ans[i] = nums[i];
	}
	return 0;
}

// PowerSet generates the power set of a slice of integers
int PowerSet(int nums[], int n) {
	int size = Pow(2, n);
	int result[size][n];

	int idx = 0;
	result[idx] = [];
	idx++;

	for (int i = 0; i < n; i++) {
		int max = idx;
		for (int j = 0; j < max; j++) {
			result[idx] = copyAndAppend(result[j], nums[i]);
			idx++;
		}
	}

	return 0;
}

// Combination generates all combinations of k elements from a slice of integers
int Combination(int nums[], int n, int k) {
	int size = n;
	int result[CombinationCount(n, k, 10e10)][k];
	int bi = (1 << uint(k)) - 1;
	int ma