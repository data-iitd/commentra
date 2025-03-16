#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define INF_INT 2147483647
#define INF_LONG 9223372036854775807

struct FenwickTree {
    vector<int> dat;
    int n;
    int minPow2;

    FenwickTree(int n) {
        dat.resize(n + 1, 0);
        this->n = n;

        minPow2 = 1;
        while ((minPow2 << 1) <= n) {
            minPow2 <<= 1;
        }
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

    int LowerBound(int w) {
        if (w <= 0) return 0;

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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    vector<int> C(n);
    for (int i = 0; i < n; i++) {
        cin >> C[i];
    }

    vector<Query> Q(q);
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        Q[i] = {i, l, r};
    }

    sort(Q.begin(), Q.end(), [](const Query& a, const Query& b) {
        return a.r < b.r;
    });

    vector<int> P(500000 + 50, -1);
    vector<int> Answers(q);

    FenwickTree ft(500000 + 50);

    int k = 0;
    for (const auto& query : Q) {
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
