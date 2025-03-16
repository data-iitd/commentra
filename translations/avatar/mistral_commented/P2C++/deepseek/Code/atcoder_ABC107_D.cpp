#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

class BIT {
public:
    BIT(int N) : size(N), tree(N + 1, 0) {
        depth = log2(N) + 1;
    }

    void bitadd(int i, int x) {
        i += 1;
        while (i <= size) {
            tree[i] += x;
            i += i & -i;
        }
    }

    int bitsum(int l, int r = -1) {
        if (r == -1) {
            return _bitsum(l);
        } else {
            return _bitsum(r) - _bitsum(l);
        }
    }

private:
    int size;
    std::vector<int> tree;
    int depth;

    int _bitsum(int i) {
        int ret = 0;
        while (i) {
            ret += tree[i];
            i &= i - 1;
        }
        return ret;
    }
};

int main() {
    int n;
    std::cin >> n;
    int m = n * (n + 1) / 4;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    std::vector<int> _a = a;
    std::sort(_a.begin(), _a.end());
    _a.erase(std::unique(_a.begin(), _a.end()), _a.end());

    std::vector<int> d(_a.size());
    for (int i = 0; i < _a.size(); ++i) {
        d[i] = std::distance(_a.begin(), std::find(_a.begin(), _a.end(), 0));
    }

    for (int i = 0; i < n; ++i) {
        a[i] = std::distance(_a.begin(), std::find(_a.begin(), _a.end(), a[i]));
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
        for (int i = 0; i <= n; ++i) {
            b[i] -= c;
        }
        BIT bit(n + 1);
        long long ans = 0;
        for (int x : b) {
            ans += bit.bitsum(x + 1);
            bit.bitadd(x, 1);
        }
        return ans >= m;
    };

    int low = 0, high = _a.size() - 1;
    while (high - low > 1) {
        int mid = (low + high) / 2;
        if (check(_a[mid])) {
            low = mid;
        } else {
            high = mid;
        }
    }

    std::cout << _a[low] << std::endl;
    return 0;
}
