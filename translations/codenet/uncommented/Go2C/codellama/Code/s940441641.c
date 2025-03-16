#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include <limits.h>
#include <math.h>

#define MAX_H 1000
#define MAX_W 1000
#define MAX_K 1000
#define MAX_DIST (1LL << 60)

typedef struct {
    int cost;
    int id;
} State;

typedef struct {
    int len;
    int cap;
    State *data;
} Heap;

void heap_init(Heap *h) {
    h->len = 0;
    h->cap = 10000;
    h->data = (State *)malloc(sizeof(State) * h->cap);
}

void heap_push(Heap *h, State v) {
    if (h->len >= h->cap) {
        h->cap *= 2;
        h->data = (State *)realloc(h->data, sizeof(State) * h->cap);
    }
    h->data[h->len++] = v;
}

State heap_pop(Heap *h) {
    State v = h->data[0];
    h->data[0] = h->data[--h->len];
    return v;
}

void heap_sort(Heap *h) {
    for (int i = h->len / 2 - 1; i >= 0; i--) {
        for (int j = i * 2 + 1; j < h->len; j = j * 2 + 1) {
            if (j + 1 < h->len && h->data[j].cost > h->data[j + 1].cost) {
                j++;
            }
            if (h->data[i].cost <= h->data[j].cost) {
                break;
            }
            State tmp = h->data[i];
            h->data[i] = h->data[j];
            h->data[j] = tmp;
        }
    }
    for (int i = h->len - 1; i >= 0; i--) {
        for (int j = i * 2 + 1; j < h->len; j = j * 2 + 1) {
            if (j + 1 < h->len && h->data[j].cost > h->data[j + 1].cost) {
                j++;
            }
            if (h->data[i].cost >= h->data[j].cost) {
                break;
            }
            State tmp = h->data[i];
            h->data[i] = h->data[j];
            h->data[j] = tmp;
        }
    }
}

int to_id(int x, int y, int dir) {
    return 4 * (MAX_W * y + x) + dir;
}

int splat_id(int id) {
    return id / 4 % MAX_W, id / 4 / MAX_W, id % 4;
}

int main() {
    int H, W, K;
    scanf("%d %d %d", &H, &W, &K);
    int x1, y1, x2, y2;
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    x1--, y1--, x2--, y2--;
    x1, y1 = y1, x1;
    x2, y2 = y2, x2;
    char c[MAX_H][MAX_W];
    for (int y = 0; y < H; y++) {
        scanf("%s", c[y]);
    }

    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};

    int dist[MAX_W * MAX_H * 4];
    for (int i = 0; i < MAX_W * MAX_H * 4; i++) {
        dist[i] = MAX_DIST;
    }

    Heap q;
    heap_init(&q);
    for (int i = 0; i < 4; i++) {
        heap_push(&q, (State){
            .cost = 0,
            .id = to_id(x1, y1, i),
        });
    }
    while (q.len > 0) {
        State now = heap_pop(&q);
        int x, y, dir;
        x = splat_id(now.id)[0];
        y = splat_id(now.id)[1];
        dir = splat_id(now.id)[2];
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
            int nID = to_id(x, y, i);
            if (dist[nID] <= nCost) {
                continue;
            }
            heap_push(&q, (State){
                .cost = nCost,
                .id = nID,
            });
        }
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (0 <= nx && nx < W && 0 <= ny && ny < H) {
            int nCost = now.cost + 1;
            int nID = to_id(nx, ny, dir);
            if (dist[nID] <= nCost) {
                continue;
            }
            heap_push(&q, (State){
                .cost = nCost,
                .id = nID,
            });
        }
    }
    int ans = MAX_DIST;
    for (int i = 0; i < 4; i++) {
        int id = to_id(x2, y2, i);
        if (dist[id] < ans) {
            int d2 = (dist[id] + K - 1) / K;
            if (d2 < ans) {
                ans = d2;
            }
        }
    }
    if (ans < MAX_DIST) {
        printf("%d\n", ans);
    } else {
        printf("-1\n");
    }
    return 0;
}

