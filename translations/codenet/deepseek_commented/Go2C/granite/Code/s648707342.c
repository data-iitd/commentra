
#include <stdio.h>
#include <stdlib.h>

typedef struct arm {
    int l, r;
} arm;

int cmpfunc(const void * a, const void * b) {
    return ((arm*)a)->r - ((arm*)b)->r;
}

int main() {
    int n = 0;
    scanf("%d", &n);

    arm *as = (arm*)malloc(n * sizeof(arm));
    for (int i = 0; i < n; i++) {
        int x, l;
        scanf("%d %d", &x, &l);
        as[i].l = x - l;
        as[i].r = x + l;
    }

    qsort(as, n, sizeof(arm), cmpfunc);

    int ans = 1;
    int r = as[0].r;
    for (int i = 1; i < n; i++) {
        if (as[i].l >= r) {
            ans++;
            r = as[i].r;
        }
    }

    printf("%d\n", ans);

    free(as);
    return 0;
}
