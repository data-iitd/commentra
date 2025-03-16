#include <stdio.h>
#include <stdlib.h>
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

int H, W, K, x1, y1, x2, y2;
int dist[1000 * 1000 * 4];
Heap q;

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

void initDist() {
    for (int i = 0; i < W * H * 4; i++) {
        dist[i] = INF;
    }
    for (int i = 0; i < 4; i++) {
        heap_push(&q, (State){0, toID(x1, y1, i)});
    }
}

int toID(int x, int y, int dir) {
    return 4 * (W * y + x) + dir;
}

void splatID(int id, int *x, int *y, int *dir) {
    *x = id % W;
    *y = id / W;
    *dir = id % 4;
}

void processHeap() {
    while (q.size > 0) {
        State now = heap_pop(&q);
        int x, y, dir;
        splatID(now.id, &x, &y, &dir);

        if (x == x2 && y == y2) break;

        if (dist[now.id] <= now.cost) continue;

        dist[now.id] = now.cost;
        for (int i = 0; i < 4; i++) {
            int nCost = now.cost + K;
            int nID = toID(x, y, i);
            if (dist[nID] <= nCost) continue;
            heap_push(&q, (State){nCost, nID});
        }

        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (0 <= nx && nx < W && 0 <= ny && ny < H) {
            int nCost = now.cost + 1;
            int nID = toID(nx, ny, dir);
            if (dist[nID] <= nCost) continue;
            heap_push(&q, (State){nCost, nID});
        }
    }
}

int calculateAnswer() {
    int ans = INF;
    for (int i = 0; i < 4; i++) {
        int id = toID(x2, y2, i);
        if (dist[id] < ans) {
            ans = dist[id];
        }
    }
    return ans;
}

void printResult(int ans) {
    if (ans < INF) {
        printf("%d\n", ans);
    } else {
        printf("-1\n");
    }
}

int main() {
    scanf("%d %d %d", &H, &W, &K);
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    x1--; y1--; x2--; y2--;

    char grid[H][W];
    for (int y = 0; y < H; y++) {
        scanf("%s", grid[y]);
    }

    heap_init(&q, W * H * 4);
    initDist();
    processHeap();
    int ans = calculateAnswer();
    printResult(ans);

    free(q.data);
    return 0;
}

