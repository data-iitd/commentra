#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include <limits.h>
#include <math.h>
#include <ctype.h>
#include <time.h>
#include <float.h>
#include <limits.h>
#include <stdarg.h>
#include <setjmp.h>
#include <signal.h>
#include <errno.h>
#include <ctype.h>
#include <locale.h>
#include <wchar.h>
#include <wctype.h>
#include <fenv.h>
#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include <limits.h>
#include <math.h>
#include <ctype.h>
#include <time.h>
#include <float.h>
#include <limits.h>
#include <stdarg.h>
#include <setjmp.h>
#include <signal.h>
#include <errno.h>
#include <ctype.h>
#include <locale.h>
#include <wchar.h>
#include <wctype.h>
#include <fenv.h>
#include <inttypes.h>
#include <stdint.h>

int a[1000000];
int b[1000000];
int c[1000000];
int d[1000000];
int n, m, q;
long ans = -100;

void dfs(int *list, int i) {
    if (i == n) {
        long score = 0;
        for (int j = 0; j < q; ++j) {
            score += (list[b[j]] - list[a[j]] == c[j])? d[j] : 0;
        }
        ans = max(ans, score);
        return;
    }
    if (i == 0) {
        for (int j = 1; j <= m; ++j) {
            list[i] = j;
            dfs(list, i + 1);
        }
    } else {
        for (int j = list[i - 1] + 1; j <= m; ++j) {
            list[i] = j;
            dfs(list, i + 1);
        }
    }
}

int main() {
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 0; i < q; ++i) {
        scanf("%d%d%d%d", &a[i], &b[i], &c[i], &d[i]);
        --a[i];
        --b[i];
    }
    dfs(a, 0);
    printf("%ld\n", ans);
    return 0;
}

