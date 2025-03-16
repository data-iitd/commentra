#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// Utility Functions

// Reads the next input as a string
char* nextStr() {
	static char buf[10000];
	scanf("%s", buf);
	return buf;
}

// Reads the next input as an integer
int nextInt() {
	int n;
	scanf("%d", &n);
	return n;
}

// Returns the maximum of two integers
int maxInt(int a, int b) {
	return a > b ? a : b;
}

// Returns the minimum of two integers
int minInt(int a, int b) {
	return a < b ? a : b;
}

// Returns the absolute value of an integer
int absInt(int a) {
	return a >= 0 ? a : -a;
}

// Returns the absolute value of a float64
double absFloat64(double a) {
	return a >= 0 ? a : -a;
}

// Returns the maximum of two float64 values
double maxFloat64(double a, double b) {
	return a > b ? a : b;
}

// Returns the minimum of two float64 values
double minFloat64(double a, double b) {
	return a < b ? a : b;
}

// Converts a string to an integer
int str2Int(char* s) {
	return atoi(s);
}

// Reverses a string
char* reverse(char* s) {
	int len = strlen(s);
	for (int i = 0; i < len / 2; i++) {
		char temp = s[i];
		s[i] = s[len - i - 1];
		s[len - i - 1] = temp;
	}
	return s;
}

// Raises an integer to the power of another integer
int powInt(int p, int q) {
	return (int)pow(p, q);
}

// Checks if a number is prime
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

// Returns the prime factors of a number
int* PrimeFactors(int n, int* size) {
	int* pfs = (int*)malloc(100 * sizeof(int)); // Assuming the number of prime factors won't exceed 100
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

// Returns the prime factors of a number as a map
int PrimeFactorsMap(int n, int* count) {
	int pfs[100] = {0}; // Assuming the number of prime factors won't exceed 100
	*count = 0;
	// Get the number of 2s that divide n
	while (n % 2 == 0) {
		pfs[*count]++;
		n = n / 2;
	}

	// n must be odd at this point. so we can skip one element
	// (note i = i + 2)
	for (int i = 3; i * i <= n; i += 2) {
		// while i divides n, append i and divide n
		while (n % i == 0) {
			pfs[*count]++;
			n = n / i;
		}
	}

	// This condition is to handle the case when n is a prime number
	// greater than 2
	if (n > 2) {
		pfs[*count]++;
	}

	return pfs;
}

// Sums up a slice of integers
int sumInts(int* x, int size) {
	int total = 0;
	for (int i = 0; i < size; i++) {
		total += x[i];
	}
	return total;
}

// Computes the greatest common divisor of two integers
int gcd(int a, int b) {
	if (b == 0) {
		return a;
	}
	return gcd(b, a % b);
}

// Computes the least common multiple of two integers
int lcm(int x, int y) {
	return x * y / gcd(x, y);
}

// Constants and Variables

#define initialBufSize 10000
#define maxBufSize 1000000
#define mod 1e9 + 7

// Main Function
int main() {
	int N = nextInt();
	int M = nextInt();
	int tmp = minInt(N, M / 2);
	int ans = 0;
	ans += tmp;
	N -= tmp;
	M -= tmp * 2;
	printf("%d\n", ans + M / 4);
	return 0;
}

