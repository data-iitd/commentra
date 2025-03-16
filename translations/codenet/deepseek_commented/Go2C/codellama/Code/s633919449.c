#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define initialBufSize 10000
#define maxBufSize 1000000
#define mod 1e9 + 7

int getInt() {
	char *str = (char *)malloc(initialBufSize * sizeof(char));
	char *endptr;
	int i;

	if (fgets(str, initialBufSize, stdin) == NULL) {
		return -1;
	}

	i = strtol(str, &endptr, 10);
	if (endptr == str || *endptr != '\n') {
		return -1;
	}

	return i;
}

int *getIntArray(int n) {
	int *array = (int *)malloc(n * sizeof(int));
	int i;

	for (i = 0; i < n; i++) {
		array[i] = getInt();
	}

	return array;
}

char *getString() {
	char *str = (char *)malloc(initialBufSize * sizeof(char));
	char *endptr;

	if (fgets(str, initialBufSize, stdin) == NULL) {
		return NULL;
	}

	return str;
}

char **getStringArray(int n) {
	char **array = (char **)malloc(n * sizeof(char *));
	int i;

	for (i = 0; i < n; i++) {
		array[i] = getString();
	}

	return array;
}

int abs(int a) {
	return (a < 0) ? -a : a;
}

int pow(int p, int q) {
	return (int)pow(p, q);
}

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

int min(int nums[], int n) {
	int res = nums[0];
	int i;

	for (i = 1; i < n; i++) {
		if (nums[i] < res) {
			res = nums[i];
		}
	}

	return res;
}

int max(int nums[], int n) {
	int res = nums[0];
	int i;

	for (i = 1; i < n; i++) {
		if (nums[i] > res) {
			res = nums[i];
		}
	}

	return res;
}

int strSearch(char *a[], char *b) {
	int i;

	for (i = 0; a[i] != NULL; i++) {
		if (strcmp(a[i], b) == 0) {
			return 1;
		}
	}

	return 0;
}

void printIntArray(int *array, int n) {
	int i;

	printf("%d", array[0]);
	for (i = 1; i < n; i++) {
		printf(" %d", array[i]);
	}
	printf("\n");
}

int calcMod(int x) {
	return x % mod;
}

char *reverse(char *s) {
	int i, j;
	char *t = (char *)malloc((strlen(s) + 1) * sizeof(char));

	for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
		t[i] = s[j];
		t[j] = s[i];
	}
	t[i] = '\0';

	return t;
}

int isPrime(int n) {
	if (n < 2) {
		return 0;
	} else if (n == 2) {
		return 1;
	} else if (n % 2 == 0) {
		return 0;
	}

	int sqrtN = (int)sqrt(n);
	int i;

	for (i = 3; i <= sqrtN; i += 2) {
		if (n % i == 0) {
			return 0;
		}
	}

	return 1;
}

int contains(int *s, int n, int e) {
	int i;

	for (i = 0; i < n; i++) {
		if (s[i] == e) {
			return 1;
		}
	}

	return 0;
}

int *makeRange(int min, int max) {
	int *a = (int *)malloc((max - min + 1) * sizeof(int));
	int i;

	for (i = 0; i < max - min + 1; i++) {
		a[i] = min + i;
	}

	return a;
}

int **powerset2(int *nums, int n) {
	int **result = (int **)malloc(pow(2, n) * sizeof(int *));
	int index = 0;

	result[index] = (int *)malloc(0 * sizeof(int));
	index++;

	int i, j;

	for (i = 0; i < n; i++) {
		int max = index;
		for (j = 0; j < max; j++) {
			result[index] = (int *)malloc((i + 1) * sizeof(int));
			memcpy(result[index], result[j], i * sizeof(int));
			result[index][i] = nums[i];
			index++;
		}
	}

	return result;
}

int *copyAndAppend(int *nums, int n) {
	int *dst = (int *)malloc((n + 1) * sizeof(int));
	memcpy(dst, nums, n * sizeof(int));
	dst[n] = n;
	return dst;
}

int calcGcd(int x, int y) {
	if (y == 0) {
		return x;
	} else if (x >= y) {
		return calcGcd(y, x % y);
	} else {
		return calcGcd(x, y % x);
	}
}

int *getDivisor(int n) {
	int *divisor = (int *)malloc(0 * sizeof(int));
	int i;

	divisor = (int *)realloc(divisor, (1 * sizeof(int)));
	divisor[0] = 1;
	if (n != 1) {
		divisor = (int *)realloc(divisor, (2 * sizeof(int)));
		divisor[1] = n;
	}

	int sqrtN = (int)sqrt(n);
	int i;

	for (i = 2; i <= sqrtN; i += 2) {
		if (n % i == 0) {
			divisor = (int *)realloc(divisor, (i * sizeof(int)));
			divisor[i - 1] = i;
			divisor = (int *)realloc(divisor, ((i + 1) * sizeof(int)));
			divisor[i] = n / i;
		}
	}

	return divisor;
}

int *intHeap;

int intHeapLen(intHeap h) {
	return h->len;
}

int intHeapLess(intHeap h, int i, int j) {
	return h->array[i] > h->array[j];
}

void intHeapSwap(intHeap h, int i, int j) {
	int tmp = h->array[i];
	h->array[i] = h->array[j];
	h->array[j] = tmp;
}

void intHeapPush(intHeap h, int x) {
	h->array[h->len] = x;
	h->len++;
}

int intHeapPop(intHeap h) {
	h->len--;
	return h->array[h->len];
}

intHeap initHeap() {
	intHeap h = (intHeap)malloc(sizeof(struct intHeap));
	h->array = (int *)malloc(initialBufSize * sizeof(int));
	h->len = 0;
	h->capacity = initialBufSize;
	return h;
}

void intHeapPushHeap(intHeap h, int n) {
	if (h->len == h->capacity) {
		h->capacity *= 2;
		h->array = (int *)realloc(h->array, h->capacity * sizeof(int));
	}
	intHeapPush(h, n);
	intHeapPush(h, n);
}

int intHeapPopHeap(intHeap h) {
	intHeapPop(h);
	intHeapPop(h);
}

int factMod(int n) {
	int value = 1;
	for (; n > 1; n--) {
		value = (value * n) % mod;
	}
	return value;
}

int combinationMod(int n, int k) {
	int factN = factMod(n);
	int factK = factMod(k);
	int factNK = factMod(n - k);
	int factKR = powMod(factK, mod - 2);
	int factNKR = powMod(factNK, mod - 2);
	return (factN * (factKR * factNKR)) % mod;
}

int *primeFactors(int n) {
	int *factors = (int *)malloc(0 * sizeof(int));
	int i;

	for (i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			factors = (int *)realloc(factors, (i * sizeof(int)));
			factors[i - 1] = i;
			n /= i;
		}
	}

	if (n > 1) {
		factors = (int *)realloc(factors, (i * sizeof(int)));
		factors[i - 1] = n;
	}

	return factors;
}

