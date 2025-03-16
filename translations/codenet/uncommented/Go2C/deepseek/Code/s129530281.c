#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 500000

typedef struct {
    int n, h, i, chunk;
    int *unit;
    int **bucket;
} Segment;

void init(Segment *seg, int n) {
    seg->n = n;
    seg->unit = (int *)malloc(sizeof(int));
    seg->unit[0] = 1;
    seg->bucket = (int **)malloc(sizeof(int *));
    seg->bucket[0] = (int *)malloc(n * sizeof(int));

    int chunk = 8;
    for (int i = 0; n > 1; i++) {
        n = (n - 1) / chunk + 1;
        seg->bucket = (int **)realloc(seg->bucket, (i + 2) * sizeof(int *));
        seg->bucket[i + 1] = (int *)malloc(n * sizeof(int));
        seg->unit = (int *)realloc(seg->unit, (i + 2) * sizeof(int));
        seg->unit[i + 1] = seg->unit[i] * chunk;
    }
    seg->h = i + 1;
    seg->chunk = chunk;
}

void maximize(Segment *seg, int index, int value) {
    seg->bucket[0][index] = value;
    for (seg->i = 0; seg->i < seg->h - 1; seg->i++) {
        int s = index - index % seg->chunk;
        int t = s + seg->chunk;
        if (t > seg->bucket[seg->i][0]) {
            t = seg->bucket[seg->i][0];
        }
        int parent = index / seg->chunk;
        int max = 0;
        for (int i = s; i < t; i++) {
            if (max < seg->bucket[seg->i][i]) {
                max = seg->bucket[seg->i][i];
            }
        }
        seg->bucket[seg->i + 1][parent] = max;
        index /= seg->chunk;
    }
}

int top(Segment *seg) {
    int index = 0;
    for (seg->i = seg->h - 2; seg->i >= 0; seg->i--) {
        int s = index * seg->chunk;
        int t = s + seg->chunk;
        if (t > seg->bucket[seg->i][0]) {
            t = seg->bucket[seg->i][0];
        }
        for (int i = s; i < t; i++) {
            if (seg->bucket[seg->i][i] == seg->bucket[seg->i + 1][index]) {
                index = i;
                break;
            }
        }
    }
    return index;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    Segment seg;
    init(&seg, n);
    for (int i = 0; i < n; i++) {
        int value;
        scanf("%d", &value);
        maximize(&seg, i, value);
    }
    for (int i = 0; i < m; i++) {
        maximize(&seg, top(&seg), seg.bucket[seg.h - 1][0] >> 1);
    }

    int64_t ans = 0;
    for (int i = 0; i < n; i++) {
        ans += seg.bucket[0][i];
    }

    printf("%lld\n", ans);

    for (int i = 0; i < seg.h; i++) {
        free(seg.bucket[i]);
    }
    free(seg.bucket);
    free(seg.unit);

    return 0;
}
