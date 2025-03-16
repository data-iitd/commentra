#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x, l, r;
} Point;

int compare(const void *a, const void *b) {
    Point *p1 = (Point *)a;
    Point *p2 = (Point *)b;
    return p1->r - p2->r;
}

int nextInt(FILE *fp) {
    int t;
    fscanf(fp, "%d", &t);
    return t;
}

int main() {
    FILE *fp = fopen("input.txt", "r");
    if (!fp) {
        perror("Failed to open input file");
        return EXIT_FAILURE;
    }

    int N = nextInt(fp);
    Point points[N];
    for (int i = 0; i < N; i++) {
        points[i].x = nextInt(fp);
        int L = nextInt(fp);
        points[i].l = points[i].x - L;
        points[i].r = points[i].x + L;
    }

    qsort(points, N, sizeof(Point), compare);

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
    fclose(fp);
    return EXIT_SUCCESS;
}
