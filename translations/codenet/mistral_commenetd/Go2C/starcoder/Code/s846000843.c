#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// The main function is the entry point of the program.
int main(int argc, char* argv[]) {
	// Read the number n from the standard input.
	int n = atoi(fgets(NULL, 0, stdin));

	// Initialize an array aa of length n to store the input integers.
	int* aa = malloc(sizeof(int) * n);

	// Read n integers from the standard input and store them in the aa array using a for loop.
	for (int i = 0; i < n; i++) {
		aa[i] = atoi(fgets(NULL, 0, stdin));
	}

	// Compute the cumulative sum of the aa array using the CumSum function.
	int* cumsum = CumSum(aa, n);

	// Initialize a variable ans to store the answer.
	int ans = 2020202020;

	// Use a for loop to iterate through the cumulative sum array, excluding the first and last elements, and compute the absolute difference between the last cumulative sum and the current cumulative sum, and the difference between the current cumulative sum and the first cumulative sum. Keep the minimum of these two differences as the answer.
	for (int i = 1; i < n-1; i++) {
		// Compute the absolute difference between the last cumulative sum and the current cumulative sum.
		int diff1 = abs(cumsum[n-1] - cumsum[i]);

		// Compute the difference between the current cumulative sum and the first cumulative sum.
		int diff2 = cumsum[i] - cumsum[0];

		// Keep the minimum of these two differences as the answer.
		ans = min(ans, diff1, diff2);
	}

	// Print the answer using the PrintLn function.
	PrintLn(ans);
}

// NewIo initializes an Io struct.
struct Io {
	FILE* reader;
	FILE* writer;
	char* buffer;
	int bufferLen;
	int bufferCap;
};

struct Io* NewIo() {
	struct Io* io = malloc(sizeof(struct Io));
	io->reader = stdin;
	io->writer = stdout;
	io->buffer = NULL;
	io->bufferLen = 0;
	io->bufferCap = 0;
	return io;
}

// The Flush method of the Io struct ensures that all output is written before the program exits.
void Flush(struct Io* io) {
	fflush(io->writer);
}

// The NextLine method of the Io struct reads a line from the standard input and returns it as a string.
char* NextLine(struct Io* io) {
	if (io->buffer == NULL) {
		io->buffer = malloc(1024);
		io->bufferCap = 1024;
	}
	char* buffer = io->buffer;
	int bufferLen = io->bufferLen;
	int bufferCap = io->bufferCap;
	int bufferPos = 0;
	while (1) {
		int c = fgetc(io->reader);
		if (c == EOF) {
			break;
		}
		if (bufferPos == bufferLen) {
			bufferLen = bufferLen * 2;
			buffer = realloc(buffer, bufferLen);
			bufferCap = bufferLen;
		}
		buffer[bufferPos] = c;
		bufferPos++;
		if (c == '\n') {
			break;
		}
	}
	buffer[bufferPos] = '\0';
	io->buffer = buffer;
	io->bufferLen = bufferPos;
	io->bufferCap = bufferCap;
	return buffer;
}

// The Next method of the Io struct reads a token from the standard input and returns it as a string.
char* Next(struct Io* io) {
	char* line = NextLine(io);
	char* token = strtok(line, " ");
	return token;
}

// The Int method of the Io struct reads an integer from the standard input and returns it.
int Int(struct Io* io) {
	char* token = Next(io);
	return atoi(token);
}

// The PrintLn method of the Io struct prints a line to the standard output.
void PrintLn(struct Io* io,...) {
	va_list args;
	va_start(args, io);
	vfprintf(io->writer, args);
	va_end(args);
	fprintf(io->writer, "\n");
}

// The Printf method of the Io struct prints a formatted line to the standard output.
void Printf(struct Io* io, char* format,...) {
	va_list args;
	va_start(args, format);
	vfprintf(io->writer, format, args);
	va_end(args);
}

// The PrintIntLn method of the Io struct prints an integer array to the standard output.
void PrintIntLn(struct Io* io, int* a, int n) {
	for (int i = 0; i < n; i++) {
		PrintInt(io, a[i]);
		if (i < n-1) {
			Print(io, " ");
		}
	}
	PrintLn(io);
}

// The PrintStringLn method of the Io struct prints a string array to the standard output.
void PrintStringLn(struct Io* io, char** a, int n) {
	for (int i = 0; i < n; i++) {
		PrintString(io, a[i]);
		if (i < n-1) {
			Print(io, " ");
		}
	}
	PrintLn(io);
}

// The Log method logs a message to the standard error stream.
void Log(char* name, void* value) {
	fprintf(stderr, "%s=%+v\n", name, value);
}

// The Abs function returns the absolute value of an integer.
int Abs(int a) {
	if (a >= 0) {
		return a;
	} else {
		return -a;
	}
}

// The Pow function returns the result of raising a to the power of b.
int Pow(int p, int q) {
	return pow(p, q);
}

// The Min function returns the minimum of a list of integers.
int Min(int n,...) {
	va_list args;
	va_start(args, n);
	int res = n;
	for (int i = 0; i < n; i++) {
		int num = va_arg(args, int);
		res = num < res? num : res;
	}
	va_end(args);
	return res;
}

// The Max function returns the maximum of a list of integers.
int Max(int n,...) {
	va_list args;
	va_start(args, n);
	int res = n;
	for (int i = 0; i < n; i++) {
		int num = va_arg(args, int);
		res = num > res? num : res;
	}
	va_end(args);
	return res;
}

// The SortAsc function sorts an integer slice in ascending order.
void SortAsc(int* a, int n) {
	qsort(a, n, sizeof(int), compareAsc);
}

// The SortDesc function sorts an integer slice in descending order.
void SortDesc(int* a, int n) {
	qsort(a, n, sizeof(int), compareDesc);
}

// The GCD function returns the greatest common divisor of a and b.
int GCD(int a, int b) {
	if (b == 0) {
		return a;
	}
	return GCD(b, a%b);
}

// The LCM function returns the least common multiple of a and b.
int LCM(int a, int b) {
	if (a == 0 && b == 0) {
		return 0;
	}
	return a * b / GCD(a, b);
}

// The CumSum function computes the cumulative sum of an integer slice.
int* CumSum(int* nums, int n) {
	int* sums = malloc(sizeof(int) * (n+1));
	sums[0] = 0;
	for (int i = 0; i < n; i++) {
		sums[i+1] = sums[i] + nums[i];
	}
	return sums;
}

// The BisectLeft function returns the index where x should be inserted into a sorted slice to maintain the sort order.
int BisectLeft(int* nums, int left, int right, int target) {
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

// The Permutations function returns all permutations of a slice.
int** Permutations(int* nums, int n) {
	int size = n;
	int** result = malloc(sizeof(int*) * Fact(size));
	int idx = 0;
	result[idx] = malloc(sizeof(int) * size);
	idx++;

	for (int i = 0; i < size; i++) {
		int max = idx;
		for (int j = 0; j < max; j++) {
			int* list = result[j];
			int* newList = malloc(sizeof(int) * (size+1));
			for (int k = 0; k < size; k++) {
				newList[k] = list[k];
			}
			newList[size] = nums[i];
			result = realloc(result, sizeof(int*) * (idx+1));
			result[idx] = newList;
			idx++;
		}
	}

	return result;
}

// The remove function removes the first occurrence of x from a slice.
int* remove(int* nums, int x, int n) {
	int* result = malloc(sizeof(int) * (n-1));
	int idx = 0;
	for (int i = 0; i < n; i++) {
		if (nums[i]!= x) {
			result[idx] = nums[i];
			idx++;
		}
	}
	return result;
}

// The PowerSet function returns all subsets of a slice.
int** PowerSet(int* nums, int n) {
	int size = n;
	int** result = malloc(sizeof(int*) * Pow(2, size));
	int idx = 0;
	result[idx] = malloc(sizeof(int) * size);
	idx++;

	for (int i = 0; i < size; i++) {
		int max = idx;
		for (int j = 0; j < max; j++) {
			int* list = result[j];
			int* newList = malloc(sizeof(int) * (size+1));
			for (int k = 0; k < size; k++) {
				newList[k] = list[k];
			}
			newList[size] = nums[i];
			result = realloc(result, sizeof(int*) * (idx+1));
			result[idx] = newList;
			idx++;
		}
	}

	return result;
}

// The copyAndAppend function returns a copy of x with y appended to it.
int* copyAndAppend(int* x, int y, int n) {
	int* dst = malloc(sizeof(int) * (n+1));
	for (int i = 0; i < n; i++) {
		dst[i] = x[i];
	}
	dst[n] = y;
	return dst;
}

// The Combination function returns all combinations of size r from a slice.
int** Combination(int* nums, int n, int r) {
	int size = n;
	int** result = malloc(sizeof(int*) * CombinationCount(size, r));
	int bi = (1 << uint(r)) - 1;
	int max = 1 << uint(size);
	int idx = 0;

	for (bi < max) {
		int flags = bi;
		int* s = malloc(sizeof(int) * size);
		int i = 0;
		for (i = 0; i < size; i++) {
			if (flags%2!= 0) {
				s[i] = nums[i];
			}
			flags /= 2;
		}
		result = realloc(result, sizeof(int*) * (idx+1));
		result[idx] = s;
		idx++;
		bi = Combination2NextIndex(bi);
	}
	return result;
}

// The CombinationCount function returns the number of combinations of size r from a slice.
int CombinationCount(int n, int m) {
	int memo[n+1][m+1];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (i == j || j == 0) {
				memo[i][j] = 1;
			} else {
				memo[i][j] = memo[i-1][j] + memo[i-1][j-1];
			}
		}
	}
	return memo[n][m];
}

// The Fact function returns the factorial of n.
int Fact(int n) {
	if (n == 0) {
		return 1;
	} else {
		return n * Fact(n-1);
	}
}

// The Divisors function returns all divisors of n.
int* Divisors(int n) {
	int* divisors = malloc(sizeof(int) * (n+1));
	int idx = 0;
	for (int i = 1; i <= n; i++) {
		if (n%i == 0) {
			divisors[idx] = i;
			idx++;
		}
	}
	return divisors;
}

// The compareAsc function compares two integers in ascending order.
int compareAsc(const void* a, const void* b) {
	int x = *(int*)a;
	int y = *(int*)b;
	if (x < y) {
		return -1;
	} else if (x > y) {
		return 1;
	} else {
		return 0;
	}
}

// The compareDesc function compares two integers in descending order.
int compareDesc(const void* a, const void* b) {
	int x = *(int*)a;
	int y = *(int*)b;
	if (x < y) {
		return 1;
	} else if (x > y) {
		return -1;
	} else {
		return 0;
	}
}

// The Combination2NextIndex function returns the next 