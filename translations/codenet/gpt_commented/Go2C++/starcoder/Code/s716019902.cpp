#include <bits/stdc++.h>

using namespace std;

// Define constants for modulo operation and factorial limit
const int mod = 998244353;
const int facNum = 300001;

int main() {
	// Initialize a new scanner for reading input
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	int sum = 0;
	
	// Calculate the sum of all integers from 1 to N that are not divisible by 3 or 5
	for (int i = 1; i <= N; i++) {
		if (i % 3 == 0 || i % 5 == 0) {
			continue; // Skip numbers divisible by 3 or 5
		}
		sum += i; // Add the number to the sum
	}
	
	// Output the final sum
	cout << sum << endl;
}

// scanner struct for handling input
struct scanner {
	int b;
	int i;
	int n;
	char s[1000000];
	scanner() {
		scanf("%d", &n);
		scanf("%s", s);
		i = 0;
		b = 0;
	}
	int i() {
		int x;
		scanf("%d", &x);
		return x;
	}
	int f() {
		double x;
		scanf("%lf", &x);
		return x;
	}
	char* bs() {
		scanf("%s", s);
		return s;
	}
	int is(int& x) {
		scanf("%d", &x);
		return x;
	}
	int fs(float& x) {
		scanf("%lf", &x);
		return x;
	}
};

// Pow calculates a^n under modulo
int Pow(int a, int n) {
	int ans = 1;
	while (n > 0) {
		if (n & 1) {
			ans = ans * a % mod; // Multiply by a if n is odd
		}
		a = a * a % mod; // Square a
		n = n >> 1; // Right shift n
	}
	return ans; // Return the result
}

// Gcd calculates the greatest common divisor of a and b
int Gcd(int a, int b) {
	if (a < b) {
		return Gcd(b, a); // Ensure a is greater than b
	}
	while (b!= 0) {
		a = b;
		b = a % b; // Apply Euclidean algorithm
	}
	return a; // Return the GCD
}

// min returns the minimum of two integers
int min(int a, int b) {
	if (a < b) {
		return a; // Return a if it's smaller
	}
	return b; // Otherwise return b
}

// combination calculates n choose k using precomputed factorials
int combination(int n, int k, int* fac, int* ifac) {
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

// factorial precomputes factorials and their modular inverses
int* factorial() {
	int* fac = new int[facNum]; // Create a slice for factorials
	fac[0] = 1;
	int* ifac = new int[facNum]; // Create a slice for inverse factorials
	ifac[0] = 1;
	for (int i = 1; i < facNum; i++) {
		fac[i] = fac[i-1] * i % mod; // Compute factorial
		ifac[i] = ifac[i-1] * pow(i, mod-2) % mod; // Compute inverse factorial using Fermat's little theorem
	}
	return fac;
}

// lowerBound finds the index of the first element in a sorted slice that is not less than v
int lowerBound(int* vs, int v, int n) {
	int m = n; // Length of the slice
	int n2 = n / 2; // Initialize mid index
	while (m!= n2) {
		if (vs[n2] < v) {
			n2 = (m-n2+1)/2 + n2; // Move to the right half
		} else {
			m = n2; // Move to the left half
			n2 = n2 / 2; // Update mid index
		}
	}
	return n2; // Return the found index
}

// IntSlice creates a slice of integers initialized to a specific value
int* IntSlice(int n, int init) {
	int* r = new int[n]; // Create a slice of length n
	for (int i = 0; i < n; i++) {
		r[i] = init; // Initialize each element
	}
	return r; // Return the initialized slice
}

