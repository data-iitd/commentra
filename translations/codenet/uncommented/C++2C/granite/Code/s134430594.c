
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <assert.h>

typedef long long ll;

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

namespace Sp {
    const int LIM = 20; 
    const int N = 200007;

    int mn[LIM][N];
    int pw[N];

    void init(int *a, int n) {
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
}

int main() {
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    int dl[n];
    for (int i = 0; i < n; i++) {
        if (a[i] > i) {
            printf("-1\n");
            return 0;
        }
        dl[i] = i - a[i];
    }
    int ans = 0;
    vector<Ban> bans;
    for (int i = 0; i < n; i++) {
        int r = i;
        while (r + 1 < n && a[r] + 1 == a[r + 1]) {
            r++;
        }
        ans += a[r];
        i = r;
        bans.push_back(Ban(r - a[r], r, r - a[r]));
    }
    Sp::init(dl, n);
    for (auto t : bans) {
        // cerr << t.l + 1 <<'' << t.r + 1 <<'' << t.val << endl;
        if (Sp::get(t.l, t.r) > t.val) {
            printf("-1\n");
            return 0;
        }
    }
    printf("%d\n", ans);
}
