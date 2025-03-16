
#include <iostream>
#include <vector>

using namespace std;

// Fenwick Tree
class FenwickTree {
public:
    int n;
    vector<int> data;

    FenwickTree(int n) {
        this->n = n;
        data.resize(n);
    }

    void add(int p, int x) {
        p++;
        for (; p <= n; p += p & -p) {
            data[p - 1] += x;
        }
    }

    int sum(int r) {
        int s = 0;
        for (; r > 0; r -= r & -r) {
            s += data[r - 1];
        }
        return s;
    }

    int sum(int l, int r) {
        return sum(r) - sum(l);
    }
};

int main() {
    int n, q;
    cin >> n >> q;

    FenwickTree fw(n);

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        fw.add(i, a);
    }

    for (int i = 0; i < q; i++) {
        int t;
        cin >> t;
        if (t == 0) {
            int p, x;
            cin >> p >> x;
            fw.add(p, x);
        } else {
            int l, r;
            cin >> l >> r;
            cout << fw.sum(l, r) << endl;
        }
    }

    return 0;
}

