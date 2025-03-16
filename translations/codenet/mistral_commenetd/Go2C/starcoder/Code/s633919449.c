#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Constants for buffer sizes and modulo value
#define INITIAL_BUF_SIZE 10000
#define MAX_BUF_SIZE 1000000
#define MOD 1e9 + 7

// Function to read an integer from input
int getInt() {
	int i;
	scanf("%d", &i);
	return i;
}

// Function to read an array of integers from input
int* getIntArray(int n) {
	int* array = malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &array[i]);
	}
	return array;
}

// Function to read a string from input
char* getString() {
	char* str = malloc(sizeof(char) * 100);
	scanf("%s", str);
	return str;
}

// Function to read an array of strings from input
char** getStringArray(int n) {
	char** array = malloc(sizeof(char*) * n);
	for (int i = 0; i < n; i++) {
		array[i] = malloc(sizeof(char) * 100);
		scanf("%s", array[i]);
	}
	return array;
}

// Function to calculate the absolute value of an integer
int abs(int a) {
	return a < 0? -a : a;
}

// Function to calculate p raised to the power of q
int pow(int p, int q) {
	int res = 1;
	while (q > 0) {
		if (q & 1) {
			res = (res * p) % MOD;
		}
		p = (p * p) % MOD;
		q >>= 1;
	}
	return res;
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
	int res = nums[0];
	for (int i = 1; i < n; i++) {
		res = res < nums[i]? res : nums[i];
	}
	return res;
}

// Function to find the maximum value among a list of integers
int max(int nums[], int n) {
	int res = nums[0];
	for (int i = 1; i < n; i++) {
		res = res > nums[i]? res : nums[i];
	}
	return res;
}

// Function to check if a string exists in an array of strings
int strSearch(char** a, int n, char* b) {
	for (int i = 0; i < n; i++) {
		if (strcmp(a[i], b) == 0) {
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
char* reverse(char* s) {
	char* res = malloc(sizeof(char) * strlen(s));
	int i = 0, j = strlen(s) - 1;
	while (i < j) {
		res[i] = s[j];
		res[j] = s[i];
		i++;
		j--;
	}
	res[i] = s[i];
	return res;
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
int contains(int* s, int n, int e) {
	for (int i = 0; i < n; i++) {
		if (s[i] == e) {
			return 1;
		}
	}
	return 0;
}

// Function to create a range of integers from min to max
int* makeRange(int min, int max) {
	int* a = malloc(sizeof(int) * (max - min + 1));
	for (int i = 0; i < max - min + 1; i++) {
		a[i] = min + i;
	}
	return a;
}

// Function to generate the powerset of a given slice of integers
int** powerset2(int* nums, int n) {
	int length = pow(2, n);
	int** result = malloc(sizeof(int*) * length);

	int index = 0;
	result[index] = malloc(sizeof(int) * 0);
	index++;

	// Generate all subsets
	for (int i = 0; i < n; i++) {
		int max = index;
		for (int j = 0; j < max; j++) {
			int* tmp = malloc(sizeof(int) * (result[j][0] + 1));
			for (int k = 0; k < result[j][0] + 1; k++) {
				tmp[k] = result[j][k];
			}
			tmp[result[j][0]] = nums[i];
			result[index] = tmp;
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
int* getDivisor(int n) {
	int* divisor = malloc(sizeof(int) * 100);
	int index = 0;
	divisor[index++] = 1;
	if (n!= 1) {
		divisor[index++] = n;
	}

	int sqrt = (int) sqrt(n);
	for (int i = 2; i <= sqrt; i++) {
		if (n % i == 0) {
			divisor[index++] = i;
			divisor[index++] = n / i;
		}
	}

	int* divisorArray = malloc(sizeof(int) * index);
	for (int i = 0; i < index; i++) {
		divisorArray[i] = divisor[i];
	}
	return divisorArray;
}

// Custom heap type for integers
typedef struct {
	int* array;
	int size;
	int capacity;
} IntHeap;

// Function to initialize a new integer heap
IntHeap* initHeap() {
	IntHeap* ih = malloc(sizeof(IntHeap));
	ih->array = malloc(sizeof(int) * 100);
	ih->size = 0;
	ih->capacity = 100;
	return ih;
}

// Function to push an integer onto the heap
void pushHeap(IntHeap* h, int n) {
	if (h->size == h->capacity) {
		h->capacity *= 2;
		h->array = realloc(h->array, sizeof(int) * h->capacity);
	}
	h->array[h->size] = n;
	h->size++;
	int i = h->size - 1;
	while (i > 0 && h->array[i] > h->array[(i - 1) / 2]) {
		int tmp = h->array[i];
		h->array[i] = h->array[(i - 1) / 2];
		h->array[(i - 1) / 2] = tmp;
		i = (i - 1) / 2;
	}
}

// Function to pop an integer from the heap
int popHeap(IntHeap* h) {
	if (h->size == 0) {
		return -1;
	}
	int res = h->array[0];
	h->array[0] = h->array[h->size - 1];
	h->size--;
	int i = 0;
	while (i < h->size) {
		int l = 2 * i + 1;
		int r = 2 * i + 2;
		int j = i;
		if (l < h->size && h->array[l] > h->array[j]) {
			j = l;
		}
		if (r < h->size && h->array[r] > h->array[j]) {
			j = r;
		}
		if (j == i) {
			break;
		}
		int tmp = h->array[i];
		h->array[i] = h->array[j];
		h->array[j] = tmp;
		i = j;
	}
	return res;
}

// Function to calculate factorial modulo mod
int factMod(int n) {
	int value = 1;
	for (; n > 1; n--) {
		value = (value * n) % MOD;
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
	return (factN * (factKR * factNKR)) % MOD;
}

// Function to find prime factors of a number
int* primeFactors(int n) {
	int* factors = malloc(sizeof(int) * 100);
	int index = 0;
	int i = 2;
	for (i = 2; i * i <= n; i++) {
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
	int* factorsArray = malloc(sizeof(int) * index);
	for (int i = 0; i < index; i++) {
		factorsArray[i] = factors[i];
	}
	return factorsArray;
}

// Function to translate the Go code to C
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

// 