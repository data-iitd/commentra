#include <iostream>
#include <math.h>
using namespace std;
typedef long long ll;

int n, a[50], p, b = 0, c = 0;

ll nPr(ll n, ll r) {
	ll res = 1;
	for (int i = 0; i < r; i++) {
		res *= (n - i);
	}

	return res;
}

ll nCr(ll n, ll r) {
	//ll res = nPr(n, r) / nPr(r, r);
	double res = 1;
	for (int i = 0; i < r; i++) {
		res *= (n - i);
		res /= (i+1);
	}
	return (ll)res;
}

int main() {
	cin >> n >> p;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] % 2 == 0) {
			b++;
		}
		else {
			c++;
		}
	}

	# 