#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

typedef long long ll;
typedef vector<ll> vll;
typedef set<ll> sll;

map<ll, ll> getPrimeFactor(ll n) {
	map<ll, ll> res;
	for (ll i = 2; i * i <= n; ++i) {
		while (n % i == 0) {
			res[i] ++;
			n /= i;
		}
	}
	if (n != 1) res[n] = 1;
	return res;
}

bool IsPrimeNumber(ll num)
{
	if (num <= 2) return true;
	else if (num % 2 == 0) return false;

	double sqrtNum = sqrt(num);
	for (int i = 3; i <= sqrtNum; i += 2)
	{
		if (num % i == 0)
		{
			return false;
		}
	}

	return true;
}

long long modinv(long long a, long long m) {
	long long b = m, u = 1, v = 0;
	while (b) {
		long long t = a / b;
		a -= t * b; swap(a, b);
		u -= t * v; swap(u, v);
	}
	u %= m;
	if (u < 0) u += m;
	return u;
}

#define rep(i,s,e) for(ll i=s;i<e;i++)
#define repeq(i,s,e) for(ll i=s;i<=e;i++)



int main() {
	ll N, K;
	scanf("%lld %lld", &N, &K);

	vll A(N + 1);
	repeq(i, 1, N) {
		scanf("%lld", &A[i]);
	}

	ll cur = 1;
	vll dic(N + 1, -1);
	bool flg = false;
	repeq(i, 1, K) {
		if (dic[cur] < 0 || flg) {
			dic[cur] = i;
			cur = A[cur];
		}
		else if(!flg) {
			ll tmp = K - (dic[cur] - 1);
			tmp %= i - dic[cur];
			i = K - tmp ;
			flg = true;
		}
	}

	printf("%lld\n", cur);
	return 0;
}

