#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INF (1LL << 60)

typedef struct {
    int cost;
    int id;
} State;

typedef struct {
    State *data;
    int size;
    int capacity;
} Heap;

void initHeap(Heap *h, int capacity) {
    h->data = (State *)malloc(capacity * sizeof(State));
    h->size = 0;
    h->capacity = capacity;
}

void freeHeap(Heap *h) {
    free(h->data);
}

void push(Heap *h, State state) {
    if (h->size == h->capacity) {
        h->capacity *= 2;
        h->data = (State *)realloc(h->data, h->capacity * sizeof(State));
    }
    h->data[h->size++] = state;
    int i = h->size - 1;
    while (i > 0) {
        int parent = (i - 1) / 2;
        if (h->data[parent].cost <= h->data[i].cost) break;
        State temp = h->data[parent];
        h->data[parent] = h->data[i];
        h->data[i] = temp;
        i = parent;
    }
}

State pop(Heap *h) {
    State result = h->data[0];
    h->data[0] = h->data[--h->size];
    int i = 0;
    while (1) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int smallest = i;
        if (left < h->size && h->data[left].cost < h->data[smallest].cost) smallest = left;
        if (right < h->size && h->data[right].cost < h->data[smallest].cost) smallest = right;
        if (smallest == i) break;
        State temp = h->data[i];
        h->data[i] = h->data[smallest];
        h->data[smallest] = temp;
        i = smallest;
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
    x1--; y1--; x2--; y2--;
    char c[H][W + 1];
    for (int y = 0; y < H; y++) {
        scanf("%s", c[y]);
    }

    int dx[] = {1, 0, -1, 0};
    int dy[] = {0, 1, 0, -1};

    int dist[W * H * 4];
    for (int i = 0; i < W * H * 4; i++) {
        dist[i] = INF;
    }

    Heap q;
    initHeap(&q, 16);
    for (int i = 0; i < 4; i++) {
        push(&q, (State){0, toID(x1, y1, i, W)});
    }

    while (q.size > 0) {
        State now = pop(&q);
        int x, y, dir;
        splatID(now.id, &x, &y, &dir, W);
        if (c[y][x] == '@') continue;
        if (dist[now.id] <= now.cost) continue;
        dist[now.id] = now.cost;
        if (x == x2 && y == y2) break;

        for (int i = 0; i < 4; i++) {
            int nCost = (now.cost + K - 1) / K * K;
            int nID = toID(x, y, i, W);
            if (dist[nID] <= nCost) continue;
            push(&q, (State){nCost, nID});
        }

        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (0 <= nx && nx < W && 0 <= ny && ny < H) {
            int nCost = now.cost + 1;
            int nID = toID(nx, ny, dir, W);
            if (dist[nID] <= nCost) continue;
            push(&q, (State){nCost, nID});
        }
    }

    int ans = INF;
    for (int i = 0; i < 4; i++) {
        int id = toID(x2, y2, i, W);
        if (dist[id] < ans) {
            int d2 = (dist[id] + K - 1) / K;
            if (d2 < ans) {
                ans = d2;
            }
        }
    }

    if (ans < INF) {
        printf("%d\n", ans);
    } else {
        printf("-1\n");
    }

    freeHeap(&q);
    return 0;
}

// <END-OF-CODE>
