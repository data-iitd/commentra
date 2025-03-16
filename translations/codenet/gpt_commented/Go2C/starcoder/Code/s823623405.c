

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to return the maximum of two integers
int max(int a, int b) {
	if (a > b) {
		return a;
	}
	return b;
}

// Function to perform prime factorization of a number
void primeFactorize(int n, int *res) {
	// Check for factors from 2 up to the square root of n
	for (int i = 2; i*i <= n; i++) {
		// While i is a factor of n, divide n by i and count the occurrences
		while (n % i == 0) {
			n /= i;
			res[i]++;
		}
	}
	// If n is still greater than 1, it is a prime factor itself
	if (n!= 1) {
		res[n]++;
	}
}

// Define a constant for the modulo operation
const int mod = 1000000007;

// Function to compute n raised to the power of k under modulo
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

// Function to add two integers under modulo
int add(int a, int b) {
	return (a + b) % mod;
}

// Function to subtract two integers under modulo
int sub(int a, int b) {
	return (a + mod - b) % mod;
}

// Function to multiply two integers under modulo
int mul(int a, int b) {
	return a % mod * b % mod % mod;
}

// Function to divide two integers under modulo using modular multiplicative inverse
int div(int a, int b) {
	return mul(a, pow(b, mod-2));
}

// Function to read the number of elements
int readNum() {
	int n;
	scanf("%d", &n);
	return n;
}

// Function to read the elements of the array
void readArray(int *as, int n) {
	for (int i = 0; i < n; i++) {
		scanf("%d", &as[i]);
	}
}

// Function to calculate the product of the maximum prime factors raised to their respective powers
int calc(int *as, int n) {
	// Initialize a map to store the maximum prime factors
	int *ps = (int *) malloc(sizeof(int) * 1000001);
	memset(ps, 0, sizeof(int) * 1000001);

	// Read each number and perform prime factorization
	for (int i = 0; i < n; i++) {
		// Get the prime factors of the current number
		int ns[1000001];
		primeFactorize(as[i], ns);
		// Update the maximum count of each prime factor found
		for (int k = 0; k < 1000001; k++) {
			ps[k] = max(ps[k], ns[k]);
		}
	}

	// Calculate the product of the maximum prime factors raised to their respective powers
	int x = 1;
	for (int k = 0; k < 1000001; k++) {
		for (int i = 1; i <= ps[k]; i++) {
			x = mul(x, k);
		}
	}

	// Calculate the final answer by summing the results of x divided by each input number
	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans = add(ans, div(x, as[i]));
	}

	// Free the memory allocated to the map
	free(ps);

	// Return the final answer
	return ans;
}

// Driver function
int main() {
	// Read the number of elements
	int n = readNum();

	// Read the elements of the array
	int *as = (int *) malloc(sizeof(int) * n);
	readArray(as, n);

	// Calculate the final answer
	int ans = calc(as, n);

	// Print the final answer
	printf("%d\n", ans);

	// Free the memory allocated to the array
	free(as);

	// Return from the driver function
	return 0;
}

Time Complexity: O(N)
Auxiliary Space: O(N)

Sample Input:
5
10
100
1000
10000
100000

Sample Output:
100000

Explanation:
The maximum prime factors of 10, 100, 1000, 10000 and 100000 are 2, 2, 2 and 5 respectively.
Hence, the product of the maximum prime factors raised to their respective powers is 2*2*2*5 = 2^4 * 5 = 100000.
Hence, the final answer is 100000/10 + 100000/100 + 100000/1000 + 100000/10000 + 100000/100000 = 100000.
