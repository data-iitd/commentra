
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

const int mod = 1000000007;

int pow(int n, int k) {
	if (k == 0) return 1;
	else if (k % 2 == 1) return pow(n, k - 1) * n % mod;
	else {
		int t = pow(n, k / 2);
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
	return mul(a, pow(b, mod - 2));
}

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];

	map<int, int> ps;
	for (int i = 0; i < n; i++) {
		int x = a[i];
		for (int j = 2; j * j <= x; j++) {
			while (x % j == 0) {
				ps[j] = max(ps[j], 1);
				x /= j;
			}
		}
		if (x!= 1) ps[x] = max(ps[x], 1);
	}

	int x = 1;
	for (auto p : ps) {
		for (int i = 0; i < p.second; i++) {
			x = mul(x, p.first);
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans = add(ans, div(x, a[i]));
	}
	cout << ans << endl;

	return 0;
}

