#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define mod 1000000007

int getInt();
int *getIntArray(int n);
char *getString();
char **getStringArray(int n);
int abs(int a);
int pow(int p, int q);
int powMod(int n, int p);
int min(int nums[], int n);
int max(int nums[], int n);
int strSearch(char *a[], char *b);
void printIntArray(int array[], int n);
int calcMod(int x);
char *reverse(char *s);
int isPrime(int n);
int contains(int s[], int e);
int *makeRange(int min, int max);
int **powerset2(int nums[], int n);
int *copyAndAppend(int nums[], int n);
int calcGcd(int x, int y);
int *getDivisor(int n);

int main() {
	int N = getInt();

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
}

int getInt() {
	int i;
	scanf("%d", &i);
	return i;
}

int *getIntArray(int n) {
	int *array = (int *)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &array[i]);
	}
	return array;
}

char *getString() {
	char *s = (char *)malloc(sizeof(char) * 1000000);
	scanf("%s", s);
	return s;
}

char **getStringArray(int n) {
	char **array = (char **)malloc(sizeof(char *) * n);
	for (int i = 0; i < n; i++) {
		array[i] = (char *)malloc(sizeof(char) * 1000000);
		scanf("%s", array[i]);
	}
	return array;
}

int abs(int a) {
	return a < 0? -a : a;
}

int pow(int p, int q) {
	int res = 1;
	for (int i = 0; i < q; i++) {
		res *= p;
	}
	return res;
}

int powMod(int n, int p) {
	if (p == 0) {
		return 1;
	} else if (p % 2 == 0) {
		int t = powMod(n, p / 2);
		return calcMod(t * t);
	} else {
		return calcMod(n * powMod(n, p - 1));
	}
}

int min(int nums[], int n) {
	if (n == 0) {
		return 0;
	}
	int res = nums[0];
	for (int i = 0; i < n; i++) {
		res = res < nums[i]? res : nums[i];
	}
	return res;
}

int max(int nums[], int n) {
	if (n == 0) {
		return 0;
	}
	int res = nums[0];
	for (int i = 0; i < n; i++) {
		res = res > nums[i]? res : nums[i];
	}
	return res;
}

int strSearch(char *a[], char *b) {
	for (int i = 0; i < strlen(a); i++) {
		if (strcmp(a[i], b) == 0) {
			return 1;
		}
	}
	return 0;
}

void printIntArray(int array[], int n) {
	char str[1000000];
	sprintf(str, "[%d", array[0]);
	for (int i = 1; i < n; i++) {
		sprintf(str, "%s, %d", str, array[i]);
	}
	sprintf(str, "%s]", str);
	printf("%s\n", str);
}

int calcMod(int x) {
	return x % mod;
}

char *reverse(char *s) {
	char *res = (char *)malloc(sizeof(char) * 1000000);
	int i = 0;
	int j = strlen(s) - 1;
	while (i < j) {
		res[i] = s[j];
		res[j] = s[i];
		i++;
		j--;
	}
	res[i] = '\0';
	return res;
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

int contains(int s[], int e) {
	for (int i = 0; i < sizeof(s) / sizeof(int); i++) {
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

int **powerset2(int nums[], int n) {
	int length = pow(2, n);
	int **result = (int **)malloc(sizeof(int *) * length);

	int index = 0;
	result[index] = (int *)malloc(sizeof(int) * 0);
	index++;

	for (int i = 0; i < n; i++) {
		int max = index;
		for (int j = 0; j < max; j++) {
			int *tmp = (int *)malloc(sizeof(int) * (index + 1));
			for (int k = 0; k < index; k++) {
				tmp[k] = result[j][k];
			}
			tmp[index] = nums[i];
			result[index] = tmp;
			index++;
		}
	}

	return result;
}

int *copyAndAppend(int nums[], int n) {
	int *dst = (int *)malloc(sizeof(int) * (sizeof(nums) / sizeof(int) + 1));
	for (int i = 0; i < sizeof(nums) / sizeof(int); i++) {
		dst[i] = nums[i];
	}
	dst[sizeof(nums) / sizeof(int)] = n;
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
	int *divisor = (int *)malloc(sizeof(int) * 1000000);
	int index = 0;
	divisor[index] = 1;
	index++;
	if (n!= 1) {
		divisor[index] = n;
		index++;
	}

	int sqrt = (int)sqrt(n);
	for (int i = 2; i <= sqrt; i++) {
		if (n % i == 0) {
			divisor[index] = i;
			index++;
			divisor[index] = n / i;
			index++;
		}
	}

	int *divisorArray = (int *)malloc(sizeof(int) * index);
	for (int i = 0; i < index; i++) {
		divisorArray[i] = divisor[i];
	}
	return divisorArray;
}

