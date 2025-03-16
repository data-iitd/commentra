
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

// ----- FenwickTree -----

class FenwickTree {
  int n;
  vector<int> dat;
  int minPow2;

public:
  FenwickTree(int n) : n(n), dat(n + 1), minPow2(1) {
    while (minPow2 << 1 <= n) {
      minPow2 <<= 1;
    }
  }

  int sum(int i) {
    int s = 0;
    while (i > 0) {
      s += dat[i];
      i -= i & (-i);
    }
    return s;
  }

  void add(int i, int x) {
    while (i <= n) {
      dat[i] += x;
      i += i & (-i);
    }
  }

  int lower_bound(int w) {
    if (w <= 0) {
      return 0;
    }

    int x = 0;
    for (int k = minPow2; k > 0; k /= 2) {
      if (x + k <= n && dat[x + k] < w) {
        w -= dat[x + k];
        x += k;
      }
    }

    return x + 1;
  }
};

// ----- main() -----

int main() {
  int n, q;
  cin >> n >> q;
  vector<int> C(n);
  for (int i = 0; i < n; i++) {
    cin >> C[i];
  }

  vector<int> P(n);
  for (int i = 0; i < n; i++) {
    P[i] = -1;
  }

  vector<int> Answers(q);
  vector<Query> Q(q);
  for (int i = 0; i < q; i++) {
    int l, r;
    cin >> l >> r;
    Q[i] = Query{i, l, r};
  }

  sort(Q.begin(), Q.end(), [](Query a, Query b) { return a.r < b.r; });
  FenwickTree ft(500000 + 50);

  int k = 0;
  for (Query query : Q) {
    // Process each query
    while (k < query.r) {
      if (P[C[k]] != -1) {
        ft.add(P[C[k]] + 1, -1);
      }
      P[C[k]] = k;
      ft.add(k + 1, 1);

      k++;
    }

    // Calculate answer and print it
    Answers[query.idx] = ft.sum(query.r) - ft.sum(query.l - 1);
  }

  // Print answers
  for (int i = 0; i < q; i++) {
    // cout << Answers[i] << endl;
    cout << Answers[i] << "\n";
  }

  return 0;
}

