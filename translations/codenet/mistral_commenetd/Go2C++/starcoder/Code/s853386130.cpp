
#include <bits/stdc++.h>

using namespace std;

// Global variables initialization
int mod = 1000000007;
int INF = 1000000007;

int main() {
	// Reading input from standard input
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	// Variables initialization
	int n, m, R;
	cin >> n; // Reading number of cities n
	cin >> m; // Reading number of roads m
	cin >> R; // Reading number of starting points R

	// Initializing rs vector with starting points
	vector<int> rs(R);
	for (int i = 0; i < R; i++) {
		cin >> rs[i]; // Reading starting point i
		rs[i]--; // Decreasing starting point index for matrix indexing
	}

	// Initializing costs matrix with infinite values
	vector<vector<int>> costs(n, vector<int>(n, INF));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			costs[i][j] = INF; // Initializing costs[i][j] with infinite value
			costs[i][i] = 0;   // Initializing costs[i][i] with zero value
		}
	}

	// Reading roads and filling costs matrix with their costs
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a; // Reading road starting point a
		cin >> b; // Reading road ending point b
		cin >> c; // Reading road cost c
		a--;                 // Decreasing starting point index for matrix indexing
		b--;                 // Decreasing ending point index for matrix indexing
		costs[a][b] = c;     // Filling costs[a][b] with cost c
		costs[b][a] = c;     // Filling costs[b][a] with cost c
	}

	// Applying Warshall-Floyd algorithm to find shortest paths between all pairs of cities
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				costs[i][j] = min(costs[i][j], costs[i][k]+costs[k][j]); // Updating costs[i][j] with minimum of current value and costs[i][k] + costs[k][j]
			}
		}
	}

	// Calculating minimum cost of visiting all cities in a single tour
	vector<vector<int>> perms = permutations(rs); // Generating all permutations of starting points
	int ans = INF; // Initializing answer with infinite value
	for (vector<int> perm : perms) { // Iterating through all permutations
		int tmp = 0; // Initializing temporary variable tmp with zero value
		for (int j = 1; j < perm.size(); j++) { // Iterating through all pairs of consecutive starting points
			int from = perm[j-1]; // Getting previous starting point
			int to = perm[j];     // Getting current starting point
			tmp += costs[from][to]; // Adding cost of road from from to to tmp
		}
		ans = min(ans, tmp); // Updating answer with minimum of current answer and tmp
	}
	cout << ans << "\n"; // Printing answer
}

// Helper function to generate all permutations of given vector
vector<vector<int>> permutations(vector<int> arr) {
	// Helper function initialization
	auto helper = [&](vector<int> arr, int n) {
		if (n == 1) { // Base case: when only one element left in arr
			vector<int> tmp(arr.size());
			copy(arr.begin(), arr.end(), tmp.begin()); // Copying arr to tmp for returning
			res.push_back(tmp); // Adding tmp to result
			return;
		}

		for (int i = 0; i < n; i++) { // Iterating through all elements of arr
			helper(arr, n-1); // Recursively calling helper function with n-1
			if (n%2 == 1) { // Swapping first and last elements when n is odd
				int tmp = arr[i];
				arr[i] = arr[n-1];
				arr[n-1] = tmp;
			} else { // Swapping first and last elements when n is even
				int tmp = arr[0];
				arr[0] = arr[n-1];
				arr[n-1] = tmp;
			}
		}
	};
	vector<vector<int>> res; // Initializing result vector
	helper(arr, arr.size()); // Calling helper function with arr and its length
	return res;
}

