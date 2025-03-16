#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// Function to calculate the greatest common divisor (GCD)
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }

// Function to calculate the least common multiple (LCM)
long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }

// Function to get the prime factors of a number
map<long long, long long> getPrimeFactor(long long n) {
	map<long long, long long> res;
	for (long long i = 2; i * i <= n; ++i) {
		while (n % i == 0) {
			res[i]++;
			n /= i;
		}
	}
	if (n != 1) res[n] = 1;
	return res;
}

// Function to check if a number is a prime number
bool IsPrimeNumber(long long num)
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

// Function to calculate the modular inverse of a number
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

// Macro for looping from s to e
#define rep(i,s,e) for(ll i=s;i<e;i++)

// Macro for looping from s to e inclusive
#define repeq(i,s,e) for(ll i=s;i<=e;i++)

int main() {
	long long N, K;
	scanf("%lld %lld", &N, &K);

	// Vector to store N+1 integers
	vll A(N + 1);
	repeq(i, 1, N) {
		scanf("%lld", &A[i]);
	}

	// Variables to track the current position and the dictionary
	long long cur = 1;
	vll dic(N + 1, -1);
	bool flg = false;
	repeq(i, 1, K) {
		if (dic[cur] < 0 || flg) {
			dic[cur] = i;
			cur = A[cur];
		}
		else if (!flg) {
			long long tmp = K - (dic[cur] - 1);
			tmp %= i - dic[cur];
			i = K - tmp;
			flg = true;
		}
	}

	// Output the final position
	printf("%lld\n", cur);
	return 0;
}
