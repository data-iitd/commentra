#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define initialBufSize 10000
#define maxBufSize 1000000
#define mod 1e9 + 7

int getInt() {
	char buf[initialBufSize];
	int i = 0;
	int result = 0;
	int gotNum = scanf("%d", &result);
	while (gotNum == 0) {
		if (i >= maxBufSize) {
			printf("ERROR: Too long input.\n");
			exit(1);
		}
		buf[i] = getchar();
		if (buf[i] == '\n') {
			buf[i] = '\0';
			gotNum = sscanf(buf, "%d", &result);
		}
		i++;
	}
	return result;
}

char *getString() {
	char *buf = (char *)malloc(initialBufSize * sizeof(char));
	int i = 0;
	int gotStr = scanf("%s", buf);
	while (gotStr == 0) {
		if (i >= maxBufSize) {
			printf("ERROR: Too long input.\n");
			exit(1);
		}
		buf[i] = getchar();
		if (buf[i] == '\n') {
			buf[i] = '\0';
			gotStr = sscanf(buf, "%s", buf);
		}
		i++;
	}
	return buf;
}

int abs(int a) {
	return a >= 0 ? a : -a;
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

int min(int nums[], int size) {
	int res = nums[0];
	for (int i = 1; i < size; i++) {
		res = (res < nums[i]) ? res : nums[i];
	}
	return res;
}

int max(int nums[], int size) {
	int res = nums[0];
	for (int i = 1; i < size; i++) {
		res = (res > nums[i]) ? res : nums[i];
	}
	return res;
}

int strSearch(char *a[], char *b) {
	for (int i = 0; i < size; i++) {
		if (strcmp(a[i], b) == 0) {
			return 1;
		}
	}
	return 0;
}

void printIntArray(int array[], int size) {
	char buf[initialBufSize];
	sprintf(buf, "%d", array[0]);
	for (int i = 1; i < size; i++) {
		sprintf(buf, "%s, %d", buf, array[i]);
	}
	printf("%s\n", buf);
}

int calcMod(int x) {
	return x % mod;
}

char *reverse(char *s) {
	int len = strlen(s);
	char *buf = (char *)malloc((len + 1) * sizeof(char));
	for (int i = 0; i < len; i++) {
		buf[i] = s[len - i - 1];
	}
	buf[len] = '\0';
	return buf;
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

int main() {
	int N = getInt();
	int sqrtN = (int)sqrt(N);

	int min = N;
	for (int i = 1; i <= sqrtN; i++) {
		if (N % i != 0) {
			continue;
		}

		int num = i + (N / i) - 2;
		if (num < min) {
			min = num;
		}
	}

	printf("%d\n", min);

	return 0;
}
