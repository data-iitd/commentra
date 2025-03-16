
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> C(n);
    for (int i = 0; i < n; i++) {
        cin >> C[i];
    }

    vector<int> P(n + 1, -1);
    vector<int> Answers(q);
    vector<int> Q(q);
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        Q[i] = i;
    }

    sort(Q.begin(), Q.end(), [&](int i, int j) { return C[Q[i].r] < C[Q[j].r]; });
    vector<int> ft(500000 + 50);

    int k = 0;
    for (int i = 0; i < q; i++) {
        while (k < Q[i].r) {
            if (P[C[k]] != -1) {
                ft[P[C[k]] + 1]--;
            }
            P[C[k]] = k;
            ft[k + 1]++;
            k++;
        }
        Answers[Q[i].idx] = ft[Q[i].r] - ft[Q[i].l - 1];
    }

    for (int i = 0; i < q; i++) {
        cout << Answers[i] << endl;
    }

    return 0;
}

