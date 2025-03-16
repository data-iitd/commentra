#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define mod 998244353
#define facNum 300001

int Pow(int a, int n) {
	int ans = 1;
	while (n > 0) {
		if (n & 1) {
			ans = ans * a % mod;
		}
		a = a * a % mod;
		n = n >> 1;
	}
	return ans;
}

int Gcd(int a, int b) {
	if (a < b) {
		return Gcd(b, a);
	}
	while (b != 0) {
		a = a % b;
		a = b;
		b = a % b;
	}
	return a;
}

int min(int a, int b) {
	if (a < b) {
		return a;
	}
	return b;
}

int combination(int n, int k, int *fac, int *ifac) {
	if (n < k || n < 0) {
		return 0;
	}
	if (k == 0) {
		return 1;
	}
	//while n != 0
	int ans = ifac[k] * ifac[n-k] % mod;
	return ans * fac[n] % mod;
}

int *factorial() {
	int *fac = (int *)malloc(sizeof(int) * facNum);
	int *ifac = (int *)malloc(sizeof(int) * facNum);
	fac[0] = 1;
	ifac[0] = 1;
	for (int i = 1; i < facNum; i++) {
		fac[i] = fac[i-1] * i % mod;
		ifac[i] = ifac[i-1] * Pow(i, mod-2) % mod;
	}
	return fac;
}

int lowerBound(int *vs, int v) {
	int n = facNum / 2;
	int m = facNum;
	while (m != n) {
		if (vs[n] < v) {
			n = (m-n+1)/2 + n;
			//m = m
		} else {
			m = n;
			n = n / 2;
		}
	}
	return n;
}

int *IntSlice(int n, int init) {
	int *r = (int *)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		r[i] = init;
	}
	return r;
}

int main() {
	int *fac = factorial();
	int *ifac = IntSlice(facNum, 1);
	int N;
	scanf("%d", &N);
	int sum = 0;
	for (int i = 1; i <= N; i++) {
		if (i%3 == 0 || i%5 == 0) {
			continue;
		}
		sum += i;
	}
	printf("%d\n", sum);
	return 0;
}

