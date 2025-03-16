
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <cstring>
#include <cstdio>

using namespace std;

// Define a constant for modulus operation
const int constMod = 1e9 + 7;

// Sort Functions

// sortIntSlice sorts a slice of integers in ascending order
vector<int> sortIntSlice(vector<int> ns) {
	sort(ns.begin(), ns.end());
	return ns;
}

// sortIntReverseSlice sorts a slice of integers in descending order
vector<int> sortIntReverseSlice(vector<int> ns) {
	sort(ns.begin(), ns.end(), greater<int>());
	return ns;
}

// Number Functions

// numAbs returns the absolute value of an integer x
int numAbs(int x) {
	if (x < 0) {
		return -x;
	}
	return x;
}

// numModPow computes a^n % m using modular exponentiation
int numModPow(int a, int n, int m) {
	int result = 1;

	for (; n > 0; n >>= 1) {
		if (n % 2 == 1) {
			result = (result * a) % m;
		}
		a = (a * a) % m;
	}

	return result;
}

// numGcd computes the greatest common divisor of a and b
int numGcd(int a, int b) {
	if (b == 0) {
		return a;
	}
	return numGcd(b, a % b);
}

// numLcm computes the least common multiple of a and b
int numLcm(int a, int b) {
	return a * b / numGcd(a, b);
}

// numModInv computes the modular inverse of a under modulo p
int numModInv(int a, int p) {
	if (a == 1) {
		return 1;
	}
	return p - numModInv(p % a, p) * (p / a) % p;
}

// numModFrac computes factorials modulo constMod up to n
vector<int> numModFrac(int n) {
	vector<int> frac;
	frac.push_back(1);

	for (int i = 1; i <= n; i++) {
		frac.push_back((i * frac[i - 1]) % constMod);
	}

	return frac;
}

// numModConb computes nCr % constMod using precomputed factorials
int numModConb(int n, int r) {
	vector<int> frac = numModFrac(n);
	return (frac[n] / ((frac[n - r] * frac[r]) % constMod)) % constMod;
}

// -----------------------------------------

// solve function implements the main logic of the problem
void solve() {
	// Read n and m from input
	int n, m;
	cin >> n >> m;
	// Read n integers into slice a
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	// Calculate the sum of all elements in a
	int sum = 0;
	for (int v : a) {
		sum += v;
	}

	// Count how many elements in a meet the required rate
	int count = 0;
	for (int v : a) {
		double rate = (double)sum / (4 * m);
		if (v >= rate) {
			count++;
		}
	}

	// Output "Yes" if count is greater than or equal to m, otherwise "No"
	if (count >= m) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}
}

// -----------------------------------------

// main function initializes the program and calls solve
int main() {
	// Call the solve function to execute the main logic
	solve();
	// Flush the writer to output results
	return 0;
}

