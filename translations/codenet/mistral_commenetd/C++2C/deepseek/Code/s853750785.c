#include <math.h>
#include <deque>
#include <queue>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
#include <cmath>
#include <tuple>
#include <string>
#include <chrono>
#include <functional>
#include <iterator>
#include <random>
#include <unordered_set>
#include <array>
#include <map>
#include <iomanip>
#include <assert.h>
#include <bitset>
#include <stack>
#include <memory>

typedef long long ll;
#define rad_to_deg(rad) (((rad)/2/M_PI)*360)
#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
#define rep(i,n) for(int i=0;i<n;i++)
#define show(s) printf("%s\n", s)
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)
#define LINF (1000000000000000000ll)
#define MOD (1e9+7)
#define rep1(i,n) for(int i =1;i<=n;i++)
typedef struct { ll first; ll second; } P;
ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}
ll lcd(ll a, ll b) {
	return (a / gcd(a, b)) * b;
}
std::vector<int> divnum(ll num) {
	int dig;
	std::vector<int>p;
	while (num) {
		dig = num % 10;
		p.push_back(dig);
		num /= 10;
	}
	return p;
}
int digiter(ll num) {
	int dig;
	std::vector<int>p;
	while (num) {
		dig = num % 10;
		p.push_back(dig);
		num /= 10;
	}
	return p.size();
}
std::vector<int> convertstring(char* s) {
	std::vector<int> d;
	int n = strlen(s);
	rep(i, n) {
		d.push_back(s[i] - '0');
	}
	return d;
}
std::map< ll, int > prime_factor(ll n) {
	std::map< ll, int > ret;
	for (ll i = 2; i * i <= n; i++) {
		while (n % i == 0) {
			ret[i]++;
			n /= i;
		}
	}
	if (n != 1) ret[n] = 1;
	return ret;
}
std::vector<ll> divisor(ll n) {
	std::vector<ll>res;
	for (ll i = 1; i * i <= n; i++) {
		if (n % i == 0) {
			res.push_back(i);
			if (i * i != n)res.push_back(n / i);
		}
	}
	return res;
}

ll myPow(ll x, ll n, ll m) {
	if (n == 0)
		return 1;
	if (n % 2 == 0)
		return myPow(x * x % m, n / 2, m);
	else
		return x * myPow(x, n - 1, m) % m;
}
std::vector<int> Eratosthenes(const int N) {
	std::vector<bool> is_prime(N + 1);
	for (int i = 0; i <= N; i++) {
		is_prime[i] = true;
	}
	std::vector<int> P;
	for (int i = 2; i <= N; i++) {
		if (is_prime[i]) {
			for (int j = 2 * i; j <= N; j += i) {
				is_prime[j] = false;
			}
			P.emplace_back(i);
		}
	}
	return P;
}
const ll mod = MOD;
struct mint {
	ll x;
	mint(ll x = 0) :x((x% mod + mod) % mod) {}
	mint operator-() const { return mint(-x); }
	mint& operator+=(const mint a) {
		if ((x += a.x) >= mod) x -= mod;
		return *this;
	}
	mint& operator-=(const mint a) {
		if ((x += mod - a.x) >= mod) x -= mod;
		return *this;
	}
	mint& operator*=(const mint a) { (x *= a.x) %= mod; return *this; }
	mint operator+(const mint a) const { return mint(*this) += a; }
	mint operator-(const mint a) const { return mint(*this) -= a; }
	mint operator*(const mint a) const { return mint(*this) *= a; }
	mint pow(ll t) const {
		if (!t) return 1;
		mint a = pow(t >> 1);
		a *= a;
		if (t & 1) a *= *this;
		return a;
	}
	mint inv() const { return pow(mod - 2); }
	mint& operator/=(const mint a) { return *this *= a.inv(); }
	mint operator/(const mint a) const { return mint(*this) /= a; }
};
std::istream& operator>>(std::istream& is, const mint& a) { return is >> a.x; }
std::ostream& operator<<(std::ostream& os, const mint& a) { return os << a.x; }
struct combination {
	vector<mint> fact, ifact;
	combination(ll n) :fact(n + 1), ifact(n + 1) {
		assert(n < mod);
		fact[0] = 1;
		for (ll i = 1; i <= n; ++i) fact[i] = fact[i - 1] * i;
		ifact[n] = fact[n].inv();
		for (ll i = n; i >= 1; --i) ifact[i - 1] = ifact[i] * i;
	}
	mint operator()(ll n, ll k) {
		if (k < 0 || k > n) return 0;
		return fact[n] * ifact[k] * ifact[n - k];
	}
}comb(1000005);
mint f(ll n, ll k) {
	if (n < 0) return 0;
	mint res = comb(n, k);
	res *= comb.fact[k];
	return res;
}

int N, M; int H[100005];
std::vector<int> G[100005];
int main() {
	scanf("%d %d", &N, &M);
	rep(i, N)scanf("%d", &H[i]);
	rep(i, M) {
		int u, v;
		scanf("%d %d", &u, &v);
		u--; v--;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	ll ans = 0;
	rep(u, N) {
		bool flag = true;
		for (int v : G[u]) {
			if (H[u] <= H[v])flag = false;
		}
		if (flag)ans++;
	}
	printf("%lld\n", ans);
}
