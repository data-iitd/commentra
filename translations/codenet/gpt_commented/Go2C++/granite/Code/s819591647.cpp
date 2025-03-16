
// problem_b.cpp

#include <bits/stdc++.h>

using namespace std;

// Define a constant for modulus operation
const int constMod = 1e9 + 7;

// Initialize scanner and writer for input and output
#define sc cin
#define wr cout

// -----------------------------------------

// getInt reads a single integer from input
int getInt() {
	int i;
	sc >> i;
	return i;
}

// getIntSlice reads n integers from input and returns them as a vector
vector<int> getIntSlice(int n) {
	vector<int> ns;
	for (int i = 0; i < n; i++) {
		ns.push_back(getInt());
	}
	return ns;
}

// getIntDoubleSlice reads m slices of n integers from input and returns them as a 2D vector
vector<vector<int>> getIntDoubleSlice(int m, int n) {
	vector<vector<int>> nds;
	for (int i = 0; i < m; i++) {
		vector<int> ns = getIntSlice(n);
		nds.push_back(ns);
	}

	return nds;
}

// getString reads a single string from input
string getString() {
	string s;
	sc >> s;
	return s;
}

// getStringSlice reads n strings from input and returns them as a vector
vector<string> getStringSlice(int n) {
	vector<string> ss;
	for (int i = 0; i < n; i++) {
		ss.push_back(getString());
	}
	return ss;
}

// getStringDoubleSlice reads m slices of n strings from input and returns them as a 2D vector
vector<vector<string>> getStringDoubleSlice(int m, int n) {
	vector<vector<string>> sds;
	for (int i = 0; i < m; i++) {
		vector<string> ss = getStringSlice(n);
		sds.push_back(ss);
	}

	return sds;
}

// -----------------------------------------

// Sort Functions

// sortIntSlice sorts a vector of integers in ascending order
vector<int> sortIntSlice(vector<int> ns) {
	sort(ns.begin(), ns.end());
	return ns;
}

// sortIntReverseSlice sorts a vector of integers in descending order
vector<int> sortIntReverseSlice(vector<int> ns) {
	sort(ns.rbegin(), ns.rend());
	return ns;
}

// -----------------------------------------

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

	for (int i = 0; i < n; i++) {
		if (n % 2 == 1) {
			result = (result * a) % m;
		}
		a = (a * a) % m;
		n >>= 1;
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
	vector<int> frac(n + 1);
	frac[0] = 1;

	for (int i = 1; i <= n; i++) {
		frac[i] = i * frac[i - 1] % constMod;
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
	// Read n integers into vector a
	vector<int> a = getIntSlice(n);

	// Calculate the sum of all elements in a
	int sum = 0;
	for (int v : a) {
		sum += v;
	}

	// Count how many elements in a meet the required rate
	int count = 0;
	for (int v : a) {
		double rate = double(sum) / double(4 * m);
		if (double(v) >= rate) {
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
	return 0;
}

