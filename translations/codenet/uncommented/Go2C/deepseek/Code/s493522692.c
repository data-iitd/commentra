#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// Util
char* nextStr() {
	static char buf[10000];
	scanf("%s", buf);
	return buf;
}

int nextInt() {
	return atoi(nextStr());
}

int maxInt(int a, int b) {
	return a > b ? a : b;
}

int minInt(int a, int b) {
	return a < b ? a : b;
}

int absInt(int a) {
	return a >= 0 ? a : -a;
}

double absFloat64(double a) {
	return a >= 0 ? a : -a;
}

double maxFloat64(double a, double b) {
	return a > b ? a : b;
}

double minFloat64(double a, double b) {
	return a < b ? a : b;
}

int str2Int(char* s) {
	return atoi(s);
}

char* reverse(char* s) {
	int len = strlen(s);
	for (int i = 0, j = len - 1; i < j; i++, j--) {
		char temp = s[i];
		s[i] = s[j];
		s[j] = temp;
	}
	return s;
}

int powInt(int p, int q) {
	return (int)pow(p, q);
}

int isPrime(int x) {
	if (x == 1) {
		return 0;
	}
	if (x == 2) {
		return 1;
	}
	if (x % 2 == 0) {
		return 0;
	}

	int b = 1;
	int rootx = (int)sqrt(x);
	for (int i = 3; i <= rootx; i += 2) {
		if (x % i == 0) {
			b = 0;
			break;
		}
	}
	return b;
}

int* PrimeFactors(int n, int* size) {
	int* pfs = (int*)malloc(1000 * sizeof(int));
	*size = 0;
	// Get the number of 2s that divide n
	while (n % 2 == 0) {
		pfs[*size] = 2;
		(*size)++;
		n = n / 2;
	}

	// n must be odd at this point. so we can skip one element
	// (note i = i + 2)
	for (int i = 3; i * i <= n; i += 2) {
		// while i divides n, append i and divide n
		while (n % i == 0) {
			pfs[*size] = i;
			(*size)++;
			n = n / i;
		}
	}

	// This condition is to handle the case when n is a prime number
	// greater than 2
	if (n > 2) {
		pfs[*size] = n;
		(*size)++;
	}

	return pfs;
}

int PrimeFactorsMap(int n) {
	int pfs[1000] = {0};
	int size = 0;
	// Get the number of 2s that divide n
	while (n % 2 == 0) {
		pfs[2]++;
		n = n / 2;
	}

	// n must be odd at this point. so we can skip one element
	// (note i = i + 2)
	for (int i = 3; i * i <= n; i += 2) {
		// while i divides n, append i and divide n
		while (n % i == 0) {
			pfs[i]++;
			n = n / i;
		}
	}

	// This condition is to handle the case when n is a prime number
	// greater than 2
	if (n > 2) {
		pfs[n]++;
	}

	return pfs;
}

int sumInts(int* x, int size) {
	int total = 0;
	for (int i = 0; i < size; i++) {
		total += x[i];
	}
	return total;
}

int gcd(int a, int b) {
	if (b == 0) {
		return a;
	}
	return gcd(b, a % b);
}

int lcm(int x, int y) {
	return x * y / gcd(x, y);
}

// Main
#define INITIAL_BUF_SIZE 10000
#define MAX_BUF_SIZE 1000000
#define MOD 1000000007

int main() {
	int N, M;
	scanf("%d %d", &N, &M);
	int tmp = minInt(N, M / 2);
	int ans = 0;
	ans += tmp;
	N -= tmp;
	M -= tmp * 2;
	printf("%d\n", ans + M / 4);
	return 0;
}
