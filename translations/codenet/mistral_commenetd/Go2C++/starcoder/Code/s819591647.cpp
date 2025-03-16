//problem_b.cpp
// This is the main file for problem B solution

#include <bits/stdc++.h>

using namespace std;

const int constMod = int(1e9) + 7; // Constants definition

// -----------------------------------------

// Function definitions

int getInt() { // Function to read an integer from standard input
	int i;
	cin >> i;
	return i;
}

vector<int> getIntSlice(int n) { // Function to read n integers and return a vector
	vector<int> ns;
	for (int i = 0; i < n; i++) {
		ns.push_back(getInt());
	}
	return ns;
}

string getString() { // Function to read a string from standard input
	string s;
	cin >> s;
	return s;
}

vector<string> getStringSlice(int n) { // Function to read n strings and return a vector
	vector<string> ss;
	for (int i = 0; i < n; i++) {
		ss.push_back(getString());
	}
	return ss;
}

vector<vector<string>> getStringDoubleSlice(int m, int n) { // Function to read m strings of length n and return a 2D vector
	vector<vector<string>> sds;
	for (int i = 0; i < m; i++) {
		sds.push_back(getStringSlice(n));
	}

	return sds;

}

// -----------------------------------------

// Sorting functions

vector<int> sortIntSlice(vector<int> ns) { // Function to sort an integer vector in ascending order
	sort(ns.begin(), ns.end());
	return ns;
}

vector<int> sortIntReverseSlice(vector<int> ns) { // Function to sort an integer vector in descending order
	sort(ns.begin(), ns.end(), greater<int>());
	return ns;
}

// -----------------------------------------

// Mathematical functions

//numAbs(x) = abs(s)
int numAbs(int x) { // Function to get absolute value of an integer
	if (x < 0) {
		return -x;
	}

	return x;
}

//numModPow(a, n, m) = a^n % m
int numModPow(int a, int n, int m) { // Function to calculate a^n % m
	int result = 1;

	for (int i = 0; i < n; i++) {
		if (n & 1) {
			result = (result * a) % m;
		}

		a = (a * a) % m;
		n >>= 1;
	}

	return result;
}

// numGcd(a, b) = gcd(a, b)
int numGcd(int a, int b) { // Function to calculate the greatest common divisor of a and b
	if (b == 0) {
		return a;
	}

	return numGcd(b, a % b);
}

// numLcm(a, b) = lcm(a, b)
int numLcm(int a, int b) { // Function to calculate the least common multiple of a and b
	return a * b / numGcd(a, b);
}

// numModInv(a, p) = a^(-1) % p
int numModInv(int a, int p) { // Function to calculate the modular inverse of a modulo p
	if (a == 1) {
		return 1;
	}

	return p - numModInv(p % a, p) * (p / a) % p;
}

// numModFrac(n) = n! % constMod
vector<int> numModFrac(int n) { // Function to calculate n! modulo constMod
	vector<int> frac = {1};

	for (int i = 1; i <= n; i++) {
		frac.push_back(i * frac[i-1] % constMod);
	}

	return frac;
}

// numModConb(n, r) = nCr % constMod
int numModConb(int n, int r) { // Function to calculate nCr modulo constMod
	vector<int> frac = numModFrac(n);

	return (frac[n] / ((frac[n-r] * frac[r]) % constMod)) % constMod;
}

// -----------------------------------------

// Main function

void solve() { // Function to solve the problem

	int n, m;
	cin >> n >> m;
	vector<int> a = getIntSlice(n);

	int sum = 0;
	for (int v : a) {
		sum += v;
	}

	int count = 0;
	for (int v : a) {
		double rate = double(sum) / double(4*m);
		if (double(v) >= rate) {
			count++;
		}
	}

	if (count >= m) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}

}

// -----------------------------------------

int main() { // Main function
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	solve();
	return 0;
}

// 