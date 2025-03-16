#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int x, l, r;
} point;

int cmp(const void *a, const void *b) {
    point *p1 = (point *)a;
    point *p2 = (point *)b;
    return p1->r - p2->r;
}

int main() {
    int N;
    scanf("%d", &N);
    point *points = (point *)malloc(sizeof(point) * N);
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &points[i].x, &points[i].l);
        points[i].r = points[i].x + points[i].l;
    }
    qsort(points, N, sizeof(point), cmp);
    int start = points[0].r;
    int ans = 1;
    for (int i = 0; i < N; i++) {
        if (points[i].l < start) {
            continue;
        }
        start = points[i].r;
        ans++;
    }
    printf("%d\n", ans);
    return 0;
}
