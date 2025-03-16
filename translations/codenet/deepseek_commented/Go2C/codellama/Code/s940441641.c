
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>

#define MAX_H 1000
#define MAX_W 1000
#define MAX_K 1000
#define MAX_DIST (MAX_H * MAX_W * 4)

typedef struct {
    int cost;
    int id;
} State;

typedef State HeapElement;
typedef HeapElement* Heap;

void swap(HeapElement* a, HeapElement* b) {
    HeapElement tmp = *a;
    *a = *b;
    *b = tmp;
}

void heapify(Heap h, int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && h[l].cost < h[largest].cost) {
        largest = l;
    }
    if (r < n && h[r].cost < h[largest].cost) {
        largest = r;
    }
    if (largest != i) {
        swap(&h[i], &h[largest]);
        heapify(h, n, largest);
    }
}

void heap_sort(Heap h, int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(h, n, i);
    }
    for (int i = n - 1; i >= 0; i--) {
        swap(&h[0], &h[i]);
        heapify(h, i, 0);
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
    x1--;
    y1--;
    x2--;
    y2--;
    char c[MAX_H][MAX_W];
    for (int y = 0; y < H; y++) {
        scanf("%s", c[y]);
    }

    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};

    int dist[MAX_DIST];
    for (int i = 0; i < MAX_DIST; i++) {
        dist[i] = INT_MAX;
    }

    Heap q = malloc(sizeof(HeapElement) * MAX_DIST);
    for (int i = 0; i < 4; i++) {
        q[i] = (State){
            .cost = 0,
            .id = to_id(x1, y1, i),
        };
    }
    for (int i = 0; i < MAX_DIST; i++) {
        if (q[i].cost == INT_MAX) {
            continue;
        }
        int x, y, dir;
        x = splat_id(q[i].id) / 4 % MAX_W;
        y = splat_id(q[i].id) / 4 / MAX_W;
        dir = splat_id(q[i].id) % 4;
        if (c[y][x] == '@') {
            continue;
        }
        if (dist[q[i].id] <= q[i].cost) {
            continue;
        }
        dist[q[i].id] = q[i].cost;
        if (x == x2 && y == y2) {
            break;
        }
        for (int i = 0; i < 4; i++) {
            int nCost = (q[i].cost + K - 1) / K * K;
            int nID = to_id(x, y, i);
            if (dist[nID] <= nCost) {
                continue;
            }
            q[i] = (State){
                .cost = nCost,
                .id = nID,
            };
        }
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (0 <= nx && nx < W && 0 <= ny && ny < H) {
            int nCost = q[i].cost + 1;
            int nID = to_id(nx, ny, dir);
            if (dist[nID] <= nCost) {
                continue;
            }
            q[i] = (State){
                .cost = nCost,
                .id = nID,
            };
        }
    }
    int ans = INT_MAX;
    for (int i = 0; i < 4; i++) {
        int id = to_id(x2, y2, i);
        if (dist[id] < ans) {
            int d2 = (dist[id] + K - 1) / K;
            if (d2 < ans) {
                ans = d2;
            }
        }
    }
    if (ans < INT_MAX) {
        printf("%d\n", ans);
    } else {
        printf("-1\n");
    }
    return 0;
}

