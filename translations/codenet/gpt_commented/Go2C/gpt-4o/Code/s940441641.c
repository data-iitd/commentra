#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define INF (1LL << 60) // Define a constant for infinity
#define MAX_H 100
#define MAX_W 100
#define MAX_DIR 4

typedef struct {
    long long cost;
    int id;
} State;

typedef struct {
    State *data;
    int size;
    int capacity;
} MinHeap;

void initHeap(MinHeap *heap, int capacity) {
    heap->data = (State *)malloc(capacity * sizeof(State));
    heap->size = 0;
    heap->capacity = capacity;
}

void freeHeap(MinHeap *heap) {
    free(heap->data);
}

void swap(State *a, State *b) {
    State temp = *a;
    *a = *b;
    *b = temp;
}

void push(MinHeap *heap, State state) {
    if (heap->size == heap->capacity) {
        heap->capacity *= 2;
        heap->data = (State *)realloc(heap->data, heap->capacity * sizeof(State));
    }
    heap->data[heap->size++] = state;

    // Bubble up
    int index = heap->size - 1;
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (heap->data[index].cost < heap->data[parent].cost) {
            swap(&heap->data[index], &heap->data[parent]);
            index = parent;
        } else {
            break;
        }
    }
}

State pop(MinHeap *heap) {
    State result = heap->data[0];
    heap->data[0] = heap->data[--heap->size];

    // Bubble down
    int index = 0;
    while (index * 2 + 1 < heap->size) {
        int child = index * 2 + 1;
        if (child + 1 < heap->size && heap->data[child + 1].cost < heap->data[child].cost) {
            child++;
        }
        if (heap->data[index].cost > heap->data[child].cost) {
            swap(&heap->data[index], &heap->data[child]);
            index = child;
        } else {
            break;
        }
    }
    return result;
}

int toID(int x, int y, int dir, int W) {
    return 4 * (W * y + x) + dir;
}

void splatID(int id, int *x, int *y, int *dir, int W) {
    *x = id / 4 % W;
    *y = id / 4 / W;
    *dir = id % 4;
}

int main() {
    int H, W, K;
    scanf("%d %d %d", &H, &W, &K);
    int x1, y1, x2, y2;
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    x1--; y1--; x2--; y2--; // Adjust for 0-based indexing
    int temp = x1; x1 = y1; y1 = temp; // Swap x and y for the starting point
    temp = x2; x2 = y2; y2 = temp; // Swap x and y for the ending point

    char grid[MAX_H][MAX_W + 1];
    for (int y = 0; y < H; y++) {
        scanf("%s", grid[y]);
    }

    int dx[MAX_DIR] = {1, 0, -1, 0};
    int dy[MAX_DIR] = {0, 1, 0, -1};

    long long dist[MAX_H * MAX_W * MAX_DIR];
    for (int i = 0; i < MAX_H * MAX_W * MAX_DIR; i++) {
        dist[i] = INF;
    }

    MinHeap heap;
    initHeap(&heap, 16);
    for (int i = 0; i < MAX_DIR; i++) {
        push(&heap, (State){0, toID(x1, y1, i, W)});
    }

    while (heap.size > 0) {
        State now = pop(&heap);
        int x, y, dir;
        splatID(now.id, &x, &y, &dir, W);

        if (grid[y][x] == '@') continue;
        if (dist[now.id] <= now.cost) continue;
        dist[now.id] = now.cost;

        if (x == x2 && y == y2) break;

        for (int i = 0; i < MAX_DIR; i++) {
            long long nCost = (now.cost + K - 1) / K * K;
            int nID = toID(x, y, i, W);
            if (dist[nID] <= nCost) continue;
            push(&heap, (State){nCost, nID});
        }

        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (0 <= nx && nx < W && 0 <= ny && ny < H) {
            long long nCost = now.cost + 1;
            int nID = toID(nx, ny, dir, W);
            if (dist[nID] <= nCost) continue;
            push(&heap, (State){nCost, nID});
        }
    }

    long long ans = INF;
    for (int i = 0; i < MAX_DIR; i++) {
        int id = toID(x2, y2, i, W);
        if (dist[id] < ans) {
            long long d2 = (dist[id] + K - 1) / K;
            if (d2 < ans) {
                ans = d2;
            }
        }
    }

    if (ans < INF) {
        printf("%lld\n", ans);
    } else {
        printf("-1\n");
    }

    freeHeap(&heap);
    return 0;
}

// <END-OF-CODE>
