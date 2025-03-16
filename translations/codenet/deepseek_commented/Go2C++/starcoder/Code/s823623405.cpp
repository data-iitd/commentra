#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n; // Read the number of elements
	vector<int> as(n);
	map<int, int> ps;
	for (int i = 0; i < n; i++) {
		cin >> as[i]; // Read each element of the array

		map<int, int> ns = primeFactorize(as[i]); // Prime factorize the current element
		for (auto k : ns) {
			ps[k.first] = max(ps[k.first], k.second); // Update the map with the prime factors and their powers
		}
	}

	int x = 1;
	for (auto k : ps) {
		for (int i = 1; i <= k.second; i++) {
			x = mul(x, k.first); // Calculate the LCM by multiplying the prime factors with their powers
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans = add(ans, div(x, as[i])); // Calculate the sum of modular inverses
	}
	cout << ans << endl; // Print the final answer
}

int max(int a, int b) {
	return a > b? a : b;
}

map<int, int> primeFactorize(int n) {
	map<int, int> res;
	for (int i = 2; i*i <= n; i++) {
		while (n%i == 0) {
			n /= i;
			res[i]++;
		}
	}
	if (n!= 1) {
		res[n]++;
	}
	return res;
}

const int mod = 1000000007;

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

