#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define INF INT_MAX

typedef struct {
    int cost, id;
} State;

typedef struct {
    State *data;
    int size;
    int capacity;
} Heap;

void heap_init(Heap *h, int capacity) {
    h->data = (State *)malloc(capacity * sizeof(State));
    h->size = 0;
    h->capacity = capacity;
}

void heap_free(Heap *h) {
    free(h->data);
}

void heap_swap(State *a, State *b) {
    State temp = *a;
    *a = *b;
    *b = temp;
}

void heap_push(Heap *h, State value) {
    if (h->size == h->capacity) {
        h->capacity *= 2;
        h->data = (State *)realloc(h->data, h->capacity * sizeof(State));
    }
    h->data[h->size] = value;
    int current = h->size;
    while (current > 0 && h->data[current].cost < h->data[(current - 1) / 2].cost) {
        heap_swap(&h->data[current], &h->data[(current - 1) / 2]);
        current = (current - 1) / 2;
    }
    h->size++;
}

State heap_pop(Heap *h) {
    State root = h->data[0];
    h->size--;
    h->data[0] = h->data[h->size];
    int current = 0;
    while (2 * current + 1 < h->size) {
        int child = 2 * current + 1;
        if (child + 1 < h->size && h->data[child + 1].cost < h->data[child].cost) {
            child++;
        }
        if (h->data[current].cost <= h->data[child].cost) {
            break;
        }
        heap_swap(&h->data[current], &h->data[child]);
        current = child;
    }
    return root;
}

int main() {
    int H, W, K;
    scanf("%d %d %d", &H, &W, &K);
    int x1, y1, x2, y2;
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    y1--; y2--; // Convert to 0-based index
    x1--; x2--; // Convert to 0-based index
    char **c = (char **)malloc(H * sizeof(char *));
    for (int y = 0; y < H; y++) {
        c[y] = (char *)malloc(W + 1);
        scanf("%s", c[y]);
    }

    int dx[] = {1, 0, -1, 0};
    int dy[] = {0, 1, 0, -1};

    int toID(int x, int y, int dir) {
        return 4 * (W * y + x) + dir;
    }

    int splatID(int id) {
        return id / 4 % W, id / 4 / W, id % 4;
    }

    int dist[W * H * 4];
    for (int i = 0; i < W * H * 4; i++) {
        dist[i] = INF;
    }

    Heap q;
    heap_init(&q, 1000);
    for (int i = 0; i < 4; i++) {
        heap_push(&q, (State){0, toID(x1, y1, i)});
    }
    while (q.size > 0) {
        State now = heap_pop(&q);
        int x, y, dir;
        x = now.id / 4 % W;
        y = now.id / 4 / W;
        dir = now.id % 4;
        if (c[y][x] == '@') {
            continue;
        }
        if (dist[now.id] <= now.cost) {
            continue;
        }
        dist[now.id] = now.cost;
        if (x == x2 && y == y2) {
            break;
        }
        for (int i = 0; i < 4; i++) {
            int nCost = (now.cost + K - 1) / K * K;
            int nID = toID(x, y, i);
            if (dist[nID] <= nCost) {
                continue;
            }
            heap_push(&q, (State){nCost, nID});
        }
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (0 <= nx && nx < W && 0 <= ny && ny < H) {
            int nCost = now.cost + 1;
            int nID = toID(nx, ny, dir);
            if (dist[nID] <= nCost) {
                continue;
            }
            heap_push(&q, (State){nCost, nID});
        }
    }
    int ans = INF;
    for (int i = 0; i < 4; i++) {
        int id = toID(x2, y2, i);
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

    for (int y = 0; y < H; y++) {
        free(c[y]);
    }
    free(c);
    heap_free(&q);
    return 0;
}
