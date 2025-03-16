#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int l;
    int r;
} arm;

int scanInt() {
    int iv;
    scanf("%d", &iv);
    return iv;
}

int main() {
    int n = scanInt();
    arm *as = (arm *)malloc(sizeof(arm) * n);
    for (int i = 0; i < n; i++) {
        int x, l;
        x = scanInt();
        l = scanInt();
        as[i].l = x - l;
        as[i].r = x + l;
    }
    qsort(as, n, sizeof(arm), cmp);

    int ans = 1;
    int r = as[0].r;
    for (int i = 1; i < n; i++) {
        if (as[i].l >= r) {
            ans++;
            r = as[i].r;
        }
    }
    printf("%d\n", ans);
    return 0;
}

int cmp(const void *a, const void *b) {
    return ((arm *)a)->r - ((arm *)b)->r;
}

