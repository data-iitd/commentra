#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

// Utility Functions

// Reads the next input as a string
char* nextStr() {
	char* s = NULL;
	size_t len = 0;
	getline(&s, &len, stdin);
	return s;
}

// Reads the next input as an integer
int nextInt() {
	int n = 0;
	scanf("%d", &n);
	return n;
}

// Returns the maximum of two integers
int maxInt(int a, int b) {
	if (a > b) {
		return a;
	} else {
		return b;
	}
}

// Returns the minimum of two integers
int minInt(int a, int b) {
	if (a > b) {
		return b;
	} else {
		return a;
	}
}

// Returns the absolute value of an integer
int absInt(int a) {
	if (a >= 0) {
		return a;
	} else {
		return -a;
	}
}

// Returns the absolute value of a float64
double absFloat64(double a) {
	if (a >= 0) {
		return a;
	} else {
		return -a;
	}
}

// Returns the maximum of two float64 values
double maxFloat64(double a, double b) {
	if (a > b) {
		return a;
	} else {
		return b;
	}
}

// Returns the minimum of two float64 values
double minFloat64(double a, double b) {
	if (a > b) {
		return b;
	} else {
		return a;
	}
}

// Converts a string to an integer
int str2Int(char* s) {
	int n = 0;
	sscanf(s, "%d", &n);
	return n;
}

// Reverses a string
char* reverse(char* s) {
	char* r = malloc(sizeof(char) * (strlen(s) + 1));
	int i = 0;
	int j = strlen(s) - 1;
	while (i < j) {
		r[i] = s[j];
		r[j] = s[i];
		i++;
		j--;
	}
	r[i] = '\0';
	return r;
}

// Raises an integer to the power of another integer
int powInt(int p, int q) {
	return (int)pow((double)p, (double)q);
}

// Checks if a number is prime
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
	int rootx = (int)sqrt((double)x);
	int i = 3;
	while (i <= rootx) {
		if (x%i == 0) {
			b = false;
			break;
		}
		i += 2;
	}
	return b;
}

// Returns the prime factors of a number
int* PrimeFactors(int n, int* len) {
	// Get the number of 2s that divide n
	int* pfs = malloc(sizeof(int) * 100);
	int i = 0;
	while (n%2 == 0) {
		pfs[i] = 2;
		i++;
		n = n / 2;
	}

	// n must be odd at this point. so we can skip one element
	// (note i = i + 2)
	for (int i = 3; i*i <= n; i = i + 2) {
		// while i divides n, append i and divide n
		while (n%i == 0) {
			pfs[i] = i;
			i++;
			n = n / i;
		}
	}

	// This condition is to handle the case when n is a prime number
	// greater than 2
	if (n > 2) {
		pfs[i] = n;
		i++;
	}

	*len = i;
	return pfs;
}

// Returns the prime factors of a number as a map
int* PrimeFactorsMap(int n, int* len) {
	int* pfs = malloc(sizeof(int) * 100);
	int i = 0;
	// Get the number of 2s that divide n
	while (n%2 == 0) {
		pfs[i] = 2;
		i++;
		n = n / 2;
	}

	// n must be odd at this point. so we can skip one element
	// (note i = i + 2)
	for (int i = 3; i*i <= n; i = i + 2) {
		// while i divides n, append i and divide n
		while (n%i == 0) {
			pfs[i] = i;
			i++;
			n = n / i;
		}
	}

	// This condition is to handle the case when n is a prime number
	// greater than 2
	if (n > 2) {
		pfs[i] = n;
		i++;
	}

	*len = i;
	return pfs;
}

// Sums up a slice of integers
int sumInts(int* x, int len) {
	int total = 0;
	for (int i = 0; i < len; i++) {
		total += x[i];
	}
	return total;
}

// Computes the greatest common divisor of two integers
int gcd(int a, int b) {
	if (b == 0) {
		return a;
	}
	return gcd(b, a%b);
}

// Computes the least common multiple of two integers
int lcm(int x, int y) {
	return x * y / gcd(x, y);
}

// Constants and Variables

const int initialBufSize = 10000;
const int maxBufSize = 1000000;
const int mod = 1e9 + 7;

// Main Function
int main() {
	// 'S'がN個、'c'がM個
	int N = nextInt();
	int M = nextInt();
	int tmp = minInt(N, M/2);
	int ans = 0;
	ans += tmp;
	N -= tmp;
	M -= tmp * 2;
	//printf("%d %d\n", ans, N, M);
	printf("%d\n", ans + M/4);
	return 0;
}

