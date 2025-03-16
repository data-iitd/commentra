#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define mod 1000000007
#define mod9 998244353
#define ld long double
#define ull unsigned long long
#define db double
#define ll long long
const db eps = 1e-7;
const int INF = 0x3f3f3f3f;
const ll inf = 0x3f3f3f3f3f3f3f3f;
#define rep(i, be, en) for (int i = be; i <= en; i++)
#define per(i, be, en) for (int i = en; i >= be; i--)

int tc, n, m, fl = 0;

int main() {
    scanf("%d%d%d", &tc, &n, &m);
    if (n > m) {
        int temp = n;
        n = m;
        m = temp;
    }
    for (int i = 1; i <= m; i++) {
        if (i * tc >= n && i * tc <= m) {
            printf("OK\n");
            fl = 1;
            break;
        }
    }
    if (fl == 0) {
        puts("NG");
    }
    return 0;
}
