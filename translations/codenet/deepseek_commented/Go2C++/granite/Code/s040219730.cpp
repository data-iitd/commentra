

#include <bits/stdc++.h>

using namespace std;

// Define the FenwickTree class
class FenwickTree {
private:
    vector<int> dat;
    int n;
    int minPow2;

public:
    FenwickTree(int n) {
        dat.resize(n + 1);
        this->n = n;

        minPow2 = 1;
        while (minPow2 <= n) {
            minPow2 *= 2;
        }
    }

    int sum(int i) {
        int s = 0;
        for (int x = i; x > 0; x -= x & (-x)) {
            s += dat[x];
        }
        return s;
    }

    void add(int i, int x) {
        for (int k = minPow2; k > 0; k /= 2) {
            if (i + k <= n) {
                dat[i + k] += x;
            }
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

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }

    vector<int> p(n + 1, -1);
    vector<int> answers(q);

    FenwickTree ft(n);

    int k = 0;
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        l--;
        r--;

        for (int j = k; j <= r; j++) {
            if (p[c[j]]!= -1) {
                ft.add(p[c[j]] + 1, -1);
            }
            p[c[j]] = j;
            ft.add(j + 1, 1);
            k = max(k, j);
        }

        answers[i] = ft.sum(r) - ft.sum(l);
    }

    for (int i = 0; i < q; i++) {
        cout << answers[i] << endl;
    }

    return 0;
}

