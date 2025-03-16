
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x, l, r;
} point;

int cmpfunc(const void * a, const void * b) {
    return ((point*)a)->r - ((point*)b)->r;
}

int main() {
    int N;
    scanf("%d", &N);
    point *points = (point*)malloc(N * sizeof(point));
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &points[i].x, &points[i].l);
        points[i].r = points[i].x + points[i].l;
    }
    qsort(points, N, sizeof(point), cmpfunc);
    int start = points[0].r;
    int ans = 1;
    for (int i = 1; i < N; i++) {
        if (points[i].l < start) {
            continue;
        }
        start = points[i].r;
        ans++;
    }
    printf("%d\n", ans);
    free(points);
    return 0;
}
