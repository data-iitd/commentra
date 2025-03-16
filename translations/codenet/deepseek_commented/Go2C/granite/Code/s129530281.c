
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    seg->bucket[0] = (int *)malloc(sizeof(int) * n);

    int chunk = 8;
    for (seg->i = 0; n > 1; seg->i++) {
        n = (n - 1) / chunk + 1;
        seg->bucket = (int **)realloc(seg->bucket, sizeof(int *) * (seg->i + 1));
        seg->unit = (int *)realloc(seg->unit, sizeof(int) * (seg->i + 1));
        seg->bucket[seg->i] = (int *)malloc(sizeof(int) * n);
        seg->unit[seg->i] = seg->unit[seg->i - 1] * chunk;
    }
    seg->h = seg->i + 1;
    seg->chunk = chunk;
}

void maximize(Segment *seg, int index, int value) {
    seg->bucket[0][index] = value;
    for (seg->i = 0; seg->i < seg->h - 1; seg->i++) {
        int s = index - index % seg->chunk;
        int t = s + seg->chunk;
        if (t > seg->bucket[seg->i].length) {
            t = seg->bucket[seg->i].length;
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
        if (t > seg->bucket[seg->i].length) {
            t = seg->bucket[seg->i].length;
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
    FILE *fp = stdin;
    if (argc > 1) {
        fp = fopen(argv[1], "r");
    }
    fscanf(fp, "%d %d", &seg.n, &seg.m);

    init(&seg);

    for (int i = 0; i < seg.n; i++) {
        fscanf(fp, "%d", &seg.bucket[0][i]);
    }

    for (int i = 0; i < seg.m; i++) {
        maximize(&seg, top(&seg), seg.bucket[0][top(&seg)] / 2);
    }

    int ans = 0;
    for (int i = 0; i < seg.n; i++) {
        ans += seg.bucket[0][i];
    }

    printf("%d\n", ans);

    return 0;
}

