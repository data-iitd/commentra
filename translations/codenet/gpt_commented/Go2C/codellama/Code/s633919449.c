
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Constants for buffer sizes and modulo value
const int initialBufSize = 10000;
const int maxBufSize = 1000000;
const int mod = 1e9 + 7;

// Scanner for reading input
char *scanner(char *str) {
	char *buf = (char *)malloc(initialBufSize * sizeof(char));
	int bufSize = initialBufSize;
	int len = 0;
	int c;

	while (1) {
		c = getchar();
		if (c == EOF) {
			return NULL;
		}
		buf[len++] = c;
		if (c == '\n') {
			break;
		}
		if (len == bufSize) {
			bufSize *= 2;
			buf = (char *)realloc(buf, bufSize * sizeof(char));
		}
	}
	buf[len] = '\0';
	strcpy(str, buf);
	free(buf);
	return str;
}

// Function to read an integer from input
int getInt() {
	char str[initialBufSize];
	scanner(str);
	return atoi(str);
}

// Function to read an array of integers from input
int *getIntArray(int n) {
	int *array = (int *)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++) {
		array[i] = getInt();
	}
	return array;
}

// Function to read a string from input
char *getString() {
	char str[initialBufSize];
	scanner(str);
	return str;
}

// Function to read an array of strings from input
char **getStringArray(int n) {
	char **array = (char **)malloc(n * sizeof(char *));
	for (int i = 0; i < n; i++) {
		array[i] = getString();
	}
	return array;
}

// Function to calculate the absolute value of an integer
int abs(int a) {
	return (a < 0) ? -a : a;
}

// Function to calculate p raised to the power of q
int pow(int p, int q) {
	if (q == 0) {
		return 1;
	} else if (q % 2 == 0) {
		return pow(p, q / 2) * pow(p, q / 2);
	} else {
		return p * pow(p, q - 1);
	}
}

// Function to calculate n raised to the power of p modulo mod
int powMod(int n, int p) {
	if (p == 0) {
		return 1;
	} else if (p % 2 == 0) {
		int t = powMod(n, p / 2);
		return (t * t) % mod;
	} else {
		return (n * powMod(n, p - 1)) % mod;
	}
}

// Function to find the minimum value among a list of integers
int min(int nums[], int n) {
	int res = nums[0];
	for (int i = 1; i < n; i++) {
		res = (res < nums[i]) ? res : nums[i];
	}
	return res;
}

// Function to find the maximum value among a list of integers
int max(int nums[], int n) {
	int res = nums[0];
	for (int i = 1; i < n; i++) {
		res = (res > nums[i]) ? res : nums[i];
	}
	return res;
}

// Function to check if a string exists in an array of strings
int strSearch(char **a, char *b) {
	for (int i = 0; i < n; i++) {
		if (strcmp(a[i], b) == 0) {
			return 1;
		}
	}
	return 0;
}

// Function to print an array of integers
void printIntArray(int *array, int n) {
	printf("%d", array[0]);
	for (int i = 1; i < n; i++) {
		printf(" %d", array[i]);
	}
	printf("\n");
}

// Function to calculate x modulo mod
int calcMod(int x) {
	return x % mod;
}

// Function to reverse a string
char *reverse(char *s) {
	int len = strlen(s);
	char *t = (char *)malloc((len + 1) * sizeof(char));
	for (int i = 0, j = len - 1; i < len; i++, j--) {
		t[i] = s[j];
	}
	t[len] = '\0';
	return t;
}

// Function to check if a number is prime
int isPrime(int n) {
	if (n < 2) {
		return 0;
	} else if (n == 2) {
		return 1;
	} else if (n % 2 == 0) {
		return 0;
	}

	int sqrtN = (int)sqrt(n);
	for (int i = 3; i <= sqrtN; i += 2) {
		if (n % i == 0) {
			return 0;
		}
	}

	return 1;
}

// Function to check if an integer exists in a slice
int contains(int *s, int n, int e) {
	for (int i = 0; i < n; i++) {
		if (s[i] == e) {
			return 1;
		}
	}
	return 0;
}

// Function to create a range of integers from min to max
int *makeRange(int min, int max) {
	int *a = (int *)malloc((max - min + 1) * sizeof(int));
	for (int i = 0; i < max - min + 1; i++) {
		a[i] = min + i;
	}
	return a;
}

// Function to generate the powerset of a given slice of integers
int **powerset2(int *nums, int n) {
	int length = (int)pow(2, n);
	int **result = (int **)malloc(length * sizeof(int *));

	int index = 0;
	result[index] = (int *)malloc(0 * sizeof(int));
	index++;

	// Generate all subsets
	for (int i = 0; i < n; i++) {
		int max = index;
		for (int j = 0; j < max; j++) {
			result[index] = (int *)malloc((i + 1) * sizeof(int));
			for (int k = 0; k < i; k++) {
				result[index][k] = result[j][k];
			}
			result[index][i] = nums[i];
			index++;
		}
	}

	return result;
}

// Function to calculate the greatest common divisor (GCD) of two integers
int calcGcd(int x, int y) {
	if (y == 0) {
		return x;
	} else if (x >= y) {
		return calcGcd(y, x % y);
	} else {
		return calcGcd(x, y % x);
	}
}

// Function to get all divisors of a number
int *getDivisor(int n) {
	int *divisor = (int *)malloc(0 * sizeof(int));
	divisor[0] = 1;
	if (n != 1) {
		divisor[1] = n;
	}

	int sqrtN = (int)sqrt(n);
	for (int i = 2; i <= sqrtN; i += 2) {
		if (n % i == 0) {
			divisor[2] = i;
			divisor[3] = n / i;
		}
	}

	return divisor;
}

// Custom heap type for integers
typedef struct {
	int *array;
	int size;
	int capacity;
} intHeap;

// Implementing heap.Interface for intHeap
int intHeap_Len(intHeap *h) {
	return h->size;
}

int intHeap_Less(intHeap *h, int i, int j) {
	return h->array[i] > h->array[j];
}

void intHeap_Swap(intHeap *h, int i, int j) {
	int tmp = h->array[i];
	h->array[i] = h->array[j];
	h->array[j] = tmp;
}

// Push an element onto the heap
void intHeap_Push(intHeap *h, int x) {
	if (h->size == h->capacity) {
		h->capacity *= 2;
		h->array = (int *)realloc(h->array, h->capacity * sizeof(int));
	}
	h->array[h->size++] = x;
}

// Pop an element from the heap
int intHeap_Pop(intHeap *h) {
	int x = h->array[--h->size];
	return x;
}

// Initialize a new integer heap
intHeap *initHeap() {
	intHeap *ih = (intHeap *)malloc(sizeof(intHeap));
	ih->array = (int *)malloc(initialBufSize * sizeof(int));
	ih->size = 0;
	ih->capacity = initialBufSize;
	return ih;
}

// Push an integer onto the heap
void intHeap_pushHeap(intHeap *h, int n) {
	intHeap_Push(h, n);
}

// Pop an integer from the heap
int intHeap_popHeap(intHeap *h) {
	return intHeap_Pop(h);
}

// Function to calculate factorial modulo mod
int factMod(int n) {
	int value = 1;
	for (; n > 1; n--) {
		value = (value * n) % mod;
	}
	return value;
}

// Function to calculate combinations modulo mod
int combinationMod(int n, int k) {
	int factN = factMod(n);
	int factK = factMod(k);
	int factNK = factMod(n - k);
	int factKR = powMod(factK, mod - 2);
	int factNKR = powMod(factNK, mod - 2);
	return (factN * (factKR * factNKR)) % mod;
}

// Function to find prime factors of a number
int *primeFactors(int n) {
	int *factors = (int *)malloc(0 * sizeof(int));
	int i = 2;
	for (; i * i <= n; i++) {
		int r = n % i;
		if (r != 0) {
			i += 1;
		} else if (r == 0) {
			n /= i;
			factors = (int *)realloc(factors, (i + 1) * sizeof(int));
			factors[i] = i;
		}
	}
	if (n > 1) {
		factors = (int *)realloc(factors, (i + 1) * sizeof(int));
		factors[i] = n;
	}
	return factors;
}

// Main function
int main() {
	// Read an integer input
	int N = getInt();

	// Determine the output based on the last digit of N
	switch (N % 10) {
	case 2:
	case 4:
	case 5:
	case 7:
	case 9:
		printf("hon\n");
		break;
	case 0:
	case 1:
	case 6:
	case 8:
		printf("pon\n");
		break;
	case 3:
		printf("bon\n");
		break;
	}

	return 0;
}

