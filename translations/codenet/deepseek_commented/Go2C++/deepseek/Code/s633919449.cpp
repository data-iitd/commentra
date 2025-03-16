#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <functional>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <unordered_map>
#include <unordered_set>
#include <numeric>
#include <array>
#include <sstream>
#include <iomanip>
#include <ctime>
#include <assert.h>

using namespace std;

const int INF = 1e9;
const long long INF_LL = 1e18;
const double PI = acos(-1.0);

#define all(x) (x).begin(), (x).end()
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define fillchar(a, x) memset(a, x, sizeof(a))
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define debug(x) cerr << #x << " = " << x << "\n"
#define endl "\n"

using ll = long long;
using P = pair<int, int>;
using T = tuple<int, int, int>;
using Graph = vector<vector<int>>;

// The main function reads an integer N and prints "hon" if the last digit of N is 2, 4, 5, 7, or 9,
// "pon" if it is 0, 1, 6, or 8, and "bon" if it is 3. This part of the code handles simple conditional logic
// based on the last digit of N.
int main() {
	int N;
	cin >> N;

	switch (N % 10) {
	case 2:
	case 4:
	case 5:
	case 7:
	case 9:
		cout << "hon" << endl;
		break;
	case 0:
	case 1:
	case 6:
	case 8:
		cout << "pon" << endl;
		break;
	case 3:
		cout << "bon" << endl;
		break;
	}

	return 0;
}

// The Graph struct and its methods define a graph with n nodes and edges.
// The dfs function performs depth-first search, and the bfs function performs breadth-first search.
// These functions are useful for graph traversal and can be used for various graph-related problems.
void dfs(int c, const Graph& edges, vector<bool>& visited) {
	visited[c] = true;

	for (int v : edges[c]) {
		if (visited[v]) continue;
		dfs(v, edges, visited);
	}
}

void bfs(int c, const Graph& graph) {
	queue<int> next;
	next.push(c);
	vector<bool> visited(graph.size(), false);

	while (!next.empty()) {
		int u = next.front();
		next.pop();
		visited[u] = true;

		for (int v : graph[u]) {
			if (visited[v]) continue;

			// なにか処理

			next.push(v);
		}
	}
}

// Utility functions are defined for converting strings to integers, calculating absolute values, finding powers,
// and checking primality. These functions enhance code reusability and readability.
int readInt() {
	int x;
	cin >> x;
	return x;
}

vector<int> readIntArray(int n) {
	vector<int> array(n);
	for (int i = 0; i < n; ++i) {
		cin >> array[i];
	}
	return array;
}

string readString() {
	string s;
	cin >> s;
	return s;
}

vector<string> readStringArray(int n) {
	vector<string> array(n);
	for (int i = 0; i < n; ++i) {
		cin >> array[i];
	}
	return array;
}

int abs(int a) {
	return abs(a);
}

int pow(int p, int q) {
	return pow(p, q);
}

int powMod(int n, int p) {
	if (p == 0) return 1;
	else if (p % 2 == 0) {
		int t = powMod(n, p / 2);
		return (t * t) % mod;
	} else {
		return (n * powMod(n, p - 1)) % mod;
	}
}

int min(int a, int b) {
	return min(a, b);
}

int max(int a, int b) {
	return max(a, b);
}

bool strSearch(const vector<string>& a, const string& b) {
	for (const string& s : a) {
		if (s == b) return true;
	}
	return false;
}

void printIntArray(const vector<int>& array) {
	for (size_t i = 0; i < array.size(); ++i) {
		if (i > 0) cout << " ";
		cout << array[i];
	}
	cout << endl;
}

int calcMod(int x) {
	return x % mod;
}

string reverse(const string& s) {
	string rev(s.rbegin(), s.rend());
	return rev;
}

bool isPrime(int n) {
	if (n < 2) return false;
	if (n == 2) return true;
	if (n % 2 == 0) return false;

	int sqrtN = static_cast<int>(sqrt(n));
	for (int i = 3; i <= sqrtN; i += 2) {
		if (n % i == 0) return false;
	}

	return true;
}

bool contains(const vector<int>& s, int e) {
	for (int v : s) {
		if (e == v) return true;
	}
	return false;
}

vector<int> makeRange(int min, int max) {
	vector<int> a(max - min + 1);
	iota(a.begin(), a.end(), min);
	return a;
}

vector<vector<int>> powerset2(const vector<int>& nums) {
	int length = 1 << nums.size();
	vector<vector<int>> result(length);

	for (int i = 0; i < length; ++i) {
		vector<int> subset;
		for (int j = 0; j < nums.size(); ++j) {
			if (i & (1 << j)) {
				subset.pb(nums[j]);
			}
		}
		result[i] = subset;
	}

	return result;
}

int calcGcd(int x, int y) {
	if (y == 0) return x;
	else if (x >= y) return calcGcd(y, x % y);
	else return calcGcd(x, y % x);
}

vector<int> getDivisor(int n) {
	set<int> divisor;
	divisor.insert(1);
	if (n != 1) divisor.insert(n);

	int sqrtN = static_cast<int>(sqrt(n));
	for (int i = 2; i <= sqrtN; ++i) {
		if (n % i == 0) {
			divisor.insert(i);
			divisor.insert(n / i);
		}
	}

	vector<int> divisorArray(divisor.begin(), divisor.end());
	return divisorArray;
}

struct intHeap {
	vector<int> h;
	int heapSize;

	intHeap() : heapSize(0) {}

	void pushHeap(int x) {
		h.push_back(x);
		++heapSize;
		int i = heapSize - 1;
		while (i > 0 && h[i] > h[(i - 1) / 2]) {
			swap(h[i], h[(i - 1) / 2]);
			i = (i - 1) / 2;
		}
	}

	int popHeap() {
		if (heapSize <= 0) return INF;
		int ret = h[0];
		h[0] = h[heapSize - 1];
		h.pop_back();
		--heapSize;
		int i = 0;
		while (2 * i + 1 < heapSize) {
			int child = 2 * i + 1;
			if (child + 1 < heapSize && h[child] < h[child + 1]) ++child;
			if (h[i] >= h[child]) break;
			swap(h[i], h[child]);
			i = child;
		}
		return ret;
	}
};

int factMod(int n) {
	int value = 1;
	for (int i = 2; i <= n; ++i) {
		value = (value * i) % mod;
	}
	return value;
}

int combinationMod(int n, int k) {
	int factN = factMod(n);
	int factK = factMod(k);
	int factNK = factMod(n - k);
	int factKR = powMod(factK, mod - 2);
	int factNKR = powMod(factNK, mod - 2);
	return ((factN * factKR) % mod * factNKR) % mod;
}

vector<int> primeFactors(int n) {
	vector<int> factors;
	for (int i = 2; i * i <= n; ++i) {
		while (n % i == 0) {
			factors.push_back(i);
			n /= i;
		}
	}
	if (n > 1) factors.push_back(n);
	return factors;
}

