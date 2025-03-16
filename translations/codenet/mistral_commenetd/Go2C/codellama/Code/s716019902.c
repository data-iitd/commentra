
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Constants
const int mod = 998244353;
const int facNum = 300001;

// Main function
int main() {
	// Initialize a new scanner
	FILE *input = fopen("input.txt", "r");
	int N;
	fscanf(input, "%d", &N);

	// Initialize a variable sum to 0
	int sum = 0;

	// Loop through numbers from 1 to N
	for (int i = 1; i <= N; i++) {
		// If the number is not divisible by 3 or 5, add it to the sum
		if (i%3 != 0 && i%5 != 0) {
			sum += i;
		}
	}

	// Print the result to the standard output
	printf("%d\n", sum);

	// Close the input file
	fclose(input);

	return 0;
}

// I/O
void scan(FILE *input, char *s) {
	// Scan the next token and return it as a string
	fscanf(input, "%s", s);
}

int scanInt(FILE *input) {
	// Convert the next token to an integer and return it
	int i;
	fscanf(input, "%d", &i);
	return i;
}

double scanFloat(FILE *input) {
	// Convert the next token to a float64 and return it
	double f;
	fscanf(input, "%lf", &f);
	return f;
}

char *scanBytes(FILE *input) {
	// Return the next token as a byte slice
	char *s;
	scan(input, s);
	return s;
}

int *scanInts(FILE *input, int n) {
	// Read n integers from the standard input and return them as a slice
	int *res = (int *)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++) {
		res[i] = scanInt(input);
	}
	return res;
}

double *scanFloats(FILE *input, int n) {
	// Read n floating-point numbers from the standard input and return them as a slice
	double *res = (double *)malloc(n * sizeof(double));
	for (int i = 0; i < n; i++) {
		res[i] = scanFloat(input);
	}
	return res;
}

// Math functions
int pow(int a, int n) {
	// Calculate a^n modulo mod
	int ans = 1;
	for (; n > 0; n >>= 1) {
		if (n & 1) {
			ans = ans * a % mod;
		}
		a = a * a % mod;
	}
	return ans;
}

int gcd(int a, int b) {
	// Calculate the greatest common divisor of a and b
	if (a < b) {
		return gcd(b, a);
	}
	for (; b != 0; a = b, b = a % b);
	return a;
}

int min(int a, int b) {
	// Return the minimum of a and b
	if (a < b) {
		return a;
	}
	return b;
}

// Combination function
int combination(int n, int k, int *fac, int *ifac) {
	// Calculate the binomial coefficient (n choose k) modulo mod
	if (n < k || n < 0) {
		return 0;
	}
	if (k == 0) {
		return 1;
	}
	// While n is not 0
	int ans = ifac[k] * ifac[n-k] % mod;
	return ans * fac[n] % mod;
}

// Factorial function
void factorial(int *fac, int *ifac) {
	// Calculate and return the factorial of all numbers from 0 to facNum-1
	fac[0] = 1;
	ifac[0] = 1;
	for (int i = 1; i < facNum; i++) {
		fac[i] = fac[i-1] * i % mod;
		ifac[i] = ifac[i-1] * pow(i, mod-2) % mod;
	}
}

// Lower bound function
int lowerBound(int *vs, int v, int n) {
	// Calculate the index of the first element in vs that is greater than or equal to v
	int n = n / 2;
	int m = n;
	for (; m != n;) {
		if (vs[n] < v) {
			n = (m-n+1)/2 + n;
			//m = m
		} else {
			m = n;
			n = n / 2;
		}
	}
	return n;
}

// IntSlice function
int *IntSlice(int n, int init) {
	// Create and initialize a slice of length n with the given initial value
	int *r = (int *)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++) {
		r[i] = init;
	}
	return r;
}

// 

