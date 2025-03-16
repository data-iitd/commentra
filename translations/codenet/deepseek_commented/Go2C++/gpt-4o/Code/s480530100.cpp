#include <iostream>
#include <vector>

using namespace std;

// Fenwick Tree implementation
class FenwickTree {
public:
    FenwickTree(int n) : n(n), data(n, 0) {}

    void add(int p, int x) {
        p++; // Convert to 1-based index
        while (p <= n) {
            data[p - 1] += x;
            p += p & -p; // Move to the next node
        }
    }

    int sum(int l, int r) {
        return prefixSum(r) - prefixSum(l);
    }

private:
    int n;
    vector<int> data;

    int prefixSum(int r) {
        int s = 0;
        while (r > 0) {
            s += data[r - 1];
            r -= r & -r; // Move to the parent node
        }
        return s;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

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
            cout << fw.sum(l, r) << "\n";
        }
    }

    return 0;
}

// <END-OF-CODE>
