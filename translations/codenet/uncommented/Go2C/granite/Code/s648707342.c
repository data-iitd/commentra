
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int l, r;
} arm;

int cmpfunc (const void * a, const void * b) {
   return ((arm*)a)->r - ((arm*)b)->r;
}

int main() {
    int n, i, ans, r;
    scanf("%d", &n);
    arm *as = (arm*)malloc(n * sizeof(arm));
    for (i = 0; i < n; i++) {
        int x, l;
        scanf("%d %d", &x, &l);
        as[i].l = x - l;
        as[i].r = x + l;
    }
    qsort(as, n, sizeof(arm), cmpfunc);
    ans = 1;
    r = as[0].r;
    for (i = 1; i < n; i++) {
        if (as[i].l >= r) {
            ans++;
            r = as[i].r;
        }
    }
    printf("%d\n", ans);
    free(as);
    return 0;
}
