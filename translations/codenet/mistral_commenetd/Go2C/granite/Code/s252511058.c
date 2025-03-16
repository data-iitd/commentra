
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x, l, r;
} point;

typedef struct {
    int size, capacity;
    point* array;
} ps;

ps* create_ps() {
    ps* p = (ps*)malloc(sizeof(ps));
    p->size = 0;
    p->capacity = 10;
    p->array = (point*)malloc(p->capacity * sizeof(point));
    return p;
}

void add(ps* p, point x) {
    if (p->size == p->capacity) {
        p->capacity *= 2;
        p->array = (point*)realloc(p->array, p->capacity * sizeof(point));
    }
    p->array[p->size++] = x;
}

void sort_ps(ps* p) {
    qsort(p->array, p->size, sizeof(point), compare);
}

int compare(const void* a, const void* b) {
    point* p1 = (point*)a;
    point* p2 = (point*)b;
    return p1->r - p2->r;
}

int main() {
    int N;
    scanf("%d", &N);
    ps* points = create_ps();
    for (int i = 0; i < N; i++) {
        int x, L;
        scanf("%d %d", &x, &L);
        point p = {x, x - L, x + L};
        add(points, p);
    }
    sort_ps(points);
    int start = points->array[0].r;
    int ans = 1;
    for (int i = 1; i < points->size; i++) {
        if (points->array[i].l < start) {
            continue;
        }
        start = points->array[i].r;
        ans++;
    }
    printf("%d\n", ans);
    return 0;
}

