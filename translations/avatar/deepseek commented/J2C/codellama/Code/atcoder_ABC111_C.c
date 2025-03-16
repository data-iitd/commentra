
#include <stdio.h>
#include <stdlib.h>

int main ( ) {
    int n, i, j, k, l, m, ans;
    int *v, *vo, *ve, *vt;
    scanf("%d", &n);
    v = (int *)malloc(n * sizeof(int));
    vo = (int *)malloc(n * sizeof(int));
    ve = (int *)malloc(n * sizeof(int));
    vt = (int *)malloc(n * sizeof(int));
    for (i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }
    for (i = 0; i < n; i++) {
        vt[v[i]]++;
        if (i % 2 == 0) {
            ve[v[i]]++;
        } else {
            vo[v[i]]++;
        }
    }
    for (i = 0; i < n; i++) {
        if (vo[i] + ve[i] == vt[i]) {
            ans = min(n - vo[i] - ve[i + 1], n - vo[i + 1] - ve[i]);
        } else {
            ans = n - vo[i] - ve[i];
        }
    }
    printf("%d", ans);
    free(v);
    free(vo);
    free(ve);
    free(vt);
    return 0;
}

