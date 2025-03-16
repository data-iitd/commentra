
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
	scanner *sc = newScanner(stdin);

	// Read an integer N from the standard input
	int N = sc->i();

	// Initialize a variable sum to 0
	int sum = 0;

	// Loop through numbers from 1 to N
	for (int i = 1; i <= N; i++) {
		// If the number is not divisible by 3 or 5, add it to the sum
		if (i%3!= 0 && i%5!= 0) {
			sum += i;
		}
	}

	// Print the result to the standard output
	printf("%d\n", sum);
}

// I/O
typedef struct {
	char *s;
	int len;
	int pos;
} string;

// New scanner constructor
scanner *newScanner(FILE *input) {
	// Initialize a new scanner with the given input
	scanner *sc = (scanner *)malloc(sizeof(scanner));
	sc->s = (char *)malloc(1024);
	sc->len = fread(sc->s, 1, 1024, input);
	sc->pos = 0;
	return sc;
}

// Helper methods for scanner
string *s(scanner *s) {
	// Scan the next token and return it as a string
	while (s->s[s->pos] =='' || s->s[s->pos] == '\n' || s->s[s->pos] == '\t') {
		s->pos++;
	}
	int start = s->pos;
	while (s->s[s->pos]!='' && s->s[s->pos]!= '\n' && s->s[s->pos]!= '\t' && s->pos < s->len) {
		s->pos++;
	}
	int end = s->pos;
	string *res = (string *)malloc(sizeof(string));
	res->s = (char *)malloc(end-start+1);
	res->len = end-start;
	res->pos = 0;
	for (int i = start; i < end; i++) {
		res->s[res->pos] = s->s[i];
		res->pos++;
	}
	res->s[res->pos] = '\0';
	return res;
}

int i(scanner *s) {
	// Convert the next token to an integer and return it
	string *t = s(s);
	int res = atoi(t->s);
	free(t->s);
	free(t);
	return res;
}

float f(scanner *s) {
	// Convert the next token to a float64 and return it
	string *t = s(s);
	float res = atof(t->s);
	free(t->s);
	free(t);
	return res;
}

char *bs(scanner *s) {
	// Return the next token as a byte slice
	string *t = s(s);
	char *res = (char *)malloc(t->len+1);
	for (int i = 0; i < t->len; i++) {
		res[i] = t->s[i];
	}
	res[t->len] = '\0';
	free(t->s);
	free(t);
	return res;
}

int *is(scanner *s, int n) {
	// Read n integers from the standard input and return them as a slice
	int *res = (int *)malloc(n*sizeof(int));
	for (int i = 0; i < n; i++) {
		res[i] = i(s);
	}
	return res;
}

float *fs(scanner *s, int n) {
	// Read n floating-point numbers from the standard input and return them as a slice
	float *res = (float *)malloc(n*sizeof(float));
	for (int i = 0; i < n; i++) {
		res[i] = f(s);
	}
	return res;
}

// Math functions
int Pow(int a, int n) {
	// Calculate a^n modulo mod
	int ans = 1;
	for (int i = 0; i < 32; i++) {
		if (n & (1 << i)) {
			ans = ans * a % mod;
		}
		a = a * a % mod;
	}
	return ans;
}

int Gcd(int a, int b) {
	// Calculate the greatest common divisor of a and b
	if (a < b) {
		return Gcd(b, a);
	}
	while (b!= 0) {
		a = b;
		b = a % b;
	}
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
int *factorial() {
	// Calculate and return the factorial of all numbers from 0 to facNum-1
	int *fac = (int *)malloc(facNum*sizeof(int));
	fac[0] = 1;
	int *ifac = (int *)malloc(facNum*sizeof(int));
	ifac[0] = 1;
	for (int i = 1; i < facNum; i++) {
		fac[i] = fac[i-1] * i % mod;
		ifac[i] = ifac[i-1] * Pow(i, mod-2) % mod;
	}
	return fac;
}

// Lower bound function
int lowerBound(int *vs, int v) {
	// Calculate the index of the first element in vs that is greater than or equal to v
	int n = 0;
	int m = facNum-1;
	while (m!= n) {
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
	int *r = (int *)malloc(n*sizeof(int));
	for (int i = 0; i < n; i++) {
		r[i] = init;
	}
	return r;
}

// 