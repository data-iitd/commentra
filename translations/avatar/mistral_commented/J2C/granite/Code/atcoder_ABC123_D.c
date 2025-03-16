

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <limits.h>
#include <stdbool.h>

int main() {
    int x[3];
    int max = 0;
    for (int i = 0; i < 3; i++) {
        scanf("%d", &x[i]);
        max = fmax(max, x[i]);
    }
    int k;
    scanf("%d", &k);
    long a[3][max];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < x[i]; j++) {
            scanf("%ld", &a[i][j]);
        }
    }
    long ans[k];
    int count = 0;
    for (int i = 0; i < x[0]; i++) {
        for (int j = 0; j < x[1]; j++) {
            for (int m = 0; m < x[2]; m++) {
                if ((i + 1) * (j + 1) * (m + 1) <= k) {
                    ans[count] = a[0][x[0] - i - 1] + a[1][x[1] - j - 1] + a[2][x[2] - m - 1];
                    count++;
                }
            }
        }
    }
    qsort(ans, count, sizeof(long), cmpfunc);
    for (int i = 0; i < k; i++) {
        printf("%ld\n", ans[i]);
    }
    return 0;
}

