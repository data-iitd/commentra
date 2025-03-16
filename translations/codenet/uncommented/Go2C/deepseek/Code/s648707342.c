#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int l, r;
} Arm;

int compare(const void *a, const void *b) {
    Arm *armA = (Arm *)a;
    Arm *armB = (Arm *)b;
    return armA->r - armB->r;
}

int main() {
    int n;
    scanf("%d", &n);
    Arm arms[n];
    for (int i = 0; i < n; i++) {
        int x, l;
        scanf("%d %d", &x, &l);
        arms[i].l = x - l;
        arms[i].r = x + l;
    }

    qsort(arms, n, sizeof(Arm), compare);

    int ans = 1;
    int r = arms[0].r;
    for (int i = 1; i < n; i++) {
        if (arms[i].l >= r) {
            ans++;
            r = arms[i].r;
        }
    }

    printf("%d\n", ans);
    return 0;
}
