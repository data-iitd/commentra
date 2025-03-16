#include <bits/stdc++.h>

using namespace std;

// Function to return the maximum of two integers
int max(int a, int b) {
	return a > b? a : b;
}

// Function to perform prime factorization of a number
map<int, int> primeFactorize(int n) {
	map<int, int> res;
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
	return res;
}

// Define a constant for the modulo operation
const int mod = 1000000007;

// Function to compute n raised to the power of k under modulo
int pow(int n, int k) {
	if (k == 0) {
		return 1;
	} else if (k % 2 == 1) {
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

int main() {
	// Read the number of elements
	int n;
	cin >> n;

	// Initialize a vector to store the input numbers and a map to store the maximum prime factors
	vector<int> as(n);
	map<int, int> ps;

	// Read each number and perform prime factorization
	for (int i = 0; i < n; i++) {
		cin >> as[i];

		// Get the prime factors of the current number
		map<int, int> ns = primeFactorize(as[i]);
		// Update the maximum count of each prime factor found
		for (auto k : ns) {
			ps[k.first] = max(ps[k.first], k.second);
		}
	}

	// Calculate the product of the maximum prime factors raised to their respective powers
	int x = 1;
	for (auto k : ps) {
		for (int i = 1; i <= k.second; i++) {
			x = mul(x, k.first);
		}
	}

	// Calculate the final answer by summing the results of x divided by each input number
	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans = add(ans, div(x, as[i]));
	}

	// Print the final answer
	cout << ans << endl;
}

