
#include <bits/stdc++.h>
using namespace std;

class BIT {
public:
    vector<int> tree;
    int size;
    int depth;

    BIT(int N) {
        size = N;
        tree = vector<int>(N + 1, 0);
        depth = N.bit_length();
    }

    int _bitsum(int i) {
        int ret = 0;
        while (i > 0) {
            ret += tree[i];
            i ^= i & -i;
        }
        return ret;
    }

    int bitsum(int l, int r = -1) {
        if (r < 0) return _bitsum(l);
        return _bitsum(r) - _bitsum(l);
    }

    void bitadd(int i, int x) {
        i++;
        while (i <= size) {
            tree[i] += x;
            i += i & -i;
        }
    }
};

int main() {
    int n;
    cin >> n;
    int m = n * (n + 1) / 4;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    map<int, int> d;
    vector<int> _a = a;
    _a.push_back(0);
    sort(_a.begin(), _a.end());
    _a.erase(unique(_a.begin(), _a.end()), _a.end());
    for (int i = 0; i < _a.size(); i++) {
        d[_a[i]] = i;
    }
    for (int i = 0; i < n; i++) {
        a[i] = d[a[i]];
    }
    auto check = [&](int X) {
        vector<int> b(n + 1);
        for (int i = 0; i < n; i++) {
            b[i + 1] = (a[i] >= X) * 2 - 1;
        }
        for (int i = 0; i < n; i++) {
            b[i + 1] += b[i];
        }
        int c = *min_element(b.begin(), b.end());
        for (int i = 0; i <= n; i++) {
            b[i] -= c;
        }
        BIT bit(n + 2);
        int ans = 0;
        for (int i = 0; i <= n; i++) {
            ans += bit.bitsum(b[i] + 1);
            bit.bitadd(b[i], 1);
        }
        return ans >= m;
    };
    int ng = -1, ok = _a.size();
    while (ok - ng > 1) {
        int mid = (ok + ng) / 2;
        if (check(mid)) {
            ok = mid;
        } else {
            ng = mid;
        }
    }
    cout << _a[ok] << endl;
    return 0;
}

