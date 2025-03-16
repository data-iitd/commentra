#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define mod 1000000007
#define mod9 998244353
#define ld long double
#define ull unsigned long long
#define db double
#define ll long long
const db eps = 1e-7;
const db pi = 3.14159265358979323846;
const int INF = 0x3f3f3f3f;
const ll inf = 0x3f3f3f3f3f3f3f3f;

int main() {
    int tc, n, m, fl = 0;

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
