
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> as(n);
	map<int, int> ps;
	for (int i = 0; i < n; i++) {
		cin >> as[i];

		map<int, int> ns = primeFactorize(as[i]);
		for (auto k : ns) {
			ps[k.first] = max(ps[k.first], k.second);
		}
	}

	int x = 1;
	for (auto k : ps) {
		for (int i = 1; i <= k.second; i++) {
			x = mul(x, k.first);
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans = add(ans, div(x, as[i]));
	}
	cout << ans << endl;
}

int max(int a, int b) {
	if (a > b) {
		return a;
	}
	return b;
}

map<int, int> primeFactorize(int n) {
	map<int, int> res;
	for (int i = 2; i*i <= n; i++) {
		for (; n % i == 0; n /= i) {
			res[i]++;
		}
	}
	if (n != 1) {
		res[n]++;
	}
	return res;
}

const int mod = 1000000007;

int pow(int n, int k) {
	if (k == 0) {
		return 1;
	} else if (k % 2 == 1) {
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

