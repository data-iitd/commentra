
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>
#include <cstdio>

using namespace std;

//=====I/O=====

#define MOD 1000000007

int64_t scanInt() {
	int64_t a;
	scanf("%ld", &a);
	return a;
}

int64_t scanInt64() {
	int64_t a;
	scanf("%ld", &a);
	return a;
}

vector<int64_t> scanInts(int n) {
	vector<int64_t> res(n);
	for (int i = 0; i < n; i++) { res[i] = scanInt(); }
	return res;
}

string scanText() {
	string a;
	cin >> a;
	return a;
}

void printInts(vector<int64_t> a) {
	for (int i = 0; i < a.size(); i++) {
		printf("%ld", a[i]);
		if (i!= a.size() - 1) { printf(" "); }
	}
	printf("\n");
}

//=====main=====

int main() {
	int n = scanInt();

	vector<int64_t> c = scanInts(n);

	int64_t ans = 0;
	sort(c.begin(), c.end());

	for (int i = 0; i < n; i++) {
		ans = (ans + (n + 1 - i) * c[i] % MOD) % MOD;
	}

	printf("%ld\n", ans * modpow(4, n - 1) % MOD);
}

int64_t modpow(int64_t a, int64_t n) {
	int64_t res = 1;
	for (int64_t i = 1; i <= n; i *= 2) {
		if (n & i) {
			res = res * a % MOD;
		}
		a = a * a % MOD;
	}
	return res;
}

