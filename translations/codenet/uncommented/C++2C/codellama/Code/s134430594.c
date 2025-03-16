#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

#define int long long

struct Ban {
    int l;
    int r;
    int val;

    Ban() {}

    Ban(int l_, int r_, int val_) {
        l = l_;
        r = r_;
        val = val_;
    }
};

struct Sp {
    const int LIM = 20; 
    const int N = 2e5 + 7;

    int mn[LIM][N];
    int pw[N];

    void init(int *a) {
        int n = sizeof(a) / sizeof(int);
        for (int i = 0; i < n; i++) {
            mn[0][i] = a[i]; 
        }
        for (int i = 0; i + 1 < LIM; i++) {
            for (int j = 0; j + (1 << (i + 1)) <= n; j++) {
                mn[i + 1][j] = max(mn[i][j], mn[i][j + (1 << i)]);
            }
        }
        pw[1] = 0;
        for (int i = 2; i < N; i++) {
            pw[i] = pw[i / 2] + 1;
        }
    } 

    int get(int l, int r) {
        r++;
        int p = pw[r - l];
        return min(mn[p][l], mn[p][r - (1 << p)]);
    }
};

int main() {
    int n;
    scanf("%lld", &n);
    int *a = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    int *dl = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        dl[i] = i - a[i];
    }
    int ans = 0;
    struct Ban *bans = (struct Ban *)malloc(n * sizeof(struct Ban));
    for (int i = 0; i < n; i++) {
        int r = i;
        while (r + 1 < n && a[r] + 1 == a[r + 1]) {
            r++;
        }
        ans += a[r];
        i = r;
        bans[i].l = r - a[r];
        bans[i].r = r;
        bans[i].val = r - a[r];
    }
    struct Sp sp;
    sp.init(dl);
    for (int i = 0; i < n; i++) {
        if (sp.get(bans[i].l, bans[i].r) > bans[i].val) {
            printf("-1\n");
            return 0;
        }
    }
    printf("%lld\n", ans);
}

