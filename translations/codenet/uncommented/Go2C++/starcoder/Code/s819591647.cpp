//problem_b.cpp

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cctype>
#include <climits>
#include <bitset>

using namespace std;

// -----------------------------------------

int getInt() {
	int i;
	cin >> i;
	return i;
}

int getIntSlice(int n) {
	int *ns = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> ns[i];
	}
	return ns;
}

int getIntDoubleSlice(int m, int n) {
	int **nds = new int*[m];
	for (int i = 0; i < m; i++) {
		nds[i] = getIntSlice(n);
	}
	return nds;
}

string getString() {
	string s;
	cin >> s;
	return s;
}

string getStringSlice(int n) {
	string *ss = new string[n];
	for (int i = 0; i < n; i++) {
		cin >> ss[i];
	}
	return ss;
}

string getDoubleStringSlice(int m, int n) {
	string **sds = new string*[m];
	for (int i = 0; i < m; i++) {
		sds[i] = getStringSlice(n);
	}
	return sds;
}

// -----------------------------------------

// Sort Fanction

int sortIntSlice(int *ns, int n) {
	sort(ns, ns + n);
	return ns;
}

int sortIntReverseSlice(int *ns, int n) {
	sort(ns, ns + n, greater<int>());
	return ns;
}

// -----------------------------------------

// Num Fanction

//numAbs(x) = abs(s)
int numAbs(int x) {
	if (x < 0) {
		return -x;
	}

	return x;
}

//numModPow(a, n, m) = a^n % m
int numModPow(int a, int n, int m) {
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
int numGcd(int a, int b) {
	if (b == 0) {
		return a;
	}

	return numGcd(b, a % b);
}

// numLcm(a, b) = lcm(a, b)
int numLcm(int a, int b) {
	return a * b / numGcd(a, b);
}

// numModInv(a, p) = a^(-1) % p
int numModInv(int a, int p) {
	if (a == 1) {
		return 1;
	}

	return p - numModInv(p % a, p) * (p / a) % p;
}

// numModFrac(n) = n! % constMod
int *numModFrac(int n) {
	int *frac = new int[n + 1];
	frac[0] = 1;

	for (int i = 1; i <= n; i++) {
		frac[i] = i * frac[i - 1] % constMod;
	}

	return frac;
}

// numModConb(n, r) = nCr % constMod
int numModConb(int n, int r) {
	int *frac = numModFrac(n);

	return (frac[n] / ((frac[n - r] * frac[r]) % constMod)) % constMod;
}

// -----------------------------------------

int main() {
	int n, m;
	cin >> n >> m;
	int *a = getIntSlice(n);

	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += a[i];
	}

	int count = 0;
	for (int i = 0; i < n; i++) {
		double rate = (double)sum / (4 * m);
		if (a[i] >= rate) {
			count++;
		}
	}

	if (count >= m) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}

	return 0;
}

// 