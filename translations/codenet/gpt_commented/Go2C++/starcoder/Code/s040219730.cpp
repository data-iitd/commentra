
#include <bits/stdc++.h>

using namespace std;

// <START-OF-CODE>

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, q;
	cin >> n >> q;

	vector<int> C(n);
	for (int i = 0; i < n; i++) {
		cin >> C[i];
	}

	vector<Query> Q;
	for (int i = 0; i < q; i++) {
		int l, r;
		cin >> l >> r;
		Q.push_back({i, l, r});
	}

	sort(Q.begin(), Q.end(), [](Query a, Query b) {
		return a.r < b.r;
	});

	FenwickTree ft(500000 + 50);
	int k = 0;
	for (auto &query : Q) {
		for (int i = k; i < query.r; i++) {
			if (P[C[i]]!= -1) {
				ft.Add(P[C[i]] + 1, -1);
			}
			P[C[i]] = i;
			ft.Add(i + 1, 1);
		}
		Answers[query.idx] = ft.Sum(query.r) - ft.Sum(query.l - 1);
	}

	for (int i = 0; i < q; i++) {
		cout << Answers[i] << endl;
	}
}

// 