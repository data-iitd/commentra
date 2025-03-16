#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 100000 + 10;
int n, m, a[N], _a[N], d[N], b[N], c[N], bit[N];
int lowbit(int x) {
    return x & (-x);
}
void add(int x, int v) {
    for (int i = x; i <= n; i += lowbit(i))
        bit[i] += v;
}
int sum(int x) {
    int ret = 0;
    for (int i = x; i > 0; i -= lowbit(i))
        ret += bit[i];
    return ret;
}
int main() {
    scanf("%d", &n);
    m = n * (n + 1) / 2;
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    sort(_a + 1, _a + n + 1);
    for (int i = 1; i <= n; i++)
        d[_a[i]] = i;
    for (int i = 1; i <= n; i++)
        a[i] = d[a[i]];
    int l = 0, r = n, mid;
    while (l < r) {
        mid = (l + r) >> 1;
        if (check(mid))
            r = mid;
        else
            l = mid + 1;
    }
    printf("%d\n", _a[l]);
    return 0;
}

bool check(int X) {
    memset(b, 0, sizeof(b));
    for (int i = 1; i <= n; i++)
        b[i] = (a[i] >= X) * 2 - 1;
    for (int i = 1; i <= n; i++)
        b[i] += b[i - 1];
    int c = min(b + 1, b + n + 1);
    for (int i = 1; i <= n; i++)
        b[i] -= c;
    memset(bit, 0, sizeof(bit));
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += sum(b[i]);
        add(b[i], 1);
    }
    return ans >= m;
}

