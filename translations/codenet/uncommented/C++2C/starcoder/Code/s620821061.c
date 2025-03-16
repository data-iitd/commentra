#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <assert.h>
#include <limits.h>
#include <float.h>
#include <ctype.h>
#include <time.h>
#include <limits.h>
#include <stdarg.h>
#include <inttypes.h>
#include <setjmp.h>
#include <signal.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <assert.h>
#include <limits.h>
#include <float.h>
#include <ctype.h>
#include <time.h>
#include <limits.h>
#include <stdarg.h>
#include <inttypes.h>
#include <setjmp.h>
#include <signal.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#define N 520

typedef long long ll;

/**
 *?????¨?????§??????????????°
 *
 * O(EV)
 */
struct BitMatching {
    int G[2*N][2];
    int match[2*N];
    bool used[2*N];
    ///?????????
    void init() {
        for (int i = 0; i < 2*N; i++) {
            for (int j = 0; j < 2; j++) {
                G[i][j] = -1;
            }
        }
    }
    ///?????´???a????????¨?????´???b?????????????????????
    void add(int a, int b) {
        G[a][0] = b+N;
        G[b+N][1] = a;
    }

    bool dfs(int v) {
        used[v] = true;
        for (int i = 0; i < 2; i++) {
            int u = G[v][i], w = match[u];
            if (w < 0 || (!used[w] && dfs(w))) {
                match[v] = u;
                match[u] = v;
                return true;
            }
        }
        return false;
    }
    ///?????§??????????????°?????¬??°???????????????
    int exec() {
        int res = 0;
        memset(match, -1, sizeof(match));
        for (int v = 0; v < N; v++) {
            if (match[v] < 0) {
                memset(used, 0, sizeof(used));
                if (dfs(v)) {
                    res++;
                }
            }
        }
        return res;
    }
};

int main() {
    while (true) {
        int n, m;
        scanf("%d%d", &n, &m);
        if (!n) break;
        BitMatching bm;
        bm.init();
        int a[n], b[m];
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        for (int i = 0; i < m; i++) {
            scanf("%d", &b[i]);
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (gcd(a[i], b[j])!= 1) {
                    bm.add(i, j);
                }
            }
        }
        printf("%d\n", bm.exec());
    }
    return 0;
}

