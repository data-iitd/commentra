#include <iostream>
#include <vector>

using namespace std;

class FenwickTree {
public:
    FenwickTree(int n) : n(n), data(n, 0) {}

    void Add(int p, int x) {
        p++;
        while (p <= n) {
            data[p - 1] += x;
            p += p & -p;
        }
    }

    int Sum(int l, int r) {
        return sum(r) - sum(l);
    }

private:
    int n;
    vector<int> data;

    int sum(int r) {
        int s = 0;
        while (r > 0) {
            s += data[r - 1];
            r -= r & -r;
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
        fw.Add(i, a);
    }

    for (int i = 0; i < q; i++) {
        int t;
        cin >> t;
        if (t == 0) {
            int p, x;
            cin >> p >> x;
            fw.Add(p, x);
        } else {
            int l, r;
            cin >> l >> r;
            cout << fw.Sum(l, r) << "\n";
        }
    }

    return 0;
}

// <END-OF-CODE>
