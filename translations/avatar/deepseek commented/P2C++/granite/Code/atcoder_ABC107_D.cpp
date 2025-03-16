
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class BIT {
public:
    BIT(int N) : size(N), tree(N + 1), depth(N.bit_length()) {}

    int _bitsum(int i) {
        int ret = 0;
        while (i) {
            ret += tree[i];
            i ^= i & -i;
        }
        return ret;
    }

    int bitsum(int l, int r = -1) {
        if (r == -1) return _bitsum(l);
        else return _bitsum(r) - _bitsum(l);
    }

    void bitadd(int i, int x) {
        i++;
        while (i <= size) {
            tree[i] += x;
            i += i & -i;
        }
    }

private:
    int size;
    vector<int> tree;
    int depth;
};

int main() {
    int n;
    cin >> n;
    int m = n * (n + 1) / 4;
    vector<int> a(n);
    map<int, int> d;
    vector<int> _a(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        _a[i] = a[i];
    }
    _a[n] = 0;
    sort(_a.begin(), _a.end());
    _a.erase(unique(_a.begin(), _a.end()), _a.end());
    for (int i = 0; i < n; i++) {
        d[a[i]] = lower_bound(_a.begin(), _a.end(), a[i]) - _a.begin();
    }
    for (int i = 0; i < n; i++) {
        a[i] = d[a[i]];
    }

    function<bool(int)> check = [&](int X) {
        vector<int> b(n + 1);
        for (int i = 0; i < n; i++) {
            b[i + 1] = (a[i] >= X) * 2 - 1;
        }
        for (int i = 1; i <= n; i++) {
            b[i] += b[i - 1];
        }
        int c = *min_element(b.begin(), b.end());
        for (int i = 0; i <= n; i++) {
            b[i] -= c;
        }
        BIT bit(n + 1);
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
        if (check(mid)) ok = mid;
        else ng = mid;
    }

    cout << _a[ok] << endl;

    return 0;
}

