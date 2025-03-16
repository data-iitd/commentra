#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INF (1LL << 60)

typedef struct {
    int cost, id;
} State;

typedef struct {
    State *data;
    int size;
    int capacity;
} Heap;

Heap* createHeap(int capacity) {
    Heap *heap = (Heap *)malloc(sizeof(Heap));
    heap->data = (State *)malloc(capacity * sizeof(State));
    heap->size = 0;
    heap->capacity = capacity;
    return heap;
}

void swap(State *a, State *b) {
    State temp = *a;
    *a = *b;
    *b = temp;
}

void push(Heap *heap, State state) {
    if (heap->size == heap->capacity) {
        heap->capacity *= 2;
        heap->data = (State *)realloc(heap->data, heap->capacity * sizeof(State));
    }
    heap->data[heap->size++] = state;
    int i = heap->size - 1;
    while (i > 0 && heap->data[i].cost < heap->data[(i - 1) / 2].cost) {
        swap(&heap->data[i], &heap->data[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

State pop(Heap *heap) {
    State result = heap->data[0];
    heap->data[0] = heap->data[--heap->size];
    int i = 0;
    while (1) {
        int smallest = i;
        if (2 * i + 1 < heap->size && heap->data[2 * i + 1].cost < heap->data[smallest].cost) {
            smallest = 2 * i + 1;
        }
        if (2 * i + 2 < heap->size && heap->data[2 * i + 2].cost < heap->data[smallest].cost) {
            smallest = 2 * i + 2;
        }
        if (smallest == i) break;
        swap(&heap->data[i], &heap->data[smallest]);
        i = smallest;
    }
    return result;
}

int toID(int x, int y, int dir, int W) {
    return 4 * (W * y + x) + dir;
}

void splatID(int id, int *x, int *y, int *dir, int W) {
    *x = id % W;
    *y = id / W;
    *dir = id % 4;
}

int main() {
    int H, W, K, x1, y1, x2, y2;
    scanf("%d %d %d", &H, &W, &K);
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    x1--; y1--; x2--; y2--; // Convert to 0-based indexing

    char grid[H][W + 1];
    for (int i = 0; i < H; i++) {
        scanf("%s", grid[i]);
    }

    int *dist = (int *)malloc(W * H * 4 * sizeof(int));
    for (int i = 0; i < W * H * 4; i++) {
        dist[i] = INF;
    }

    Heap *q = createHeap(100);
    for (int i = 0; i < 4; i++) {
        push(q, (State){0, toID(x1, y1, i, W)});
    }

    const int dx[4] = {1, 0, -1, 0};
    const int dy[4] = {0, 1, 0, -1};

    while (q->size > 0) {
        State now = pop(q);
        int x, y, dir;
        splatID(now.id, &x, &y, &dir, W);

        if (x == x2 && y == y2) {
            break;
        }

        if (dist[now.id] <= now.cost) {
            continue;
        }

        dist[now.id] = now.cost;

        for (int i = 0; i < 4; i++) {
            int nCost = now.cost + K;
            int nID = toID(x, y, i, W);
            if (dist[nID] <= nCost) {
                continue;
            }
            push(q, (State){nCost, nID});
        }

        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (0 <= nx && nx < W && 0 <= ny && ny < H) {
            int nCost = now.cost + 1;
            int nID = toID(nx, ny, dir, W);
            if (dist[nID] <= nCost) {
                continue;
            }
            push(q, (State){nCost, nID});
        }
    }

    int ans = INF;
    for (int i = 0; i < 4; i++) {
        int id = toID(x2, y2, i, W);
        if (dist[id] < ans) {
            ans = dist[id];
        }
    }

    if (ans < INF) {
        printf("%d\n", ans);
    } else {
        printf("-1\n");
    }

    free(dist);
    free(q->data);
    free(q);
    return 0;
}

// <END-OF-CODE>
