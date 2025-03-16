#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define mod 1000000007

int max(int a, int b) {
	if (a > b) {
		return a;
	}
	return b;
}

int pow(int n, int k) {
	if (k == 0) {
		return 1;
	} else if (k % 2 == 1) {
		return pow(n, k - 1) * n % mod;
	} else {
		int t = pow(n, k / 2);
		return t * t % mod;
	}
}

int add(int a, int b) {
	return (a + b) % mod;
}

int sub(int a, int b) {
	return (a + mod - b) % mod;
}

int mul(int a, int b) {
	return a % mod * b % mod % mod;
}

int div(int a, int b) {
	return mul(a, pow(b, mod - 2));
}

int main() {
	// Read the number of elements
	int n;
	scanf("%d", &n);

	// Initialize a slice to store the input numbers and a map to store the maximum prime factors
	int *as = (int *)malloc(n * sizeof(int));
	int *ps = (int *)malloc(n * sizeof(int));

	// Read each number and perform prime factorization
	for (int i = 0; i < n; i++) {
		scanf("%d", &as[i]);

		// Get the prime factors of the current number
		int *ns = primeFactorize(as[i]);
		// Update the maximum count of each prime factor found
		for (int k = 0; k < n; k++) {
			ps[k] = max(ps[k], ns[k]);
		}
	}

	// Calculate the product of the maximum prime factors raised to their respective powers
	int x = 1;
	for (int k = 0; k < n; k++) {
		for (int i = 1; i <= ps[k]; i++) {
			x = mul(x, k);
		}
	}

	// Calculate the final answer by summing the results of x divided by each input number
	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans = add(ans, div(x, as[i]));
	}

	// Print the final answer
	printf("%d\n", ans);

	// Free the memory allocated for the slices
	free(as);
	free(ps);

	return 0;
}

int *primeFactorize(int n) {
	int *res = (int *)malloc(n * sizeof(int));
	// Check for factors from 2 up to the square root of n
	for (int i = 2; i * i <= n; i++) {
		// While i is a factor of n, divide n by i and count the occurrences
		for (; n % i == 0; n /= i) {
			res[i]++;
		}
	}
	// If n is still greater than 1, it is a prime factor itself
	if (n != 1) {
		res[n]++;
	}
	return res;
}

