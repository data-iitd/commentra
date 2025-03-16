
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Define constants for modulo operation and factorial limit
const int mod = 998244353;
const int facNum = 300001;

// Function to calculate a^n under modulo
int Pow(int a, int n) {
	int ans = 1;
	for (n > 0; n > 0; n = n >> 1) {
		if (n & 1) {
			ans = ans * a % mod; // Multiply by a if n is odd
		}
		a = a * a % mod; // Square a
	}
	return ans; // Return the result
}

// Function to calculate the greatest common divisor of a and b
int Gcd(int a, int b) {
	if (a < b) {
		return Gcd(b, a); // Ensure a is greater than b
	}
	for (b != 0; b != 0;) {
		a = b;
		b = a % b; // Apply Euclidean algorithm
	}
	return a; // Return the GCD
}

// Function to return the minimum of two integers
int min(int a, int b) {
	if (a < b) {
		return a; // Return a if it's smaller
	}
	return b; // Otherwise return b
}

// Function to calculate n choose k using precomputed factorials
int combination(int n, int k, int *fac, int *ifac) {
	if (n < k || n < 0) {
		return 0; // Return 0 if invalid
	}
	if (k == 0) {
		return 1; // Return 1 if k is 0
	}
	// Calculate combination using factorials
	int ans = ifac[k] * ifac[n-k] % mod;
	return ans * fac[n] % mod;
}

// Function to precompute factorials and their modular inverses
void factorial(int *fac, int *ifac) {
	fac[0] = 1;
	ifac[0] = 1;
	for (int i = 1; i < facNum; i++) {
		fac[i] = fac[i-1] * i % mod; // Compute factorial
		ifac[i] = ifac[i-1] * Pow(i, mod-2) % mod; // Compute inverse factorial using Fermat's little theorem
	}
}

// Function to find the index of the first element in a sorted slice that is not less than v
int lowerBound(int *vs, int v) {
	int n = facNum / 2; // Initialize mid index
	int m = facNum; // Length of the slice
	for (m != n; m != n;) {
		if (vs[n] < v) {
			n = (m-n+1)/2 + n; // Move to the right half
		} else {
			m = n; // Move to the left half
			n = n / 2; // Update mid index
		}
	}
	return n; // Return the found index
}

// Function to create a slice of integers initialized to a specific value
int *IntSlice(int n, int init) {
	int *r = malloc(n * sizeof(int)); // Create a slice of length n
	for (int i = 0; i < n; i++) {
		r[i] = init; // Initialize each element
	}
	return r; // Return the initialized slice
}

int main() {
	// Initialize factorials and their modular inverses
	int *fac = IntSlice(facNum, 1);
	int *ifac = IntSlice(facNum, 1);
	factorial(fac, ifac);
	
	// Read an integer N from input
	int N;
	scanf("%d", &N);
	int sum = 0;
	
	// Calculate the sum of all integers from 1 to N that are not divisible by 3 or 5
	for (int i = 1; i <= N; i++) {
		if (i%3 == 0 || i%5 == 0) {
			continue; // Skip numbers divisible by 3 or 5
		}
		sum += i; // Add the number to the sum
	}
	
	// Output the final sum
	printf("%d\n", sum);
	
	// Free allocated memory
	free(fac);
	free(ifac);
	
	return 0;
}

