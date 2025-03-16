
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))
#define max(a, b) (((a) > (b)) ? (a) : (b))
#define abs(a) (((a) < 0) ? -(a) : (a))

int main() {
	// Initialize an Io struct and call its Flush method to ensure that all output is written before the program exits.
	Io io = {
		.reader = stdin,
		.writer = stdout,
		.tokens = NULL,
		.nextToken = 0
	};
	defer(io.Flush());

	// Read the number n from the standard input.
	int n = io.Int();

	// Initialize an array aa of length n to store the input integers.
	int *aa = malloc(n * sizeof(int));

	// Read n integers from the standard input and store them in the aa array using a for loop.
	for (int i = 0; i < n; i++) {
		aa[i] = io.Int();
	}

	// Compute the cumulative sum of the aa array using the CumSum function.
	int *cumsum = CumSum(aa, n);

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

	// Print the answer using the PrintLn method of the Io struct.
	printf("%d\n", ans);

	// Free the memory allocated for the aa and cumsum arrays.
	free(aa);
	free(cumsum);

	return 0;
}

// The Io struct represents the standard input and output streams.
typedef struct {
	FILE *reader;
	FILE *writer;
	char **tokens;
	int nextToken;
} Io;

// The Flush method of the Io struct ensures that all output is written before the program exits.
void Io_Flush(Io *io) {
	fflush(io->writer);
}

// The NextLine method of the Io struct reads a line from the standard input and returns it as a string.
char *Io_NextLine(Io *io) {
	char *buffer = NULL;
	size_t bufferSize = 0;
	getline(&buffer, &bufferSize, io->reader);
	return buffer;
}

// The Next method of the Io struct reads a token from the standard input and returns it as a string.
char *Io_Next(Io *io) {
	if (io->nextToken >= io->tokens) {
		char *line = Io_NextLine(io);
		io->tokens = strtok(line, " ");
		io->nextToken = 0;
	}
	char *r = io->tokens[io->nextToken];
	io->nextToken++;
	return r;
}

// The Int method of the Io struct reads an integer from the standard input and returns it.
int Io_Int(Io *io) {
	char *token = Io_Next(io);
	int i = atoi(token);
	return i;
}

// The PrintLn method of the Io struct prints a line to the standard output.
void Io_PrintLn(Io *io, char *a) {
	printf("%s\n", a);
}

// The Printf method of the Io struct prints a formatted line to the standard output.
void Io_Printf(Io *io, char *format, ...) {
	va_list args;
	va_start(args, format);
	vprintf(format, args);
	va_end(args);
}

// The PrintIntLn method of the Io struct prints an integer array to the standard output.
void Io_PrintIntLn(Io *io, int *a) {
	Io_PrintLn(io, a);
}

// The PrintStringLn method of the Io struct prints a string array to the standard output.
void Io_PrintStringLn(Io *io, char **a) {
	Io_PrintLn(io, a);
}

// The Log method logs a message to the standard error stream.
void Log(char *name, int value) {
	fprintf(stderr, "%s=%d\n", name, value);
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
	return (int)pow(p, q);
}

// The Min function returns the minimum of a list of integers.
int Min(int nums, ...) {
	int res = nums;
	va_list args;
	va_start(args, nums);
	for (int i = 0; i < nums; i++) {
		res = min(res, va_arg(args, int));
	}
	va_end(args);
	return res;
}

// The Max function returns the maximum of a list of integers.
int Max(int nums, ...) {
	int res = nums;
	va_list args;
	va_start(args, nums);
	for (int i = 0; i < nums; i++) {
		res = max(res, va_arg(args, int));
	}
	va_end(args);
	return res;
}

// The SortAsc function sorts an integer slice in ascending order.
int *SortAsc(int *nums, int size) {
	qsort(nums, size, sizeof(int), cmp);
	return nums;
}

// The SortDesc function sorts an integer slice in descending order.
int *SortDesc(int *nums, int size) {
	qsort(nums, size, sizeof(int), cmp);
	return nums;
}

// The Cmp function compares two integers.
int cmp(const void *a, const void *b) {
	return *(int *)a - *(int *)b;
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
int *CumSum(int *nums, int size) {
	int *sums = malloc(sizeof(int) * (size + 1));
	sums[0] = 0;
	for (int i = 0; i < size; i++) {
		sums[i+1] = sums[i] + nums[i];
	}
	return sums;
}

// The BisectLeft function returns the index where x should be inserted into a sorted slice to maintain the sort order.
int BisectLeft(int *nums, int left, int right, int target) {
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
int **Permutations(int *nums, int size) {
	int **result = malloc(sizeof(int *) * Fact(size));
	int idx = 0;

	for (int i = 0; i < size; i++) {
		int *rest = remove(nums, size, nums[i]);
		int **lists = Permutations(rest, size-1);
		for (int j = 0; j < size-1; j++) {
			int *list = lists[j];
			list = append(list, size-1, nums[i]);
			result[idx] = list;
			idx++;
			result[idx] = lists[j+1];
			idx++;
		}
	}
	return result;
}

// The remove function removes the first occurrence of x from a slice.
int *remove(int *nums, int size, int x) {
	int *result = malloc(sizeof(int) * (size - 1));
	int idx = 0;
	for (int i = 0; i < size; i++) {
		if (nums[i] != x) {
			result[idx] = nums[i];
			idx++;
		}
	}
	return result;
}

// The append function returns a copy of x with y appended to it.
int *append(int *x, int size, int y) {
	int *result = malloc(sizeof(int) * (size + 1));
	for (int i = 0; i < size; i++) {
		result[i] = x[i];
	}
	result[size] = y;
	return result;
}

// The PowerSet function returns all subsets of a slice.
int **PowerSet(int *nums, int size) {
	int **result = malloc(sizeof(int *) * Pow(2, size));
	int idx = 0;

	int bi = (1 << size) - 1;
	int max = 1 << size;
	while (bi < max) {
		int flags = bi;
		int *s = malloc(sizeof(int) * size);
		int j = 0;
		for (int i = 0; i < size; i++) {
			if (flags % 2 != 0) {
				s[j] = nums[i];
				j++;
			}
			flags /= 2;
		}
		result[idx] = s;
		idx++;
		bi = Combination2NextIndex(bi);
	}
	return result;
}

// The Combination function returns all combinations of size r from a slice.
int **Combination(int *nums, int size, int r) {
	int **result = malloc(sizeof(int *) * CombinationCount(size, r, 10e10));
	int idx = 0;

	int bi = (1 << r) - 1;
	int max = 1 << size;
	while (bi < max) {
		int flags = bi;
		int *s = malloc(sizeof(int) * r);
		int j = 0;
		for (int i = 0; i < size; i++) {
			if (flags % 2 != 0) {
				s[j] = nums[i];
				j++;
			}
			flags /= 2;
		}
		result[idx] = s;
		idx++;
		bi = Combination2NextIndex(bi);
	}
	return result;
}

// The CombinationCount function returns the number of combinations of size r from a slice.
int CombinationCount(int n, int m, int maxInput) {
	int **memo = malloc(sizeof(int *) * (maxInput * maxInput));
	for (int i = 0; i < maxInput * maxInput; i++) {
		memo[i] = malloc(sizeof(int) * maxInput);
	}
	return combinationCount(n, m, memo);
}
int combinationCount(int n, int m, int **memo) {
	if (n == m || m == 0) {
		return 1;
	}

	int left = memo[n-1][m-1];
	int right = memo[n-1][m];

	if (left != 0 && right != 0) {
		return left + right;
	}

	if (left != 0) {
		right = combinationCount(n-1, m, memo);
		memo[n-1][m] = right;
		return left + right;
	}

	if (right != 0) {
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

// The Fact function returns the factorial of n.
int Fact(int n) {
	if (n == 0) {
		return 1;
	} else {
		return n * Fact(n-1);
	}
}

// The Divisors function returns all divisors of n.
int *Divisors(int n) {
	int *divisors = malloc(sizeof(int) * n);
	for (int i = 1; i < int(sqrt(n))+1; i++) {
		if (n % i == 0) {
			divisors[i] = i;
			divisors[n-i] = n-i;
		}
	}
	return divisors;
}

// The Combination2NextIndex function returns the next index in the combination sequence.
int Combination2NextIndex(int bi) {
	int i = 0;
	while (bi % 2 == 0) {
		bi /= 2;
		i++;
	}
	return bi + (1 << i);
}

// The Combination2NextIndex function returns the next index in the combination sequence.
int Combination2NextIndex(int bi) {
	int i = 0;
	while (bi % 2 == 0) {
		bi /= 2;
		i++;
	}
	return bi + (1 << i);
}

// The Combination2NextIndex function returns the next index in the combination sequence.
int Combination2NextIndex(int bi) {