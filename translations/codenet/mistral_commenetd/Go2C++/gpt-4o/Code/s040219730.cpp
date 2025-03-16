#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000000 + 7;
const int MAXN = 500000 + 50;

int n, q;
vector<int> C;
vector<int> Answers(MAXN);
vector<int> P(MAXN, -1);

struct Query {
    int idx, l, r;
};

class FenwickTree {
public:
    vector<int> dat;
    int n;

    FenwickTree(int n) : n(n) {
        dat.resize(n + 1, 0);
    }

    int Sum(int i) {
        int s = 0;
        while (i > 0) {
            s += dat[i];
            i -= i & (-i);
        }
        return s;
    }

    void Add(int i, int x) {
        while (i <= n) {
            dat[i] += x;
            i += i & (-i);
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;
    C.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> C[i];
    }

    vector<Query> Q(q);
    for (int i = 0; i < q; i++) {
        cin >> Q[i].l >> Q[i].r;
        Q[i].idx = i;
    }

    sort(Q.begin(), Q.end(), [](const Query &a, const Query &b) {
        return a.r < b.r;
    });

    FenwickTree ft(MAXN);
    int k = 0;

    for (const auto &query : Q) {
        while (k < query.r) {
            if (P[C[k]] != -1) {
                ft.Add(P[C[k]] + 1, -1);
            }
            P[C[k]] = k;
            ft.Add(k + 1, 1);
            k++;
        }
        Answers[query.idx] = ft.Sum(query.r) - ft.Sum(query.l - 1);
    }

    for (int i = 0; i < q; i++) {
        cout << Answers[i] << "\n";
    }

    return 0;
}

// <END-OF-CODE>
