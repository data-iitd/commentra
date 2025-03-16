
#include <bits/stdc++.h>

using namespace std;

int main() {
	// Initialize variables
	int n;
	cin >> n; // Read the number of integers from the standard input
	vector<int> as(n); // Create an array of size n to store the input integers
	map<int, int> ps; // Create a map to store the prime factors and their powers

	// Read the input integers and calculate their prime factors
	for (int i = 0; i < n; i++) {
		cin >> as[i]; // Read an integer from the standard input

		map<int, int> ns = primeFactorize(as[i]); // Calculate the prime factors and their powers of the current integer
		for (auto k = ns.begin(); k!= ns.end(); k++) { // Iterate through the map to update the powers of the prime factors
			ps[k->first] = max(ps[k->first], k->second); // Update the power of the current prime factor if it's greater
		}
	}

	// Calculate the answer
	int x = 1; // Initialize a variable to store the product of prime factors
	for (auto k = ps.begin(); k!= ps.end(); k++) { // Iterate through the map to calculate the product of prime factors
		for (int i = 1; i <= k->second; i++) { // Calculate the power of the prime factor
			x = mul(x, k->first); // Multiply the current product with the prime factor
		}
	}

	int ans = 0; // Initialize a variable to store the answer
	for (int i = 0; i < n; i++) { // Iterate through the array to calculate the answer
		ans = add(ans, div(x, as[i])); // Calculate the difference between the current product and the current integer, and add it to the answer
	}

	cout << ans << endl; // Print the answer
}

int max(int a, int b) {
	// Return the maximum of two integers
	return a > b? a : b;
}

map<int, int> primeFactorize(int n) {
	// Calculate the prime factors and their powers of a given integer
	map<int, int> res;
	for (int i = 2; i*i <= n; i++) { // Iterate through the possible prime factors
		while (n%i == 0) { // If the current number is divisible by the current prime factor
			n /= i; // Divide the current number by the prime factor
			res[i]++; // Increment the power of the prime factor
		}
	}
	if (n!= 1) { // If the number is not equal to 1, it means that it has a prime factor greater than 1
		res[n]++; // Increment the power of the last prime factor
	}
	return res;
}

const int mod = 1000000007;

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

