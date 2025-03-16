
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int to, pre, c;
} edge;

edge e[100000 * 2 + 10];
int u[100000 + 10];
int n, m;
bool vis[100000 + 10];
int cnt[3];
int d[100000 + 10];
int T;
bool ok;

void ins(int a, int b, int c) {
    e[++m] = (edge){b, u[a], c};
    u[a] = m;
}

#define v e[i].to
#define ec e[i].c
#define reg(i, a) for (int i = u[a]; i; i = e[i].pre)

void dfs(int x, int l) {
    vis[x] = true;
    cnt[l]++;
    d[x] = l;
    T++;
    if (!vis[v]) {
        dfs(v, (l + ec) % 3);
    } else if ((l + ec) % 3!= d[v]) {
        ok = false;
    }
}

int main() {
    scanf("%d%d", &n, &m);
    rep(i, 1, m) {
        int a, b;
        scanf("%d%d", &a, &b);
        ins(a, b, 1);
        ins(b, a, 2);
    }
    LL ans = 0;
    rep(i, 1, n) {
        if (!vis[i]) {
            T = 0;
            rep(j, 0, 2) cnt[j] = 0;
            ok = true;
            dfs(i, 0);
            LL s = cnt[0] + cnt[1] + cnt[2];
            if (!ok) {
                ans += s * s;
            } else {
                if (cnt[0] && cnt[1] && cnt[2]) {
                    ans += cnt[0] * cnt[1] + cnt[1] * cnt[2] + cnt[2] * cnt[0];
                } else {
                    ans += T / 2;
                }
            }
        }
    }
    printf("%lld\n", ans);
}
