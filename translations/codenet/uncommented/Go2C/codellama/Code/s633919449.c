
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define initialBufSize 10000
#define maxBufSize 1000000
#define mod 1e9 + 7

int getInt() {
	int i;
	scanf("%d", &i);
	return i;
}

int getIntArray(int n) {
	int *array = (int *)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &array[i]);
	}
	return array;
}

char *getString() {
	char *str = (char *)malloc(sizeof(char) * 10000);
	scanf("%s", str);
	return str;
}

char **getStringArray(int n) {
	char **array = (char **)malloc(sizeof(char *) * n);
	for (int i = 0; i < n; i++) {
		array[i] = getString();
	}
	return array;
}

int abs(int a) {
	return a < 0 ? -a : a;
}

int pow(int p, int q) {
	if (q == 0) {
		return 1;
	} else if (q % 2 == 0) {
		return pow(p, q / 2) * pow(p, q / 2);
	} else {
		return p * pow(p, q - 1);
	}
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
	for (int i = 1; i < n; i++) {
		res = res < nums[i] ? res : nums[i];
	}
	return res;
}

int max(int nums[], int n) {
	int res = nums[0];
	for (int i = 1; i < n; i++) {
		res = res > nums[i] ? res : nums[i];
	}
	return res;
}

int strSearch(char **a, char *b) {
	for (int i = 0; i < n; i++) {
		if (strcmp(a[i], b) == 0) {
			return 1;
		}
	}
	return 0;
}

void printIntArray(int *array, int n) {
	char *strArray = (char *)malloc(sizeof(char) * 10000);
	strArray[0] = '[';
	for (int i = 0; i < n; i++) {
		sprintf(strArray + strlen(strArray), "%d", array[i]);
		if (i != n - 1) {
			strcat(strArray, ", ");
		}
	}
	strcat(strArray, "]");
	printf("%s\n", strArray);
}

int calcMod(int x) {
	return x % mod;
}

char *reverse(char *s) {
	int len = strlen(s);
	for (int i = 0; i < len / 2; i++) {
		char tmp = s[i];
		s[i] = s[len - i - 1];
		s[len - i - 1] = tmp;
	}
	return s;
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
	for (int i = 3; i <= sqrtN; i += 2) {
		if (n % i == 0) {
			return 0;
		}
	}

	return 1;
}

int contains(int *s, int n, int e) {
	for (int i = 0; i < n; i++) {
		if (s[i] == e) {
			return 1;
		}
	}
	return 0;
}

int *makeRange(int min, int max) {
	int *a = (int *)malloc(sizeof(int) * (max - min + 1));
	for (int i = 0; i < max - min + 1; i++) {
		a[i] = min + i;
	}
	return a;
}

int **powerset2(int *nums, int n) {
	int length = (int)pow(2, n);
	int **result = (int **)malloc(sizeof(int *) * length);

	int index = 0;
	result[index] = (int *)malloc(sizeof(int) * 0);
	index++;

	for (int i = 0; i < n; i++) {
		int max = index;
		for (int j = 0; j < max; j++) {
			result[index] = (int *)malloc(sizeof(int) * (i + 1));
			memcpy(result[index], result[j], sizeof(int) * i);
			result[index][i] = nums[i];
			index++;
		}
	}

	return result;
}

int *copyAndAppend(int *nums, int n) {
	int *dst = (int *)malloc(sizeof(int) * (n + 1));
	memcpy(dst, nums, sizeof(int) * n);
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
	int *divisor = (int *)malloc(sizeof(int) * 10000);
	divisor[0] = 1;
	if (n != 1) {
		divisor[1] = n;
	}

	int sqrtN = (int)sqrt(n);
	for (int i = 2; i <= sqrtN; i++) {
		if (n % i == 0) {
			divisor[2] = i;
			divisor[3] = n / i;
		}
	}

	int *divisorArray = (int *)malloc(sizeof(int) * 4);
	for (int i = 0; i < 4; i++) {
		divisorArray[i] = divisor[i];
	}
	return divisorArray;
}

typedef struct {
	int *array;
	int length;
} intHeap;

int intHeap_Len(intHeap *h) {
	return h->length;
}

int intHeap_Less(intHeap *h, int i, int j) {
	return h->array[i] > h->array[j];
}

void intHeap_Swap(intHeap *h, int i, int j) {
	int tmp = h->array[i];
	h->array[i] = h->array[j];
	h->array[j] = tmp;
}

void intHeap_Push(intHeap *h, int x) {
	h->array[h->length] = x;
	h->length++;
}

int intHeap_Pop(intHeap *h) {
	int old = h->array[h->length - 1];
	h->length--;
	return old;
}

intHeap *initHeap() {
	intHeap *ih = (intHeap *)malloc(sizeof(intHeap));
	ih->array = (int *)malloc(sizeof(int) * 10000);
	ih->length = 0;
	return ih;
}

void intHeap_pushHeap(intHeap *h, int n) {
	intHeap_Push(h, n);
}

int intHeap_popHeap(intHeap *h) {
	return intHeap_Pop(h);
}

int factMod(int n) {
	int value = 1;
	for (int i = 1; i <= n; i++) {
		value = (value * i) % mod;
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
	int *factors = (int *)malloc(sizeof(int) * 10000);
	int i = 2;
	for (; i * i <= n; i++) {
		int r = n % i;
		if (r != 0) {
			i++;
		} else if (r == 0) {
			n /= i;
			factors[0] = i;
		}
	}
	if (n > 1) {
		factors[1] = n;
	}
	return factors;
}

