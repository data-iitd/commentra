
#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) {
	// Return the maximum of two integers
	if (a > b) {
		return a;
	}
	return b;
}

int primeFactorize(int n, int *res) {
	// Calculate the prime factors and their powers of a given integer
	int i, j;
	for (i = 2; i*i <= n; i++) { // Iterate through the possible prime factors
		for (j = 0; n%i == 0; n /= i, j++) { // If the current number is divisible by the current prime factor
			res[i]++; // Increment the power of the prime factor
		}
	}
	if (n!= 1) { // If the number is not equal to 1, it means that it has a prime factor greater than 1
		res[n]++; // Increment the power of the last prime factor
	}
	return n;
}

int pow(int n, int k) {
	// Calculate n raised to the power of k modulo mod
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
	// Return the sum of two integers modulo mod
	return (a + b) % mod;
}

int sub(int a, int b) {
	// Return the difference of two integers modulo mod
	return (a + mod - b) % mod;
}

int mul(int a, int b) {
	// Return the product of two integers modulo mod
	return a % mod * b % mod % mod;
}

int div(int a, int b) {
	// Return the quotient of a and b modulo mod
	return mul(a, pow(b, mod-2));
}

int main() {
	// Initialize variables
	int n, i, j, k, v;
	scanf("%d", &n); // Read the number of integers from the standard input
	int *as = (int *)malloc(n * sizeof(int)); // Create an array of size n to store the input integers
	int *ps = (int *)malloc(n * sizeof(int)); // Create an array of size n to store the prime factors and their powers
	for (i = 0; i < n; i++) {
		scanf("%d", &as[i]); // Read an integer from the standard input
		ps[i] = primeFactorize(as[i], ps + i); // Calculate the prime factors and their powers of the current integer
	}

	// Calculate the answer
	int x = 1; // Initialize a variable to store the product of prime factors
	for (i = 0; i < n; i++) { // Iterate through the array to calculate the product of prime factors
		for (j = 0; j < ps[i]; j++) { // Calculate the power of the prime factor
			x = mul(x, as[i]); // Multiply the current product with the prime factor
		}
	}

	int ans = 0; // Initialize a variable to store the answer
	for (i = 0; i < n; i++) { // Iterate through the array to calculate the answer
		ans = add(ans, div(x, as[i])); // Calculate the difference between the current product and the current integer, and add it to the answer
	}

	printf("%d\n", ans); // Print the answer
	return 0;
}

