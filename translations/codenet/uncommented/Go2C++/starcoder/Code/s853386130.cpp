#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000007;
const int INF = 1000000007;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m, R;
	cin >> n;
	cin >> m;
	cin >> R;

	vector<int> rs(R);
	for (int i = 0; i < R; i++) {
		cin >> rs[i];
		rs[i]--;
	}

	vector<vector<int>> costs(n, vector<int>(n, INF));
	for (int i = 0; i < n; i++) {
		costs[i][i] = 0;
	}
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

	// Warshall-Floyd
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				costs[i][j] = min(costs[i][j], costs[i][k]+costs[k][j]);
			}
		}
	}

	// 順列で訪問先の順序をすべて試す
	// これでは重複して訪問する町がでてしまうか。。
	vector<vector<int>> perms;
	do {
		vector<int> perm;
		for (int i = 0; i < R; i++) {
			perm.push_back(rs[i]);
		}
		perms.push_back(perm);
	} while (next_permutation(rs.begin(), rs.end()));

	int ans = INF;
	for (auto perm : perms) {
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

// 