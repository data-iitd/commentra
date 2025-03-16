
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define Inf 1000000000

typedef struct {
    int cost;
    int id;
} State;

typedef struct {
    State *data;
    int size;
    int capacity;
} Heap;

void swap(State *a, State *b) {
    State temp = *a;
    *a = *b;
    *b = temp;
}

int less(State a, State b) {
    return a.cost < b.cost;
}

void heapify(Heap *h, int i) {
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int smallest = i;
    if (l < h->size && less(h->data[l], h->data[i])) {
        smallest = l;
    }
    if (r < h->size && less(h->data[r], h->data[smallest])) {
        smallest = r;
    }
    if (smallest!= i) {
        swap(&h->data[i], &h->data[smallest]);
        heapify(h, smallest);
    }
}

void heap_push(Heap *h, State v) {
    if (h->size == h->capacity) {
        h->capacity *= 2;
        h->data = (State*)realloc(h->data, h->capacity * sizeof(State));
    }
    h->data[h->size++] = v;
    int i = h->size - 1;
    while (i > 0 && less(h->data[i], h->data[(i - 1) / 2])) {
        swap(&h->data[i], &h->data[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

State heap_pop(Heap *h) {
    if (h->size == 0) {
        exit(1);
    }
    State v = h->data[0];
    h->data[0] = h->data[--h->size];
    heapify(h, 0);
    return v;
}

int main() {
    int H, W, K;
    scanf("%d %d %d", &H, &W, &K);
    int x1, y1, x2, y2;
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    x1--, y1--; // Swap x and y for the starting point
    x2--, y2--; // Swap x and y for the ending point
    char c[H][W];
    for (int i = 0; i < H; i++) {
        scanf("%s", c[i]);
    }
    int dx[] = {1, 0, -1, 0};
    int dy[] = {0, 1, 0, -1};
    int toID(int x, int y, int dir) {
        return 4 * (W * y + x) + dir;
    }
    void splatID(int id, int *x, int *y, int *dir) {
        *x = id / 4 % W;
        *y = id / 4 / W;
        *dir = id % 4;
    }
    int dist[H][W][4];
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            for (int k = 0; k < 4; k++) {
                dist[i][j][k] = Inf;
            }
        }
    }
    Heap h;
    h.data = (State*)malloc(sizeof(State) * H * W * 4);
    h.size = 0;
    h.capacity = H * W * 4;
    for (int i = 0; i < 4; i++) {
        heap_push(&h, (State){0, toID(x1, y1, i)});
    }
    while (h.size > 0) {
        State now = heap_pop(&h);
        int x, y, dir;
        splatID(now.id, &x, &y, &dir);
        if (c[y][x] == '@') {
            continue;
        }
        if (dist[y][x][dir] <= now.cost) {
            continue;
        }
        dist[y][x][dir] = now.cost;
        if (x == x2 && y == y2) {
            break;
        }
        for (int i = 0; i < 4; i++) {
            int nCost = (now.cost + K - 1) / K * K;
            int nID = toID(x, y, i);
            if (dist[y][x][i] <= nCost) {
                continue;
            }
            heap_push(&h, (State){nCost, nID});
        }
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (0 <= nx && nx < W && 0 <= ny && ny < H) {
            int nCost = now.cost + 1;
            int nID = toID(nx, ny, dir);
            if (dist[ny][nx][dir] <= nCost) {
                continue;
            }
            heap_push(&h, (State){nCost, nID});
        }
    }
    int ans = Inf;
    for (int i = 0; i < 4; i++) {
        int id = toID(x2, y2, i);
        if (dist[y2][x2][i] < ans) {
            int d2 = (dist[y2][x2][i] + K - 1) / K;
            if (d2 < ans) {
                ans = d2;
            }
        }
    }
    if (ans < Inf) {
        printf("%d\n", ans);
    } else {
        printf("-1\n");
    }
    return 0;
}

