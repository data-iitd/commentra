#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x, l, r;
} Point;

int compare(const void *a, const void *b) {
    Point *pointA = (Point *)a;
    Point *pointB = (Point *)b;
    return pointA->r - pointB->r;
}

int main() {
    int N;
    scanf("%d", &N);
    Point *points = (Point *)malloc(N * sizeof(Point));
    
    for (int i = 0; i < N; i++) {
        scanf("%d", &points[i].x);
        int L;
        scanf("%d", &L);
        points[i].l = points[i].x - L;
        points[i].r = points[i].x + L;
    }
    
    qsort(points, N, sizeof(Point), compare);
    
    // Interval scheduling problem
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

// <END-OF-CODE>
