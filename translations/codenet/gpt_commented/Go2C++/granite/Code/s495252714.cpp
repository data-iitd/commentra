
```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

const int mod = 1000000007;

int modpow(int a, int n) {
    int res = 1;
    while (n > 0) {
        if (n & 1) {
            res = (long long)res * a % mod;
        }
        a = (long long)a * a % mod;
        n >>= 1;
    }
    return res;
}

int main() {
    int n;
    scanf("%d", &n);

    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &c[i]);
    }

    sort(c.begin(), c.end());

    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = (ans + (n + 1 - i) * c[i] % mod) % mod;
    }

    printf("%d\n", ans * modpow(4, n - 1) % mod);

    return 0;
}

