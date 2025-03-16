#include <bits/stdc++.h>

using namespace std;

int main() {
	// Initialize constants and vectors
	const int MX = 10000;
	vector<int> sieve(MX, 0);
	vector<int> primes;

	// Use the Sieve of Eratosthenes to find all primes up to MX
	for (int i = 2; i < MX; i++) {
		if (sieve[i]!= 0) {
			continue; // Skip if i is not a prime
		}
		primes.push_back(i); // i is a prime, add it to the primes list
		for (int j = i + i; j < MX; j += i) {
			sieve[j] = i; // Mark j as not prime
		}
	}

	// Read the number of integers to process
	int n;
	cin >> n;
	int ans = 0;

	// Process each integer and update the answer
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		ans++; // Assume the number is valid
		for (int j = 0; j < primes.size(); j++) {
			if (x > primes[j] && x % primes[j] == 0) {
				ans--; // The number is not valid
				break;
			}
		}
	}

	// Output the result
	cout << ans << endl;
}

