#include <iostream>
#include <iomanip>
#include<math.h>
#include<list>
#include <algorithm>
#include<set>
#include<vector>
#include<math.h>
#include<map>
#include<string>
#include <numeric>
#include <queue>
#include <sstream>
#include <bitset>
#include<stack>

using namespace std;
using ll = long long;
using vll = vector<long long>;
using sll = set<long long>;

// Function to calculate the greatest common divisor (GCD)
template<typename T>
T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

// Function to calculate the least common multiple (LCM)
template<typename T>
T lcm(T a, T b) { return a / gcd(a, b) * b; }

// Function to get the prime factors of a number
template<typename T>
map<T, T> getPrimeFactor(T n) {
	map<T, T> res;
	for (T i = 2; i * i <= n; ++i) {
		while (n % i == 0) {
			res[i] ++;
			n /= i;
		}
	}
	if (n != 1) res[n] = 1;
	return res;
}

// Function to check if a number is a prime number
template<typename T>
bool IsPrimeNumber(T num)
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
	ll N, K;
	std::cin >> N >> K;

	// Vector to store N+1 integers
	vll A(N + 1);
	repeq(i, 1, N) {
		std::cin >> A[i];
	}

	// Variables to track the current position and the dictionary
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

	// Output the final position
	std::cout << cur << endl;
	return 0;
}
