#include <bits/stdc++.h>

using namespace std;

int main() {
	// Initialize a buffered reader to read input
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(cin.failbit);
	int n, m, R;
	cin >> n;
	cin >> m;
	cin >> R;
	vector<int> rs(R);
	for (int i = 0; i < R; i++) {
		cin >> rs[i];
		rs[i]--;
	}
	vector<vector<int>> costs(n, vector<int>(n, 1000000007));
	for (int i = 0; i < n; i++) {
		costs[i][i] = 0;
	}
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a;
		cin >> b;
		cin >> c;
		a--;
		b--;
		costs[a][b] = c;
		costs[b][a] = c;
	}
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				costs[i][j] = min(costs[i][j], costs[i][k]+costs[k][j]);
			}
		}
	}
	vector<vector<int>> perms;
	do {
		vector<int> perm;
		for (int i = 0; i < R; i++) {
			perm.push_back(rs[i]);
		}
		for (int i = 1; i < R; i++) {
			perm.push_back(rs[i]);
		}
		perms.push_back(perm);
	} while (next_permutation(rs.begin(), rs.end()));
	int ans = 1000000007;
	for (int i = 0; i < perms.size(); i++) {
		int tmp = 0;
		for (int j = 1; j < perms[i].size(); j++) {
			tmp += costs[perms[i][j-1]][perms[i][j]];
		}
		ans = min(ans, tmp);
	}
	cout << ans << "\n";
}

