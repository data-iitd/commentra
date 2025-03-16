#include <bits/stdc++.h>

using namespace std;

// Constants for the modulo operation and infinity value
const int mod = 1000000007;
const int INF = 1000000007;

int main() {
	// Create a new reader to read from standard input
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	istream* r = &cin;

	// Read the number of cities, roads, and restaurants
	int n, m, R;
	cin >> n;
	cin >> m;
	cin >> R;

	// Read the indices of the restaurants and decrement by 1 for 0-based indexing
	vector<int> rs(R);
	for (int i = 0; i < R; i++) {
		cin >> rs[i];
		rs[i]--;
	}

	// Initialize the cost matrix with INF and set diagonal to 0
	vector<vector<int>> costs(n, vector<int>(n, INF));
	for (int i = 0; i < n; i++) {
		costs[i][i] = 0;
	}

	// Read the road connections and their costs, updating the cost matrix
	int a, b, c;
	for (int i = 0; i < m; i++) {
		cin >> a;
		cin >> b;
		cin >> c;
		a--;
		b--;
		costs[a][b] = c;
		costs[b][a] = c;
	}

	// Use the Floyd-Warshall algorithm to compute the shortest paths between all pairs of cities
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				costs[i][j] = min(costs[i][j], costs[i][k]+costs[k][j]);
			}
		}
	}

	// Generate all permutations of the restaurant indices and find the minimum cost tour
	vector<vector<int>> perms = permutations(rs);
	int ans = INF;
	for (vector<int> perm : perms) {
		int tmp = 0;
		for (int j = 1; j < perm.size(); j++) {
			int from = perm[j-1];
			int to = perm[j];
			tmp += costs[from][to];
		}
		ans = min(ans, tmp);
	}
	cout << ans << "\n";
}

// Function to generate all permutations of a given array
vector<vector<int>> permutations(vector<int> arr) {
	function<void(vector<int>, int)> helper;
	vector<vector<int>> res;

	helper = [&](vector<int> arr, int n) {
		if (n == 1) {
			vector<int> tmp(arr.size());
			copy(arr.begin(), arr.end(), tmp.begin());
			res.push_back(tmp);
		} else {
			for (int i = 0; i < n; i++) {
				helper(arr, n-1);
				if (n%2 == 1) {
					int tmp = arr[i];
					arr[i] = arr[n-1];
					arr[n-1] = tmp;
				} else {
					int tmp = arr[0];
					arr[0] = arr[n-1];
					arr[n-1] = tmp;
				}
			}
		}
	};
	helper(arr, arr.size());
	return res;
}

