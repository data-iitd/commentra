
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//Util
char* nextStr() {
	static char buf[1000000];
	fgets(buf, 1000000, stdin);
	return buf;
}

int nextInt() {
	static char buf[1000000];
	fgets(buf, 1000000, stdin);
	return atoi(buf);
}

int maxInt(int a, int b) {
	if (a > b) {
		return a;
	} else {
		return b;
	}
}

int minInt(int a, int b) {
	if (a > b) {
		return b;
	} else {
		return a;
	}
}

int absInt(int a) {
	if (a >= 0) {
		return a;
	} else {
		return -a;
	}
}

double absFloat64(double a) {
	if (a >= 0) {
		return a;
	} else {
		return -a;
	}
}

double maxFloat64(double a, double b) {
	if (a > b) {
		return a;
	} else {
		return b;
	}
}

double minFloat64(double a, double b) {
	if (a > b) {
		return b;
	} else {
		return a;
	}
}

int str2Int(char* s) {
	int n = atoi(s);
	return n;
}

char* reverse(char* s) {
	int len = strlen(s);
	int i, j;
	for (i = 0, j = len - 1; i < j; i++, j--) {
		char tmp = s[i];
		s[i] = s[j];
		s[j] = tmp;
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
	int i = 3;
	for (i = 3; i * i <= x; i = i + 2) {
		// while i divides n, append i and divide n
		if (x % i == 0) {
			b = 0;
			break;
		}
	}
	return b;
}

int* PrimeFactors(int n) {
	int* pfs = (int*)malloc(sizeof(int) * 1000000);
	// Get the number of 2s that divide n
	while (n % 2 == 0) {
		pfs[0] = 2;
		n = n / 2;
	}

	// n must be odd at this point. so we can skip one element
	// (note i = i + 2)
	for (int i = 3; i * i <= n; i = i + 2) {
		// while i divides n, append i and divide n
		while (n % i == 0) {
			pfs[0] = i;
			n = n / i;
		}
	}

	// This condition is to handle the case when n is a prime number
	// greater than 2
	if (n > 2) {
		pfs[0] = n;
	}

	return pfs;
}

int sumInts(int* x, int len) {

	int total = 0;
	for (int i = 0; i < len; i++) {
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

//Main
int main() {
	// 'S'がN個、'c'がM個
	int N, M;
	N = nextInt();
	M = nextInt();
	int tmp = minInt(N, M / 2);
	int ans = 0;
	ans += tmp;
	N -= tmp;
	M -= tmp * 2;
	//printf("%d %d\n", ans, N, M);
	printf("%d\n", ans + M / 4);
	return 0;
}

