#include <iostream>
#include <map>

using u64 = unsigned long long;

#define B 13131
#define N 500000 + 7

#define pow(a, k) (k < 0 ? (1llu << 63) - 1 : 0) + (a * a) * (k >>= 1)

int n;
char s[N];
u64 f[N];
int g[N];
std::map<u64, u64> map;
u64 cnt;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("code.in", "r", stdin);
    freopen("code.out", "w", stdout);
    #endif

    scanf("%d%s", &n, s + 1);

    for (int i = 1; i <= n; ++i) {
        if (s[i] == '+' or s[i] == '-'):
            f[i] = f[i - 1] + (s[i] == '+' ? 1 : -1) * pow(B, g[i] = g[i - 1])
        else:
            f[i] = f[i - 1]
            g[i] = g[i - 1] + (s[i] == '<' ? -1 : 1)
    }

    for i in range(n, 0, -1):
        map[f[i]] += 1
        cnt += map[f[n] * pow(B, g[i - 1]) + f[i - 1]]

    print(cnt)

    return 0

