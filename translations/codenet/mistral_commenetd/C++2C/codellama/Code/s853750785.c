// AtCoder.c : This file contains the 'main' function. Program execution starts and ends there.
//

#define _USE_MATH_DEFINES // Preprocessor directive to include math constant definitions
#include<math.h> // Standard math library

//#include<cmath> // Alternative way to include math functions

#include<deque> // Double-ended queue
#include<queue> // Standard queue
#include<vector> // Vector container
#include<algorithm> // Standard algorithm library
#include<iostream> // Standard input/output library
#include<set> // Set container
#include<cmath> // Standard math functions
#include<tuple> // Standard tuple data structure
#include<string> // Standard string library
#include<chrono> // C++11 library for measuring time
#include<functional> // Function objects
#include<iterator> // Iterator related functions
#include<random> // Standard random number generation
#include<unordered_set> // Unordered set container
#include<array> // Fixed size array
#include<map> // Associative array (map)
#include<iomanip> // Manipulators for input/output streams
#include<assert.h> // Standard C library for assertions
#include<bitset> // Bit manipulation library
#include<stack> // Stack container
#include<memory> // Memory management library

//#include "Ants.h" // Include custom header file (if any)

using namespace std; // Using standard library namespace
typedef long long ll; // Define long long integer type alias
#define rad_to_deg(rad) (((rad)/2/M_PI)*360) // Helper function to convert radians to degrees
#define EPS (1e-7) // Small constant for floating point comparisons
#define INF (1e9) // Large constant for integer and floating point comparisons
#define PI (acos(-1)) // Mathematical constant Pi
#define rep(i,n) for(int i=0;i<n;i++) // Shorthand for iterating through a range
#define show(s) cout<<s<<endl // Shorthand for printing a value to the console
#define chmin(x,y) x=min(x,y) // Helper function to update the minimum value
#define chmax(x,y) x=max(x,y) // Helper function to update the maximum value
#define LINF (1000000000000000000ll) // Extremely large constant for integer and floating point comparisons
#define MOD (1e9+7) // Modulus constant for modular arithmetic
#define rep1(i,n) for(int i =1;i<=n;i++) // Shorthand for iterating through a range starting from 1
typedef pair < ll, ll> P; // Define pair data structure alias
ll gcd(ll a, ll b) {// Helper function to find the greatest common divisor
	if (b == 0) return a;
	return gcd(b, a % b);
}
ll lcd(ll a, ll b) {// Helper function to find the least common multiple
	return (a / gcd(a, b)) * b;
}
vector<int> divnum(ll num) { // Helper function to get the digits of a number
	int dig;
	vector<int>p;
	while (num) {
		dig = num % 10;
		p.push_back(dig);
		num /= 10;
	}
	return p;
}
int digiter(ll num) { // Helper function to get the number of digits of a number
	int dig;
	vector<int>p;
	while (num) {
		dig = num % 10;
		p.push_back(dig);
		num /= 10;
	}
	return p.size();
}
vector<int> convertstring(string s) { // Helper function to convert a string to a vector of integers
	vector<int> d;
	ll n = s.size();
	rep(i, n) {
		d.push_back(s[i] - '0');
	}
	return d;
}
map< ll, int > prime_factor(ll n) { // Helper function to find the prime factors of a number
	map< ll, int > ret;
	for (ll i = 2; i * i <= n; i++) {
		while (n % i == 0) {
			ret[i]++;
			n /= i;
		}
	}
	if (n != 1) ret[n] = 1;
	return ret;
}
vector<ll> divisor(ll n) { // Helper function to find all divisors of a number
	vector<ll>res;
	for (ll i = 1; i * i <= n; i++) {
		if (n % i == 0) {
			res.push_back(i);
			if (i * i != n)res.push_back(n / i);
		}
	}
	return res;
}

ll myPow(ll x, ll n, ll m) {// Helper function to calculate x raised to the power of n modulo m
	if (n == 0)
		return 1;
	if (n % 2 == 0)
		return myPow(x * x % m, n / 2, m);
	else
		return x * myPow(x, n - 1, m) % m;
}
std::vector<int> Eratosthenes(const int N) {// Helper function to generate a vector of prime numbers up to N
	std::vector<bool> is_prime(N + 1);
	for (int i = 0; i <= N; i++)
	{
		is_prime[i] = true;
	}
	std::vector<int> P;
	for (int i = 2; i <= N; i++)
	{
		if (is_prime[i])
		{
			for (int j = 2 * i; j <= N; j += i)
			{
				is_prime[j] = false;
			}
			P.emplace_back(i);
		}
	}
	return P;
}
const ll mod = MOD; // Define the modulus constant for modular arithmetic
struct mint { // Custom modular integer type

	ll x; // Integer value
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

	// for prime mod
	mint inv() const { return pow(mod - 2); }
	mint& operator/=(const mint a) { return *this *= a.inv(); }
	mint operator/(const mint a) const { return mint(*this) /= a; }
};
istream& operator>>(istream& is, const mint& a) { return is >> a.x; }
ostream& operator<<(ostream& os, const mint& a) { return os << a.x; }
struct combination { // Helper structure for calculating combinations

	vector<mint> fact, ifact; // Factors and inverse factors
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
}comb(1000005);// Precompute combinations up to 1000005
mint f(ll n, ll k) {
	if (n < 0) return 0;
	// nCk = nPk * k!
	mint res = comb(n, k);
	res *= comb.fact[k];
	return res;
}

int N, M; int H[100005];
vector<int> G[100005]; // Adjacency list to represent the graph
int main() {
	scanf("%d %d", &N, &M); // Read the number of nodes and edges
	rep(i, N)scanf("%d", &H[i]); // Read the heights of the nodes
	rep(i, M) { // Iterate through each edge
		int u, v;
		scanf("%d %d", &u, &v); // Read the endpoints of the edge
		u--; v--; // Convert to 0-indexing
		G[u].push_back(v); // Add an edge from node u to node v
		G[v].push_back(u); // Add a reciprocal edge from node v to node u
	}
	ll ans = 0; // Initialize answer variable
	rep(u, N) { // Iterate through each node
		bool flag = true; // Assume that the node has a higher height than its neighbors
		for (int v : G[u]) {
			if (H[u] <= H[v])flag = false; // If not, update the flag
		}
		if (flag)ans++; // If the node has a higher height than its neighbors, increment the answer
	}
	printf("%lld\n", ans); // Print the answer
}

