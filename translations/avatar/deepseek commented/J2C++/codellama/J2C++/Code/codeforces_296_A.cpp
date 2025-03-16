
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <cctype>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <iomanip>
#include <cassert>
#include <random>
#include <chrono>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define ll long long
#define int long long
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << ", " << #y << "=" << y << endl
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int>	vi;
typedef vector<ll> vll;
typedef vector<ull> vull;
typedef vector<pii>	vpii;
typedef vector<pll>	vpll;
typedef vector<vi> vvi;
typedef vector<vll>	vvll;
typedef vector<vull> vvull;
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) {
    uniform_int_distribution<int> uid(0,lim-1);
    return uid(rang);
}

const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;

class InputReader {
	public:
		InputReader(const string &file_name) {
			ifstream fin(file_name);
			if (fin.fail()) {
				throw runtime_error("Error opening file");
			}
			string line;
			while (getline(fin, line)) {
				stringstream ss(line);
				string token;
				while (ss >> token) {
					tokens.push_back(token);
				}
			}
		}

		string next() {
			if (tokens.empty()) {
				throw runtime_error("No more tokens available");
			}
			string token = tokens.front();
			tokens.pop_front();
			return token;
		}

		int nextInt() {
			return stoi(next());
		}

		long long nextLong() {
			return stoll(next());
		}

		double nextDouble() {
			return stod(next());
		}

		string nextLine() {
			string str = "";
			string token;
			while (!tokens.empty() && isspace(tokens.front()[0])) {
				tokens.pop_front();
			}
			while (!tokens.empty() && !isspace(tokens.front()[0])) {
				token = tokens.front();
				tokens.pop_front();
				str += token;
			}
			return str;
		}

	private:
		deque<string> tokens;
};

class Task {
	public:
		void solve() {
			InputReader in;
			in.init("");
			int n = in.nextInt();
			int arr[1001] = {0};
			for (int i = 0; i < n; i++) {
				int x = in.nextInt();
				arr[x]++;
			}
			int count_max = -1;
			for (int i = 1; i < 1001; i++) {
				if (count_max < arr[i]) count_max = arr[i];
			}
			if (n % 2 == 0) {
				if (count_max <= n / 2) {
					cout << "YES" << endl;
				} else {
					cout << "NO" << endl;
				}
			} else {
				if (count_max <= n / 2 + 1) {
					cout << "YES" << endl;
				} else {
					cout << "NO" << endl;
				}
			}
		}
};

int main() {
	Task task;
	task.solve();
	return 0;
}

