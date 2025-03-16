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
} Heap;

void heap_init(Heap *h, int capacity) {
    h->data = (State *)malloc(capacity * sizeof(State));
    h->size = 0;
}

void heap_push(Heap *h, State value) {
    int i = h->size++;
    while (i > 0) {
        int parent = (i - 1) / 2;
        if (h->data[parent].cost <= value.cost) break;
        h->data[i] = h->data[parent];
        i = parent;
    }
    h->data[i] = value;
}

State heap_pop(Heap *h) {
    State top = h->data[0];
    State value = h->data[--h->size];
    int i = 0;
    while (2 * i + 1 < h->size) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int smallest = left;
        if (right < h->size && h->data[right].cost < h->data[left].cost) {
            smallest = right;
        }
        if (h->data[smallest].cost >= value.cost) break;
        h->data[i] = h->data[smallest];
        i = smallest;
    }
    h->data[i] = value;
    return top;
}

void heap_free(Heap *h) {
    free(h->data);
}

int read_int() {
    int i;
    scanf("%d", &i);
    return i;
}

char* read_string() {
    char *s = (char *)malloc(100 * sizeof(char));
    scanf("%s", s);
    return s;
}

int main() {
    int H = read_int();
    int W = read_int();
    int K = read_int();
    int x1 = read_int() - 1;
    int y1 = read_int() - 1;
    int x2 = read_int() - 1;
    int y2 = read_int() - 1;
    y1 = x1;
    y2 = x2;

    char **c = (char **)malloc(H * sizeof(char *));
    for (int y = 0; y < H; y++) {
        c[y] = read_string();
    }

    int dx[] = {1, 0, -1, 0};
    int dy[] = {0, 1, 0, -1};

    int to_id(int x, int y, int dir) {
        return 4 * (W * y + x) + dir;
    }

    int splat_id(int id) {
        return id / 4 % W, id / 4 / W, id % 4;
    }

    int dist[W * H * 4];
    for (int i = 0; i < W * H * 4; i++) {
        dist[i] = INF;
    }

    Heap q;
    heap_init(&q, W * H * 4);

    for (int i = 0; i < 4; i++) {
        heap_push(&q, (State){0, to_id(x1, y1, i)});
    }

    while (q.size > 0) {
        State now = heap_pop(&q);
        int x, y, dir;
        x = now.id / 4 % W;
        y = now.id / 4 / W;
        dir = now.id % 4;

        if (c[y][x] == '@') continue;
        if (dist[now.id] <= now.cost) continue;
        dist[now.id] = now.cost;

        if (x == x2 && y == y2) break;

        for (int i = 0; i < 4; i++) {
            int n_cost = (now.cost + K - 1) / K * K;
            int n_id = to_id(x, y, i);
            if (dist[n_id] <= n_cost) continue;
            heap_push(&q, (State){n_cost, n_id});
        }

        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (0 <= nx && nx < W && 0 <= ny && ny < H) {
            int n_cost = now.cost + 1;
            int n_id = to_id(nx, ny, dir);
            if (dist[n_id] <= n_cost) continue;
            heap_push(&q, (State){n_cost, n_id});
        }
    }

    int ans = INF;
    for (int i = 0; i < 4; i++) {
        int id = to_id(x2, y2, i);
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
