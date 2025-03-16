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
	} else if (k%2 == 1) {
		return pow(n, k-1) * n % mod;
	} else {
		int t = pow(n, k/2);
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
	return mul(a, pow(b, mod-2));
}

int main() {
	int n;
	scanf("%d", &n); // Read the number of elements
	int *as = (int *)malloc(n * sizeof(int));
	int *ps = (int *)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++) {
		scanf("%d", &as[i]); // Read each element of the array

		int *ns = primeFactorize(as[i]); // Prime factorize the current element
		for (int k = 0; k < n; k++) {
			ps[k] = max(ps[k], ns[k]); // Update the map with the prime factors and their powers
		}
	}

	int x = 1;
	for (int k = 0; k < n; k++) {
		for (int i = 1; i <= ps[k]; i++) {
			x = mul(x, k); // Calculate the LCM by multiplying the prime factors with their powers
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans = add(ans, div(x, as[i])); // Calculate the sum of modular inverses
	}
	printf("%d\n", ans); // Print the final answer

	return 0;
}

int *primeFactorize(int n) {
	int *res = (int *)malloc(n * sizeof(int));
	for (int i = 2; i*i <= n; i++) {
		for (; n%i == 0; n /= i) {
			res[i]++;
		}
	}
	if (n != 1) {
		res[n]++;
	}
	return res;
}

