
#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1e9 + 7;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, q;
  cin >> n >> q;
  vector<int> C(n);
  for (int i = 0; i < n; ++i) {
    cin >> C[i];
  }

  vector<Query> Q(q);
  for (int i = 0; i < q; ++i) {
    int l, r;
    cin >> l >> r;
    Q[i] = Query{i, l, r};
  }

  sort(Q.begin(), Q.end(), [](const Query &a, const Query &b) {
    return a.r < b.r;
  });

  vector<int> P(n + 1, -1);
  vector<int> Answers(q);

  FenwickTree ft(n + 1);

  int k = 0;
  for (const auto &query : Q) {
    for (; k < query.r; ++k) {
      if (P[C[k]]!= -1) {
        ft.Add(P[C[k]] + 1, -1);
      }
      P[C[k]] = k;
      ft.Add(k + 1, 1);
    }

    Answers[query.idx] = ft.Sum(query.r) - ft.Sum(query.l - 1);
  }

  for (int i = 0; i < q; ++i) {
    cout << Answers[i] << endl;
  }

  return 0;
}

// 