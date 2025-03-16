#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 100010

struct edge {
    int to, pre, c;
} e[N << 1];

int u[N], l = 0;
void ins(int a, int b, int c) {
    e[++l] = (struct edge){b, u[a], c};
    u[a] = l;
}

int n, m;
bool vis[N], ok;
long long cnt[3];
int d[N];
int T;

void dfs(int x, int l) {
    vis[x] = true;
    cnt[l]++;
    d[x] = l;
    for (int i = u[x]; i; i = e[i].pre) {
        T++;
        int v = e[i].to;
        int ec = e[i].c;
        if (!vis[v]) {
            dfs(v, (l + ec) % 3);
        } else if ((l + ec) % 3 != d[v]) {
            ok = false;
        }
    }
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        ins(a, b, 1);
        ins(b, a, 2);
    }
    
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            T = 0;
            for (int j = 0; j < 3; j++) {
                cnt[j] = 0;
            }
            ok = true;
            dfs(i, 0);
            long long s = cnt[0] + cnt[1] + cnt[2];
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
    return 0;
}

// <END-OF-CODE>
