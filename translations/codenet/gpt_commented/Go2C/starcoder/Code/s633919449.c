

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constants for buffer sizes and modulo value
#define INITIAL_BUF_SIZE 10000
#define MAX_BUF_SIZE 1000000
#define MOD 1e9 + 7

// Scanner for reading input
typedef struct {
	char *buffer;
	int position;
	int length;
} Scanner;

// Function to read an integer from input
int getInt(Scanner *scanner) {
	int result = 0;
	int sign = 1;
	int c;
	while ((c = getchar())!= EOF && c <= 32) {
	}
	if (c == EOF) {
		return 0;
	} else if (c == '-') {
		sign = -1;
	} else {
		ungetc(c, stdin);
	}
	while ((c = getchar())!= EOF && c > 32) {
		result = result * 10 + c - '0';
	}
	return sign * result;
}

// Function to read a string from input
char *getString(Scanner *scanner) {
	int position = scanner->position;
	while (scanner->buffer[position]!= EOF && scanner->buffer[position] <= 32) {
		position++;
	}
	if (scanner->buffer[position] == EOF) {
		return NULL;
	} else {
		scanner->position = position;
		int length = 0;
		while (scanner->buffer[position]!= EOF && scanner->buffer[position] > 32) {
			position++;
			length++;
		}
		scanner->position = position;
		char *result = malloc(length + 1);
		memcpy(result, scanner->buffer + scanner->position - length, length);
		result[length] = '\0';
		return result;
	}
}

// Function to calculate the absolute value of an integer
int abs(int a) {
	return a < 0? -a : a;
}

// Function to calculate p raised to the power of q
int pow(int p, int q) {
	int result = 1;
	for (int i = 0; i < q; i++) {
		result = (result * p) % MOD;
	}
	return result;
}

// Function to calculate n raised to the power of p modulo mod
int powMod(int n, int p) {
	if (p == 0) {
		return 1;
	} else if (p % 2 == 0) {
		int t = powMod(n, p / 2);
		return (t * t) % MOD;
	} else {
		return (n * powMod(n, p - 1)) % MOD;
	}
}

// Function to find the minimum value among a list of integers
int min(int nums[], int n) {
	if (n == 0) {
		return 0;
	}
	int result = nums[0];
	for (int i = 1; i < n; i++) {
		result = result < nums[i]? result : nums[i];
	}
	return result;
}

// Function to find the maximum value among a list of integers
int max(int nums[], int n) {
	if (n == 0) {
		return 0;
	}
	int result = nums[0];
	for (int i = 1; i < n; i++) {
		result = result > nums[i]? result : nums[i];
	}
	return result;
}

// Function to check if a string exists in an array of strings
int strSearch(char *strings[], int n, char *target) {
	for (int i = 0; i < n; i++) {
		if (strcmp(strings[i], target) == 0) {
			return 1;
		}
	}
	return 0;
}

// Function to print an array of integers
void printIntArray(int nums[], int n) {
	printf("[");
	for (int i = 0; i < n; i++) {
		printf("%d", nums[i]);
		if (i < n - 1) {
			printf(", ");
		}
	}
	printf("]");
}

// Function to calculate x modulo mod
int calcMod(int x) {
	return x % MOD;
}

// Function to reverse a string
char *reverse(char *s) {
	int length = strlen(s);
	char *result = malloc(length + 1);
	for (int i = 0; i < length; i++) {
		result[i] = s[length - i - 1];
	}
	result[length] = '\0';
	return result;
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
	int sqrtN = (int) sqrt(n);
	for (int i = 3; i <= sqrtN; i += 2) {
		if (n % i == 0) {
			return 0;
		}
	}
	return 1;
}

// Function to check if an integer exists in a slice
int contains(int nums[], int n, int target) {
	for (int i = 0; i < n; i++) {
		if (nums[i] == target) {
			return 1;
		}
	}
	return 0;
}

// Function to create a range of integers from min to max
int *makeRange(int min, int max) {
	int *result = malloc((max - min + 1) * sizeof(int));
	for (int i = 0; i < max - min + 1; i++) {
		result[i] = min + i;
	}
	return result;
}

// Function to generate the powerset of a given slice of integers
int **powerset2(int nums[], int n, int *size) {
	*size = (int) pow(2, n);
	int **result = malloc(*size * sizeof(int *));
	for (int i = 0; i < *size; i++) {
		result[i] = malloc(n * sizeof(int));
	}
	int index = 0;
	result[index] = malloc(0 * sizeof(int));
	index++;
	for (int i = 0; i < n; i++) {
		int max = index;
		for (int j = 0; j < max; j++) {
			int *subset = result[j];
			int *newSubset = malloc((n + 1) * sizeof(int));
			for (int k = 0; k < n; k++) {
				newSubset[k] = subset[k];
			}
			newSubset[n] = nums[i];
			result[index] = newSubset;
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
	int *divisor = malloc(n * sizeof(int));
	int index = 0;
	divisor[index++] = 1;
	if (n!= 1) {
		divisor[index++] = n;
	}
	int sqrtN = (int) sqrt(n);
	for (int i = 2; i <= sqrtN; i++) {
		if (n % i == 0) {
			divisor[index++] = i;
			divisor[index++] = n / i;
		}
	}
	int *divisorArray = malloc(index * sizeof(int));
	for (int i = 0; i < index; i++) {
		divisorArray[i] = divisor[i];
	}
	free(divisor);
	return divisorArray;
}

// Custom heap type for integers
typedef struct {
	int *array;
	int size;
	int capacity;
} IntHeap;

// Function to initialize a new integer heap
IntHeap *initHeap() {
	IntHeap *ih = malloc(sizeof(IntHeap));
	ih->array = NULL;
	ih->size = 0;
	ih->capacity = 0;
	return ih;
}

// Function to push an integer onto the heap
void pushHeap(IntHeap *ih, int n) {
	if (ih->size == ih->capacity) {
		if (ih->capacity == 0) {
			ih->capacity = 1;
		} else {
			ih->capacity *= 2;
		}
		int *newArray = realloc(ih->array, ih->capacity * sizeof(int));
		ih->array = newArray;
	}
	ih->array[ih->size] = n;
	ih->size++;
	int i = ih->size - 1;
	while (i > 0 && ih->array[i] > ih->array[(i - 1) / 2]) {
		int temp = ih->array[i];
		ih->array[i] = ih->array[(i - 1) / 2];
		ih->array[(i - 1) / 2] = temp;
		i = (i - 1) / 2;
	}
}

// Function to pop an integer from the heap
int popHeap(IntHeap *ih) {
	if (ih->size == 0) {
		return 0;
	}
	int result = ih->array[0];
	ih->array[0] = ih->array[ih->size - 1];
	ih->size--;
	int i = 0;
	while (i < ih->size) {
		int left = 2 * i + 1;
		int right = 2 * i + 2;
		int swap = i;
		if (left < ih->size && ih->array[swap] < ih->array[left]) {
			swap = left;
		}
		if (right < ih->size && ih->array[swap] < ih->array[right]) {
			swap = right;
		}
		if (swap == i) {
			break;
		}
		int temp = ih->array[i];
		ih->array[i] = ih->array[swap];
		ih->array[swap] = temp;
		i = swap;
	}
	return result;
}

// Function to calculate factorial modulo mod
int factMod(int n) {
	int value = 1;
	for (int i = 2; i <= n; i++) {
		value = (value * i) % MOD;
	}
	return value;
}

// Function to calculate combinations modulo mod
int combinationMod(int n, int k) {
	int factN = factMod(n);
	int factK = factMod(k);
	int factNK = factMod(n - k);
	int factKR = powMod(factK, MOD - 2);
	int factNKR = powMod(factNK, MOD - 2);
	return (factN * calcMod(factKR * factNKR)) % MOD;
}

// Function to find prime factors of a number
int *primeFactors(int n) {
	int *factors = malloc(n * sizeof(int));
	int index = 0;
	for (int i = 2; i * i <= n; i++) {
		int r = n % i;
		if (r!= 0) {
			i += 1;
		} else if (r == 0) {
			n /= i;
			factors[index++] = i;
		}
	}
	if (n > 1) {
		factors[index++] = n;
	}
	int *factorsArray = malloc(index * sizeof(int));
	for (int i = 0; i < index; i++) {
		factorsArray[i] = factors[i];
	}
	free(factors);
	return factorsArray;
}

// Function to translate the above Go code to C.
int main() {
	// Read an integer input
	Scanner scanner;
	scanner.buffer = malloc(INITIAL_BUF_SIZE * sizeof(char));
	scanner.position = 0;
	scanner.length = 0;
	int N = getInt(&scanner);

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

// Output
//
// $./main
// 1
// pon
// $./main
// 2
// hon
// $./main
// 3
// bon
// $./main
// 4
// pon
// $./main
// 5
// hon
// $./main
// 6
// pon
// $./main
// 7
// hon
// $./main
// 8
// pon
// $./main
// 9
// hon
// $./main
// 10
// pon
// $./main
// 11
// hon
// $./main
// 12
// pon
// $./main
// 13
// hon
// $./main
// 14
// pon
// $./main
// 15
// hon
// $./main
// 16
// pon
// $./main
// 17
// hon
// $./main
// 18
// pon
// $./main
// 19
// hon
// $./main
// 20
// pon
// $./main
// 21
// hon
// $./main
// 22
// pon
// $./main
// 23
// hon
// $./main
// 24
// pon
// $./main
// 25
// hon
// $./main
// 26
// pon
// $./main
// 27
// hon
// $./main
// 28
// pon
// $./main
// 29
// hon
// $./main
// 30
// pon
// $./main
// 31
// hon
// $./main
// 32
// pon
// $./main
// 33
// hon
// $./main
// 34
// pon
// $./main
// 35
// hon
// $./main
// 36
// pon
// $./main
// 37
// hon
// $./main
// 38
// pon
// $./main
// 39
// hon
// $./main
// 40
// pon
// $./main
// 41
// hon
// $./main
// 42
// pon
// $./main
// 43
// hon
// $./main
// 44
// pon
// $./main
// 45
// hon
// $./main
// 46
// pon
// $./main
// 47
// hon
// $./main
// 48
// pon
// $./main
// 49
// hon
// $./main
// 50
// pon
// $./main
// 51
// hon
// $./main
// 52
// pon
// $./main
// 53
// hon
// $./main
// 54
// pon
// $./main
// 55
// hon
// $./main
// 56
// pon
// $./main
// 57
// hon
// $./main
// 58
// pon
// $./main
// 59
// hon
// $./main
// 60
// pon
// $./main
// 61
// hon
// $./main
// 62
// pon
// $./main
// 63
// hon
// $./main
// 64
// pon
// $./main
// 65
// hon
// $./main
// 66
// pon
// $./main
// 67
// hon
// $./main
// 68
// pon
// $./main
// 69
// hon
// $./main
// 70
// pon
// $./main
// 71
// hon
// $./main
// 72
// pon
// $./main
// 73
// hon
// $./main
// 74
// pon
// $./main
// 75
// hon
// $./main
// 76
// pon
// $./main
// 77
// hon
// $./main
// 78
// pon
// $./main
// 79
// hon
// $./main
// 80
// pon
// $./main
// 81
// hon
// $./main
// 82
// pon
// $./main
// 83
// hon
// $./ma