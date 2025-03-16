
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <limits.h>
#include <float.h>
#include <ctype.h>
#include <time.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
    int x[3];
    int max = 0;
    for (int i = 0; i < 3; ++i) {
        scanf("%d", &x[i]);
        max = max > x[i]? max : x[i];
    }
    int k;
    scanf("%d", &k);
    long a[3][x[0]];
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < x[i]; ++j) {
            scanf("%ld", &a[i][j]);
        }
        qsort(a[i], x[i], sizeof(long), cmpfunc);
    }
    long ans[k];
    for (int i = 0; i < x[0]; ++i) {
        for (int j = 0; j < x[1]; ++j) {
            for (int m = 0; m < x[2]; ++m) {
                if ((i + 1) * (j + 1) * (m + 1) <= k) {
                    long tmp = a[0][x[0] - i - 1] + a[1][x[1] - j - 1] + a[2][x[2] - m - 1];
                    ans[k - (i + 1) * (j + 1) * (m + 1)] = tmp;
                }
            }
        }
    }
    qsort(ans, k, sizeof(long), cmpfunc);
    for (int i = 0; i < k; ++i) {
        printf("%ld\n", ans[i]);
    }
    return 0;
}

