
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Utility Functions

// Reads the next input as a string
char* nextStr() {
	static char str[100000];
	fgets(str, 100000, stdin);
	return str;
}

// Reads the next input as an integer
int nextInt() {
	int i;
	scanf("%d", &i);
	return i;
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
float64 absFloat64(float64 a) {
	if (a >= 0) {
		return a;
	} else {
		return -a;
	}
}

// Returns the maximum of two float64 values
float64 maxFloat64(float64 a, float64 b) {
	if (a > b) {
		return a;
	} else {
		return b;
	}
}

// Returns the minimum of two float64 values
float64 minFloat64(float64 a, float64 b) {
	if (a > b) {
		return b;
	} else {
		return a;
	}
}

// Converts a string to an integer
int str2Int(char* s) {
	int n = atoi(s);
	return n;
}

// Reverses a string
char* reverse(char* s) {
	int len = strlen(s);
	int i, j;
	char c;
	for (i = 0, j = len - 1; i < j; i++, j--) {
		c = s[i];
		s[i] = s[j];
		s[j] = c;
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
	int i = 3;
	for (i = 3; i <= rootx; i = i + 2) {
		// while i divides n, append i and divide n
		if (x % i == 0) {
			b = 0;
			break;
		}
	}
	return b;
}

// Returns the prime factors of a number
int* PrimeFactors(int n) {
	int* pfs = (int*)malloc(sizeof(int) * 1000000);
	int pfs_len = 0;
	// Get the number of 2s that divide n
	while (n % 2 == 0) {
		pfs[pfs_len] = 2;
		pfs_len++;
		n = n / 2;
	}

	// n must be odd at this point. so we can skip one element
	// (note i = i + 2)
	for (int i = 3; i * i <= n; i = i + 2) {
		// while i divides n, append i and divide n
		while (n % i == 0) {
			pfs[pfs_len] = i;
			pfs_len++;
			n = n / i;
		}
	}

	// This condition is to handle the case when n is a prime number
	// greater than 2
	if (n > 2) {
		pfs[pfs_len] = n;
		pfs_len++;
	}

	return pfs;
}

// Returns the prime factors of a number as a map
int** PrimeFactorsMap(int n) {
	int** pfs = (int**)malloc(sizeof(int*) * 1000000);
	int pfs_len = 0;
	// Get the number of 2s that divide n
	while (n % 2 == 0) {
		pfs[pfs_len] = (int*)malloc(sizeof(int) * 2);
		pfs[pfs_len][0] = 2;
		pfs[pfs_len][1] = 1;
		pfs_len++;
		n = n / 2;
	}

	// n must be odd at this point. so we can skip one element
	// (note i = i + 2)
	for (int i = 3; i * i <= n; i = i + 2) {
		// while i divides n, append i and divide n
		while (n % i == 0) {
			pfs[pfs_len] = (int*)malloc(sizeof(int) * 2);
			pfs[pfs_len][0] = i;
			pfs[pfs_len][1] = 1;
			pfs_len++;
			n = n / i;
		}
	}

	// This condition is to handle the case when n is a prime number
	// greater than 2
	if (n > 2) {
		pfs[pfs_len] = (int*)malloc(sizeof(int) * 2);
		pfs[pfs_len][0] = n;
		pfs[pfs_len][1] = 1;
		pfs_len++;
	}

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
	return gcd(b, a % b);
}

// Computes the least common multiple of two integers
int lcm(int x, int y) {
	return x * y / gcd(x, y);
}

// Constants and Variables

// Main Function
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
	//fmt.Println(ans, N, M)
	printf("%d\n", ans + M / 4);
	return 0;
}

