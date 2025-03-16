
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int a;
    int b;
} ab_t;

typedef struct {
    int *array;
    int size;
} array_t;

typedef struct {
    int a;
    int b;
    int color;
} q_t;

int genid(int a, int b) {
    if (b < a) {
        int tmp = a;
        a = b;
        b = tmp;
    }
    return a * 100000 + b;
}

int main() {
    int N = 0;
    scanf("%d", &N);

    ab_t *ab = (ab_t *)malloc(sizeof(ab_t) * (N - 1));
    array_t *edges = (array_t *)malloc(sizeof(array_t) * N);
    for (int i = 0; i < N; i++) {
        edges[i].array = (int *)malloc(sizeof(int) * N);
        edges[i].size = 0;
    }
    for (int i = 0; i < N - 1; i++) {
        scanf("%d %d", &ab[i].a, &ab[i].b);
        ab[i].a--;
        ab[i].b--;
        edges[ab[i].a].array[edges[ab[i].a].size] = ab[i].b;
        edges[ab[i].a].size++;
        edges[ab[i].b].array[edges[ab[i].b].size] = ab[i].a;
        edges[ab[i].b].size++;
    }

    int *colors = (int *)malloc(sizeof(int) * (N * (N - 1) / 2));
    q_t *q = (q_t *)malloc(sizeof(q_t) * N);
    int head = 0, tail = 0;
    q[tail].a = 0;
    q[tail].b = -1;
    q[tail].color = -1;
    tail++;
    while (head < tail) {
        q_t current = q[head];
        head++;
        int color = 1;
        for (int i = 0; i < edges[current.a].size; i++) {
            int child = edges[current.a].array[i];
            if (child == current.b) {
                continue;
            }
            if (color == current.color) {
                color++;
            }
            colors[genid(current.a, child)] = color;
            q[tail].a = child;
            q[tail].b = current.a;
            q[tail].color = color;
            tail++;
            color++;
        }
    }

    int K = 0;
    for (int i = 0; i < N; i++) {
        if (edges[i].size > K) {
            K = edges[i].size;
        }
    }
    printf("%d\n", K);

    for (int i = 0; i < N - 1; i++) {
        printf("%d\n", colors[genid(ab[i].a, ab[i].b)]);
    }

    for (int i = 0; i < N; i++) {
        free(edges[i].array);
    }
    free(edges);
    free(ab);
    free(colors);
    free(q);

    return 0;
}
