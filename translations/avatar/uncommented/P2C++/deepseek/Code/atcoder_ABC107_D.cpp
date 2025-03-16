#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

class BIT {
public:
    BIT(int N) : size(N), tree(N + 1, 0) {
        depth = 0;
        while (N) {
            depth++;
            N >>= 1;
        }
    }

    int _bitsum(int i) {
        int ret = 0;
        while (i) {
            ret += tree[i];
            i ^= i & -i;
        }
        return ret;
    }

    int bitsum(int l, int r = -1) {
        if (r == -1) {
            return _bitsum(l);
        } else {
            return _bitsum(r) - _bitsum(l);
        }
    }

    void bitadd(int i, int x) {
        i += 1;
        while (i <= size) {
            tree[i] += x;
            i += i & -i;
        }
    }

private:
    int size;
    std::vector<int> tree;
    int depth;
};

int main() {
    int n;
    std::cin >> n;
    int m = n * (n + 1) / 4;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    std::map<int, int> d;
    std::vector<int> _a(a);
    _a.push_back(0);
    std::sort(std::unique(_a.begin(), _a.end()), _a.end());
    for (int i = 0; i < _a.size(); ++i) {
        d[_a[i]] = i;
    }
    for (int i = 0; i < n; ++i) {
        a[i] = d[a[i]];
    }

    auto check = [&](int X) {
        std::vector<int> b(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            b[i + 1] = (a[i] >= X) * 2 - 1;
        }
        for (int i = 0; i < n; ++i) {
            b[i + 1] += b[i];
        }
        int c = *std::min_element(b.begin(), b.end());
        for (int i = 0; i < b.size(); ++i) {
            b[i] -= c;
        }
        BIT bit(n + 2);
        long long ans = 0;
        for (int x : b) {
            ans += bit.bitsum(x + 1);
            bit.bitadd(x, 1);
        }
        return ans >= m;
    };

    std::vector<int> t{static_cast<int>(_a.size()), 0};
    while (t[0] - t[1] > 1) {
        int mid = (t[0] + t[1]) / 2;
        if (check(mid)) {
            t[1] = mid;
        } else {
            t[0] = mid;
        }
    }
    std::cout << _a[t[1]] << std::endl;
    return 0;
}
