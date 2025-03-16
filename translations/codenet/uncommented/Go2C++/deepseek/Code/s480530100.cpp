#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

void out(vector<int> x) {
    for (int i : x) {
        cout << i << " ";
    }
    cout << endl;
}

// BIT :
class BIT {
public:
    int n;
    vector<int> data;

    BIT(int n) : n(n), data(n, 0) {}

    void add(int p, int x) {
        p++;
        while (p <= n) {
            data[p - 1] += x;
            p += p & -p;
        }
    }

    int sum(int r) {
        int s = 0;
        while (r > 0) {
            s += data[r - 1];
            r -= r & -r;
        }
        return s;
    }

    int sum(int l, int r) {
        return sum(r) - sum(l);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    BIT fw(n);
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
