
```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class FenwickTree {
private:
    vector<int> data;
    int n;

public:
    FenwickTree(int n) : n(n), data(n, 0) {}

    void add(int p, int x) {
        p++;
        for (int i = p; i <= n; i += i & -i) {
            data[i-1] += x;
        }
    }

    int sum(int l, int r) {
        return sum(r) - sum(l);
    }

private:
    int sum(int r) {
        int s = 0;
        for (int i = r; i > 0; i -= i & -i) {
            s += data[i-1];
        }
        return s;
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

