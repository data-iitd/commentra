#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define mod 1000000007

int max(int a, int b) {
	if (a > b) {
		return a;
	}
	return b;
}

int primeFactorize(int n, int *ps) {
	int res = 0;
	for (int i = 2; i*i <= n; i++) {
		while (n%i == 0) {
			n /= i;
			ps[res++] = i;
		}
	}
	if (n!= 1) {
		ps[res++] = n;
	}
	return res;
}

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

int main() {
	int n;
	scanf("%d", &n);
	int *as = (int *)malloc(sizeof(int) * n);
	int *ps = (int *)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &as[i]);
		int ns[n];
		int m = primeFactorize(as[i], ns);
		for (int j = 0; j < m; j++) {
			ps[ns[j]] = max(ps[ns[j]], 1);
		}
	}

	int x = 1;
	for (int i = 0; i < n; i++) {
		x = mul(x, ps[i]);
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans = add(ans, div(x, as[i]));
	}
	printf("%d\n", ans);
	return 0;
}

