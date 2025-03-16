
// AtCoder.java : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。

import java.util.*;

// Include necessary libraries for various functionalities
import java.util.Arrays;
import java.util.Deque;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Vector;
import java.util.function.Function;
import java.util.stream.Collectors;

// Define type aliases for convenience
typedef long long ll;

// Define mathematical constants and macros
#define rad_to_deg(rad) (((rad)/2/Math.PI)*360)
#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
#define rep(i,n) for(int i=0;i<n;i++)
#define show(s) System.out.println(s)
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)
#define LINF (1000000000000000000ll)
#define MOD (1e9+7)
#define rep1(i,n) for(int i =1;i<=n;i++)

// Define a pair type for convenience
typedef Pair < ll, ll> P;

// Function to calculate the greatest common divisor (GCD)
ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

// Function to calculate the least common multiple (LCM)
ll lcd(ll a, ll b) {
	if (b == 0) return a;
	return (a / gcd(a, b)) * b;
}

// Function to return the digits of a number as a vector
vector<int> divnum(ll num) {
	int dig;
	vector<int>p;
	while (num) {
		dig = num % 10;
		p.push_back(dig);
		num /= 10;
	}
	return p;
}

// Function to count the number of digits in a number
int digiter(ll num) {
	int dig;
	vector<int>p;
	while (num) {
		dig = num % 10;
		p.push_back(dig);
		num /= 10;
	}
	return p.size();
}

// Function to convert a string to a vector of integers
vector<int> convertstring(String s) {
	vector<int> d;
	ll n = s.length();
	rep(i, n) {
		d.push_back(s.charAt(i) - '0');
	}
	return d;
}

// Function to perform prime factorization of a number
map< ll, int > prime_factor(ll n) {
	map< ll, int > ret;
	for (ll i = 2; i * i <= n; i++) {
		while (n % i == 0) {
			ret.put(i, ret.get(i) + 1);
			n /= i;
		}
	}
	if (n != 1) ret.put(n, 1);
	return ret;
}

// Function to find all divisors of a number
vector<ll> divisor(ll n) {
	vector<ll>res;
	for (ll i = 1; i * i <= n; i++) {
		if (n % i != 0) continue;
		res.push_back(i);
		if (i * i != n) res.push_back(n / i);
	}
	return res;
}

// Function to compute x raised to the power n modulo m
ll myPow(ll x, ll n, ll m) {
	if (n == 0)
		return 1;
	if (n % 2 == 0)
		return myPow(x * x % m, n / 2, m);
	else
		return x * myPow(x, n - 1, m) % m;
}

// Function to generate a list of prime numbers using the Sieve of Eratosthenes
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

// Overload input/output operators for mint
istream& operator>>(istream& is, const mint& a) { return is >> a.x; }
ostream& operator<<(ostream& os, const mint& a) { return os << a.x; }

// Structure for combinations (n choose k)
struct combination {
	vector<mint> fact, ifact;
	combination(ll n) : fact(n + 1), ifact(n + 1) {
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
} comb(1000005); // Precompute combinations up to 1,000,005

// Function to calculate permutations with repetition
mint f(ll n, ll k) {
	if (n < 0) return 0;
	// nPk = nCk * k!
	mint res = comb(n, k);
	res *= comb.fact[k];
	return res;
}

// Main function
int N, M; 
int H[100005]; // Array to hold heights
vector<int> G[100005]; // Adjacency list for the graph

int main() {
	// Read number of nodes (N) and edges (M)
	cin >> N >> M;

	// Read heights of each node
	rep(i, N) cin >> H[i];

	// Read edges and build the graph
	rep(i, M) {
		int u, v;
		cin >> u >> v;
		u--; v--; // Convert to 0-based indexing
		G[u].push_back(v);
		G[v].push_back(u);
	}

	ll ans = 0; // Variable to count the number of nodes that are taller than all their neighbors

	// Iterate through each node to check if it is taller than all its neighbors
	rep(u, N) {
		boolean flag = true; // Flag to check if the current node is taller
		for (int v : G[u]) {
			if (H[u] <= H[v]) flag = false; // If any neighbor is taller or equal, set flag to false
		}
		if (flag) ans++; // If the flag is still true, increment the answer
	}

	// Output the result
	System.out.println(ans);
}

