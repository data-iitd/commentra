
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <assert.h>

typedef long long ll;

const ll mod = 1000000007;

ll modpow(ll a, ll n) {
	ll res = 1;
	while (n > 0) {
		if (n & 1) {
			res = res * a % mod;
		}
		a = a * a % mod;
		n >>= 1;
	}
	return res;
}

int main() {
	int n;
	scanf("%d", &n);

	int c[n];
	for (int i = 0; i < n; i++) {
		scanf("%d", &c[i]);
	}

	ll ans = 0;
	qsort(c, n, sizeof(int), cmpfunc);
	for (int i = 0; i < n; i++) {
		ans = (ans + (n + 1 - i) * c[i] % mod) % mod;
	}

	printf("%lld\n", ans * modpow(4, n - 1) % mod);

	return 0;
}

int cmpfunc(const void *a, const void *b) {
	return (*(int *)a - *(int *)b);
}

