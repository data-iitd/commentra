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
typedef struct { ll first, second; } P;
ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}
ll lcd(ll a, ll b) {
	if (b == 0) return a;
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
std::vector<int> convertstring(std::string s) {
	std::vector<int> d;
	ll n = s.size();
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
		if (n % i != 0)continue;
		res.push_back(i);
		if (i * i != n)res.push_back(n / i);
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
typedef struct {
	ll x;
} mint;
mint mint_init(ll x) {
	mint m;
	m.x = (x % mod + mod) % mod;
	return m;
}
mint mint_operator_minus(mint a) {
	mint m;
	m.x = -a.x;
	return m;
}
mint& mint_operator_plus_equal(mint* a, mint b) {
	if ((a->x += b.x) >= mod) a->x -= mod;
	return *a;
}
mint& mint_operator_minus_equal(mint* a, mint b) {
	if ((a->x += mod - b.x) >= mod) a->x -= mod;
	return *a;
}
mint& mint_operator_multiply_equal(mint* a, mint b) {
	(a->x *= b.x) %= mod;
	return *a;
}
mint mint_operator_plus(mint a, mint b) {
	return mint_operator_plus_equal(&a, b);
}
mint mint_operator_minus(mint a, mint b) {
	return mint_operator_minus_equal(&a, b);
}
mint mint_operator_multiply(mint a, mint b) {
	return mint_operator_multiply_equal(&a, b);
}
mint mint_pow(mint a, ll t) {
	if (t == 0) return mint_init(1);
	mint res = mint_pow(mint_operator_multiply(a, a), t >> 1);
	if (t & 1) res = mint_operator_multiply(res, a);
	return res;
}
mint mint_inv(mint a) {
	return mint_pow(a, mod - 2);
}
mint& mint_operator_divide_equal(mint* a, mint b) {
	return mint_operator_multiply_equal(a, mint_inv(b));
}
mint mint_operator_divide(mint a, mint b) {
	return mint_operator_divide_equal(&a, b);
}
void mint_input(mint* m) {
	scanf("%lld", &m->x);
}
void mint_output(mint m) {
	printf("%lld", m.x);
}
typedef struct {
	std::vector<mint> fact, ifact;
	int n;
} combination;
combination comb_init(int n) {
	combination c;
	c.n = n;
	assert(n < mod);
	c.fact.resize(n + 1);
	c.ifact.resize(n + 1);
	c.fact[0] = mint_init(1);
	for (int i = 1; i <= n; ++i) c.fact[i] = mint_operator_multiply(c.fact[i - 1], mint_init(i));
	c.ifact[n] = mint_operator_divide(c.fact[n], c.fact[n]);
	for (int i = n; i >= 1; --i) c.ifact[i - 1] = mint_operator_multiply(c.ifact[i], mint_init(i));
	return c;
}
mint comb_operator(combination c, ll n, ll k) {
	if (k < 0 || k > n) return mint_init(0);
	return mint_operator_multiply(c.fact[n], mint_operator_multiply(c.ifact[k], c.ifact[n - k]));
}
mint comb_f(combination c, ll n, ll k) {
	mint res = comb_operator(c, n, k);
	res = mint_operator_multiply(res, c.fact[k]);
	return res;
}

int N, M;
int H[100005];
std::vector<int> G[100005];
int main() {
	scanf("%d %d", &N, &M);
	rep(i, N) scanf("%d", &H[i]);
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
			if (H[u] <= H[v]) flag = false;
		}
		if (flag) ans++;
	}
	printf("%lld\n", ans);
}
