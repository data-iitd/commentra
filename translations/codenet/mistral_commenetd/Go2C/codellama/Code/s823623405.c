
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define mod 1000000007

int max(int a, int b) {
	// Return the maximum of two integers
	if (a > b) {
		return a;
	}
	return b;
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
	int n;
	scanf("%d", &n); // Read the number of integers from the standard input
	int *as = (int *)malloc(n * sizeof(int)); // Create an array of size n to store the input integers
	int **ps = (int **)malloc(n * sizeof(int *)); // Create an array of size n to store the prime factors and their powers

	// Read the input integers and calculate their prime factors
	for (int i = 0; i < n; i++) {
		scanf("%d", &as[i]); // Read an integer from the standard input

		int **ns = primeFactorize(as[i]); // Calculate the prime factors and their powers of the current integer
		for (int k = 0; k < n; k++) { // Iterate through the array to update the powers of the prime factors
			ps[k][k] = max(ps[k][k], ns[k][k]); // Update the power of the current prime factor if it's greater
		}
	}

	// Calculate the answer
	int x = 1; // Initialize a variable to store the product of prime factors
	for (int k = 0; k < n; k++) { // Iterate through the array to calculate the product of prime factors
		for (int i = 1; i <= ps[k][k]; i++) { // Calculate the power of the prime factor
			x = mul(x, ps[k][k]); // Multiply the current product with the prime factor
		}
	}

	int ans = 0; // Initialize a variable to store the answer
	for (int i = 0; i < n; i++) { // Iterate through the array to calculate the answer
		ans = add(ans, div(x, as[i])); // Calculate the difference between the current product and the current integer, and add it to the answer
	}

	printf("%d\n", ans); // Print the answer

	return 0;
}

int **primeFactorize(int n) {
	// Calculate the prime factors and their powers of a given integer
	int **res = (int **)malloc(n * sizeof(int *));
	for (int i = 2; i*i <= n; i++) { // Iterate through the possible prime factors
		for (; n%i == 0; n /= i) { // If the current number is divisible by the current prime factor
			res[i] = (int *)malloc(sizeof(int)); // Create a new array to store the power of the prime factor
			res[i][0]++; // Increment the power of the prime factor
		}
	}
	if (n != 1) { // If the number is not equal to 1, it means that it has a prime factor greater than 1
		res[n] = (int *)malloc(sizeof(int)); // Create a new array to store the power of the last prime factor
		res[n][0]++; // Increment the power of the last prime factor
	}
	return res;
}

