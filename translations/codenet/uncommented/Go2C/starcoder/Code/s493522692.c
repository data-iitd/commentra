#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

//Util
int nextInt() {
	int i;
	scanf("%d", &i);
	return i;
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

int absFloat64(double a) {
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
	int n;
	sscanf(s, "%d", &n);
	return n;
}

char* reverse(char* s) {
	char* r = (char*)malloc(sizeof(char) * (strlen(s) + 1));
	int i;
	for (i = 0; i < strlen(s); i++) {
		r[i] = s[strlen(s) - i - 1];
	}
	r[i] = '\0';
	return r;
}

int powInt(int p, int q) {
	return (int)pow(p, q);
}

bool isPrime(int x) {
	if (x == 1) {
		return false;
	}
	if (x == 2) {
		return true;
	}
	if (x%2 == 0) {
		return false;
	}

	bool b = true;
	int rootx = (int)sqrt(x);
	int i = 3;
	for (i = 3; i <= rootx; i += 2) {
		if (x%i == 0) {
			b = false;
			break;
		}
	}
	return b;
}

int PrimeFactors(int n) {
	// Get the number of 2s that divide n
	int count = 0;
	while (n%2 == 0) {
		count++;
		n = n / 2;
	}

	// n must be odd at this point. so we can skip one element
	// (note i = i + 2)
	for (int i = 3; i*i <= n; i = i + 2) {
		// while i divides n, append i and divide n
		while (n%i == 0) {
			count++;
			n = n / i;
		}
	}

	// This condition is to handle the case when n is a prime number
	// greater than 2
	if (n > 2) {
		count++;
	}

	return count;
}

int PrimeFactorsMap(int n) {
	int count = 0;
	// Get the number of 2s that divide n
	while (n%2 == 0) {
		count++;
		n = n / 2;
	}

	// n must be odd at this point. so we can skip one element
	// (note i = i + 2)
	for (int i = 3; i*i <= n; i = i + 2) {
		// while i divides n, append i and divide n
		while (n%i == 0) {
			count++;
			n = n / i;
		}
	}

	// This condition is to handle the case when n is a prime number
	// greater than 2
	if (n > 2) {
		count++;
	}

	return count;
}

int sumInts(int* x, int n) {

	int total = 0;
	for (int i = 0; i < n; i++) {
		total += x[i];
	}

	return total;
}

int gcd(int a, int b) {
	if (b == 0) {
		return a;
	}
	return gcd(b, a%b);
}

int lcm(int x, int y) {

	return x * y / gcd(x, y);

}

//Main
int main() {
	// 'S'がN個、'c'がM個
	int N, M;
	scanf("%d %d", &N, &M);
	int tmp = minInt(N, M/2);
	int ans = 0;
	ans += tmp;
	N -= tmp;
	M -= tmp * 2;
	//printf("%d %d %d\n", ans, N, M);
	printf("%d\n", ans + M/4);
}

